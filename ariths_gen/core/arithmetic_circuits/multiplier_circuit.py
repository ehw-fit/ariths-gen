from .arithmetic_circuit import (
    ArithmeticCircuit
)

from ariths_gen.one_bit_circuits.logic_gates import (
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate
)

from ariths_gen.wire_components import (
    Wire,
    ConstantWireValue0,
    ConstantWireValue1,
    Bus
)

import math


class MultiplierCircuit(ArithmeticCircuit):
    """Class represents a general multiplier circuit derived from `ArithmeticCircuit` class.

    The __init__ method calls parent class __init__ method which fills some mandatory attributes concerning arithmetic circuit
    that are later used for generation into various representations.
    """

    def __init__(self, a, b, prefix: str, name: str, out_N: int, **kwargs):
        super().__init__(a=a, b=b, prefix=prefix, name=name, out_N=out_N, **kwargs)

    # Array multipliers
    def get_previous_partial_product(self, a_index: int, b_index: int):
        """Used in array multipliers to get previous row's component output wires for further connection to another component's input.

        Args:
            a_index (int): First input wire index.
            b_index (int): Second input wire index.

        Returns:
            Wire: Previous row's component wire of corresponding pp.
        """
        # To get the index of previous row's connecting adder and its generated pp
        index = ((b_index-2) * (self.N*2)) + ((self.N-1)+2*(a_index+2))

        # Get carry wire as input for the last adder in current row
        if a_index == self.N-1:
            index = index-2
            return self.components[index].get_carry_wire()
        # Get sum wire as input for current adder
        else:
            return self.components[index].get_sum_wire()

    # Dadda/Wallace multipliers
    @staticmethod
    def get_maximum_height(initial_value: int):
        """Used in dadda multipliers to get multiplier's maximum height.

        Maximum height sequence as defined here: https://en.wikipedia.org/wiki/Dadda_multiplier
        d(j=1) = 2; d(j+1) = floor(1.5*d)

        `j` stands for initial stage value
        `d` stands for maximum height for current initial stage value

        Args:
            initial_value (int): Initial algorithms stage value.

        Returns:
            int, int: Current algorithms stage and maximum bits (height) allowed in a column for current stage.
        """
        stage = 0
        d = 2
        while True:
            stage += 1
            max_height = d
            # Calculating maximum height sequence
            # d(j=1) = 2; d(j+1) = floor(1.5*d)
            d = math.floor(1.5*d)
            if d >= initial_value:
                return stage, max_height

    def init_column_heights(self, signed: bool = False):
        """Creates appropriate number of partial product columns along with filling them with corresponding number of bit pairs.

        Args:
            signed (bool, optional): Specify whether pp columns bit pairs should perform signed multiplication or not. Defaults to False.

        Returns:
            list: List of partial product columns with their bit pairs.
        """
        columns = [[num] if num <= self.N else [num - (num - self.N)*2] for num in range(1, self.out.N)]
        columns = [self.add_column_wires(column=col, column_index=columns.index(col), signed=signed) for col in columns]
        return columns

    def add_column_wires(self, column: list, column_index: int, signed: bool):
        """Fills circuit's partial product column with corresponding bit pairs.

        Args:
            column (list): List representing column of partial product bits.
            column_index (int): Index of partial products column.
            signed (bool): Specify whether pp columns bit pairs should perform signed multiplication or not.

        Returns:
            list: Updated column list containing corresponding number of input bit pairs to form proper pp column.
        """
        # Adding neccessary number of lists (based on number of bits in the column – stored in `column[0]`)
        # to column that each represent individual bit pairs for described column (these bit pairs are then combined in AND/NAND gates)
        [column.append([]) for _ in range(column[0])]
        # Filling column bit pair lists with appropriate bits
        if column_index <= self.N-1:
            [column[column[0]-index].append(self.a.get_wire(index)) for index in range(0, column[0])]
            [column[index+1].append(self.b.get_wire(index)) for index in range(0, column[0])]
        else:
            [column[self.a.N-index].append(self.a.get_wire(index)) for index in range(self.a.N-1, self.a.N-column[0]-1, -1)]
            [column[index-(self.a.N-1-column[0])].append(self.b.get_wire(index)) for index in range(self.a.N-column[0], self.a.N)]

        # Converting unsigned column pp bit pair lists into AND gates
        if signed is False:
            column[1:] = [AndGate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index), parent_component=self) for i in range(1, len(column))]
        # Converting signed column pp bit pair lists into AND/NAND gates (based on Baugh-Wooley multiplication algorithm)
        else:
            # First half of partial product columns contains only AND gates
            if column_index < self.N-1 or column_index == self.out.N-2:
                column[1:] = [AndGate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index), parent_component=self) for i in range(1, len(column))]
            # Second half of partial product columns contains NAND/AND gates
            else:
                column[1] = NandGate(a=column[1][0], b=column[1][1], prefix=self.prefix+'_nand_'+str(column[1][0].index)+'_'+str(column[1][1].index), parent_component=self)
                column[-1] = NandGate(a=column[-1][0], b=column[-1][1], prefix=self.prefix+'_nand_'+str(column[-1][0].index)+'_'+str(column[-1][1].index), parent_component=self)
                if len(column[2:-1]) != 0:
                    column[2:-1] = [AndGate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index), parent_component=self) for i in range(2, len(column)-1)]

        return column

    def get_column_height(self, column_num: int):
        """Retrieves the current height of desired partial products column.

        Args:
            column_num (int): Index of pp column.

        Returns:
            int: Height of the current bit column.
        """
        return self.columns[column_num][0]

    def update_column_heights(self, curr_column: int, curr_height_change: int, next_column: int = 0, next_height_change: int = 0):
        """Updates height of desired column and optionally also its subsequent column.

        Used within dadda and wallace multipliers to perform gradual reduction of partial product columns through the stages.
        Allows to choose the height change to take effect on the chosen column index and optionally also the same for the following
        column if it should also be affected.

        Args:
            curr_column (int): Current pp column index.
            curr_height_change (int): Height change for the chosen current pp column.
            next_column (int, optional): Subsequent pp column index. Defaults to 0.
            next_height_change (int, optional): Height change for the chosen subsequent pp column. Defaults to 0.
        """
        self.columns[curr_column][0] = self.get_column_height(curr_column)+curr_height_change
        if next_column-1 == curr_column:
            self.columns[next_column][0] = self.get_column_height(next_column)+next_height_change

    def add_column_wire(self, column: int, bit: int):
        """Retrieves wire from desired partial product column bit position.

        If bit pair (AND/NAND gate) is present at the desired position, it is reduced and replaced with AND/NAND gate output wire accordingly.
        Either former logic gate's output wire or present wire is returned.

        Args:
            column (int): Partial product column index.
            bit (int): Bit position within the chosen column.

        Returns:
            Wire: Return Wire present at specified position.
        """
        # Checks if a logic gate is present at desired column bit position. If so the gate is added to circuit's list of subcomponents,
        # and the former logic gates's output bit replaces the gate at desired column bit position. This output wire is also returned to the caller.
        if isinstance(self.columns[column][bit+1], AndGate) or isinstance(self.columns[column][bit+1], NandGate):
            self.add_component(self.columns[column][bit+1])
            return self.get_previous_component(1).out
        else:
            return self.columns[column][bit+1]

    def get_column_wire(self, column: int, bit: int):
        """Retrieves wire from desired partial product column bit position.

        If bit pair (AND/NAND gate) is present at the desired position, AND/NAND gate output wire is returned,
        if not the wire present at the desired position is returned.

        Args:
            column (int): Partial product column index.
            bit (int): Bit position within the chosen column.

        Returns:
            Wire: Return Wire present at specified position.
        """
        # Checks if a logic gate is present at desired column bit position. If so, its output bit is returned.
        if isinstance(self.columns[column][bit+1], AndGate) or isinstance(self.columns[column][bit+1], NandGate):
            return self.columns[column][bit+1].out
        else:
            return self.columns[column][bit+1]

    def update_column_wires(self, curr_column: int, adder: ArithmeticCircuit, next_column: int = 0):
        """Provides bit height reduction of the chosen column.

        Inserts chosen column's top bits into an `adder` circuit to reduce its bit height.
        Generated sum is stored to the bottom of the column and generated carry bit is stored to the top of the next column.

        Args:
            curr_column (int): Current pp column index.
            adder (ArithmeticCircuit): Two/three input one bit adder.
            next_column (int, optional): Subsequent pp column index. Defaults to 0.
        """
        if hasattr(adder, "c"):
            self.columns[curr_column].pop(1)
            self.columns[curr_column].pop(1)
            self.columns[curr_column].pop(1)
            self.columns[curr_column].insert(self.get_column_height(curr_column), adder.get_sum_wire())
        else:
            self.columns[curr_column].pop(1)
            self.columns[curr_column].pop(1)
            self.columns[curr_column].insert(self.get_column_height(curr_column), adder.get_sum_wire())

        if next_column-1 == curr_column:
            self.columns[next_column].insert(1, adder.get_carry_wire())
