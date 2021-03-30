from .arithmetic_circuit import(
    ArithmeticCircuit
)

from ariths_gen.one_bit_circuits.logic_gates import(
    LogicGate,
    AndGate,
    NandGate,
    OrGate,
    NorGate,
    XorGate,
    XnorGate,
    NotGate  
)

from ariths_gen.wire_components import(
    Wire,
    Bus
)

import math

""" MULTIPLIER CIRCUITS """
class MultiplierCircuit(ArithmeticCircuit):
    def __init__(self):
        super().__init__()

    """ Array multipliers """
    # Used in array multipliers to get previous row's component output wires
    # for further connection to another component's input
    def get_previous_partial_product(self, a_index: int, b_index: int, offset: int = 0):
        # To get the index of previous row's connecting adder and its generated pp
        index = ((b_index-2) * (self.N*2)) + ((self.N-1)+2*(a_index+2)) + offset

        # Get carry wire as input for the last adder in current row
        if a_index == self.N-1:
            index = index-2
            return self.components[index].get_carry_wire()
        # Get sum wire as input for current adder
        else:
            return self.components[index].get_sum_wire()

    """ Dadda multiplier """
    # Used in dadda multipliers to get multiplier's maximum height
    @staticmethod
    def get_maximum_height(initial_value: int):
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

    def init_column_heights(self, signed=False):
        columns = [[num] if num <= self.N else [num - (num - self.N)*2] for num in range(1, self.out.N)]
        columns = [self.add_column_wires(column=col, column_index=columns.index(col)) for col in columns]
        return columns

    def add_column_wires(self, column: list, column_index: int):
        [column.append([]) for _ in range(column[0])]
        if column_index <= self.N-1:
            [column[column[0]-index].append(self.a.get_wire(index)) for index in range(0, column[0])]
            [column[index+1].append(self.b.get_wire(index)) for index in range(0, column[0])]
        else:
            [column[self.a.N-index].append(self.a.get_wire(index)) for index in range(self.a.N-1, self.a.N-column[0]-1, -1)]
            [column[index-(self.a.N-1-column[0])].append(self.b.get_wire(index)) for index in range(self.a.N-column[0], self.a.N)]

        # TODO check and refactor
        # Filling unsigned pp matrix with AND gates
        if self.__class__.__name__ == "unsigned_dadda_multiplier" or self.__class__.__name__ == "unsigned_wallace_multiplier":
            column[1:] = [AndGate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index)) for i in range(1, len(column))]
        # Filling signed pp matrix with AND/NAND gates (based on Baugh-Wooley multiplication algorithm)
        else:
            # First half of partial product columns contains only AND gates
            if column_index < self.N-1 or column_index == self.out.N-2:
                column[1:] = [AndGate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index)) for i in range(1, len(column))]
            # Second half of partial product columns contains NAND/AND gates
            else:
                column[1] = NandGate(a=column[1][0], b=column[1][1], prefix=self.prefix+'_nand_'+str(column[1][0].index)+'_'+str(column[1][1].index))
                column[-1] = NandGate(a=column[-1][0], b=column[-1][1], prefix=self.prefix+'_nand_'+str(column[-1][0].index)+'_'+str(column[-1][1].index))
                if len(column[2:-1]) != 0:
                    column[2:-1] = [AndGate(a=column[i][0], b=column[i][1], prefix=self.prefix+'_and_'+str(column[i][0].index)+'_'+str(column[i][1].index)) for i in range(2, len(column)-1)]
        
        return column

    def get_column_height(self, column_num: int):
        return self.columns[column_num][0]

    def update_column_heights(self, curr_column: int, curr_height_change: int, next_column: int = 0, next_height_change: int = 0):
        self.columns[curr_column][0] = self.get_column_height(curr_column)+curr_height_change
        if next_column-1 == curr_column:
            self.columns[next_column][0] = self.get_column_height(next_column)+next_height_change

    def get_column_wire(self, column: int, bit: int):
        if isinstance(self.columns[column][bit], AndGate) or isinstance(self.columns[column][bit], NandGate):
            self.add_component(self.columns[column][bit])
            return self.get_previous_component(1).out
        else:
            return self.columns[column][bit]

    def update_column_wires(self, curr_column: int, adder: ArithmeticCircuit, next_column: int = 0):
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
