"""
Implementation of QuAdder

For more information, see:
M. A. Hanif, R. Hafiz, O. Hasan and M. Shafique, "QuAd: Design and analysis of Quality-area optimal Low-Latency approximate Adders," 2017 54th ACM/EDAC/IEEE Design Automation Conference (DAC), Austin, TX, USA, 2017, pp. 1-6, doi: 10.1145/3061639.3062306.

"""

from ...wire_components import (
    ConstantWireValue0,
    Bus
)
from ariths_gen.core.arithmetic_circuits import (
    GeneralCircuit
)

from ariths_gen.multi_bit_circuits.adders.ripple_carry_adder import (
    UnsignedRippleCarryAdder
)
import warnings


class QuAdder(GeneralCircuit):
    """
    Implementation of QuAd

    https://ieeexplore.ieee.org/document/8060326

    The implementation is inspired by Matlab code from the authors of the paper:
    ```matlab
    temp_count=1;
    for iij=1:length(R_vect)
        fprintf(fileID,['wire [' num2str(R_vect(iij)+P_vect(iij)) ':0] temp' num2str(temp_count) ';\n']);
        temp_count=temp_count + 1;
    end

    temp_count=1;
    for iiij=1:length(R_vect)
        if (sum(R_vect(1:iiij))+P_vect(1)-1) == (sum(R_vect(1:iiij))+P_vect(1)-R_vect(iiij)-P_vect(iiij))
            fprintf(fileID,['aassign temp' num2str(temp_count) '[' num2str(R_vect(iiij)+P_vect(iiij)) ':0] = in1[' num2str(sum(R_vect(1:iiij))+P_vect(1)-1) '] + in2[' num2str(sum(R_vect(1:iiij))+P_vect(1)-1) '];\n']);
        else
            disp(R_vect(1:iiij))
            fprintf(fileID,['bassign temp' num2str(temp_count) '[' num2str(R_vect(iiij)+P_vect(iiij)) ':0] = in1[' num2str(sum(R_vect(1:iiij))+P_vect(1)-1) ':' num2str(sum(R_vect(1:iiij))+P_vect(1)-R_vect(iiij)-P_vect(iiij)) '] + in2[' num2str(sum(R_vect(1:iiij))+P_vect(1)-1) ':' num2str(sum(R_vect(1:iiij))+P_vect(1)-R_vect(iiij)-P_vect(iiij)) '];\n']);
        end
        temp_count=temp_count+1;
    end

    statement='};\n';
    temp_count=1;
    for iiij=1:length(R_vect)
        if iiij ~= length(R_vect)
            if (R_vect(iiij)==1)
                statement = [', temp' num2str(temp_count) '[' num2str(R_vect(iiij)+P_vect(iiij)-1) '] ' statement];
            else
                statement = [', temp' num2str(temp_count) '[' num2str(R_vect(iiij)+P_vect(iiij)-1) ':' num2str(P_vect(iiij)) '] ' statement];
            end
        else
            statement = ['assign res[' num2str(N) ':0] =' '{ temp' num2str(temp_count) '[' num2str(R_vect(iiij)+P_vect(iiij)) ':' num2str(P_vect(iiij)) '] ' statement];
        end
        temp_count=temp_count+1;
    end
    ```


    """

    def log(self, *args):
        if self.use_log:
            print(*args)

    def __init__(self, a, b, R, P, prefix, name="quad", adder_type=None, use_log=False, **kwargs):
        """
        :param a: Bus first input
        :param b: Bus second input
        :param R: list of integers, defines the resultant bits of all the sub-adders (the first index specifies the resultant bits of sub-adder 1 and so on)
        :param P: list of integers, defines the prediction bits of all the sub-adders (again the first index specifies the prediction bits of sub-adder 1 and so on)
        """

        if not adder_type:
            adder_type = UnsignedRippleCarryAdder

        # Assumptions checks
        assert len(R) == len(P), "R and P must have the same length"
        print([P[i] < P[i-1] + R[i-1] for i in range(1, len(P))])
        assert all([P[i] < P[i-1] + R[i-1] for i in range(1, len(P))]
                   ), "Pi must be lower than Pi-1 + Ri-1"
        assert sum(R) == a.N, "Sum of R must be equal to number of bits"

        self.use_log = use_log

        self.N = max(a.N, b.N)
        super().__init__(inputs=[a, b], prefix=prefix, name=name, out_N=self.N+1, **kwargs)

        # Bus sign extension in case buses have different lengths
        self.a.bus_extend(N=self.N, prefix=a.prefix)
        self.b.bus_extend(N=self.N, prefix=b.prefix)

        # warnings.warn("QuAdder is not tested yet")

        # Connect all outputs to zero
        for i in range(self.N+1):
            self.out[i] = ConstantWireValue0()

        # Declaration of temporary wires (just for debug purposes)
        temp_count = 0
        for iiij in range(0, len(R)):
            self.log('wire [' + str(R[iiij]+P[iiij]) +
                     ':0] temp' + str(temp_count) + ';')
            temp_count = temp_count + 1

        def bus_subconnect(out_bus, in_bus, out_indexes, in_indexes):
            out_indexes = list(out_indexes)
            in_indexes = list(in_indexes)
            assert len(out_indexes) == len(in_indexes)

            for i, j in zip(out_indexes, in_indexes):
                if j >= in_bus.N:
                    out_bus[i] = ConstantWireValue0()  # unsigned extension
                else:
                    out_bus.connect(i, in_bus.get_wire(j))  # [i] = in_bus[j]

        # Connection of adders
        temp_count = 0
        temp_bus = []
        for iiij in range(0, len(R)):
            # Former verilog output
            self.log("assign temp{}[{}:0] = in1[{}:{}] + in2[{}:{}];".format(
                temp_count,
                R[iiij]+P[iiij],
                sum(R[0:iiij + 1]) + P[0]-1,
                sum(R[0:iiij + 1]) + P[0]-R[iiij]-P[iiij],
                sum(R[0:iiij + 1]) + P[0]-1,
                sum(R[0:iiij + 1]) + P[0]-R[iiij]-P[iiij]
            ))

            a1 = Bus(f"{prefix}_temp_{temp_count}_a", R[iiij]+P[iiij])
            b1 = Bus(f"{prefix}_temp_{temp_count}_b", R[iiij]+P[iiij])

            bus_subconnect(b1, self.b,
                           range(R[iiij]+P[iiij]),
                           range(sum(R[0:iiij + 1])+P[0]-R[iiij]-P[iiij], sum(R[0:iiij + 1])+P[0]))

            bus_subconnect(a1, self.a,
                           range(R[iiij]+P[iiij]),
                           range(sum(R[0:iiij + 1])+P[0]-R[iiij]-P[iiij], sum(R[0:iiij + 1])+P[0]))

            temp_bus.append(self.add_component(
                adder_type(a1, b1, prefix=f"{prefix}_add_{temp_count}")

            ))
            temp_count = temp_count+1

        # Final connection
        temp_count = 0
        statement = "}"
        wire_id = 0
        for iiij in range(0, len(R)):
            if iiij != len(R) - 1:
                if R[iiij] == 1:
                    statement = ', temp{}[{}]'.format(
                        temp_count, R[iiij]+P[iiij] - 1) + statement
                else:
                    statement = ', temp{}[{}:{}]'.format(
                        temp_count, R[iiij]+P[iiij] - 1, P[iiij]) + statement

            else:
                statement = 'assign res[' + str(self.N) + ':0] =' + '{ temp' + str(
                    temp_count) + '[' + str(R[iiij]+P[iiij]) + ':' + str(P[iiij]) + '] ' + statement

            self.log(statement)
            for i in range(P[iiij], R[iiij]+P[iiij]):
                self.log(temp_count, i, wire_id, temp_bus[temp_count].out[i])
                self.out[wire_id] = temp_bus[temp_count].out[i]
                wire_id += 1

            temp_count = temp_count+1

        # Last carry (MSB)
        self.out[wire_id] = temp_bus[temp_count - 1].out[R[iiij]+P[iiij]]
