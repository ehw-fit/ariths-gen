#!/usr/bin/bash

valid=1

test_circuit () {
    local type=$1
    local circuit=$2



    for mode in "flat" "hier"; do
        echo -e "===== Testing verilog \e[33m$circuit\e[0m ($mode) ======"

        if iverilog -o tmp.verilog -Ddut=$circuit ../test_circuits/verilog_circuits/$mode/$circuit.v tb_$type.v ; then
            tv=`vvp tmp.verilog`
            if [[ $tv ]]; then
                echo -e "[\e[31mfail\e[0m]"
                echo -e $tv
                valid=0
            else
                echo -e "[\e[32mok\e[0m]"
            fi
        else
            echo -e "[\e[31mfailed synthesis\e[0m]"
            valid=0
        fi

        # if ./tmp.exe ; then
        #     echo -e "[\e[32mok\e[0m]"
        # else
        #     echo -e "[\e[31mfail\e[0m]"
        #     valid=0
        # fi
    done
}



test_circuit "adder_signed" "s_rca8"
test_circuit "adder_signed" "s_pg_rca8"
test_circuit "adder_signed" "s_cska8"
test_circuit "adder_signed" "s_cla8"

test_circuit "adder_unsigned" "u_rca8"
test_circuit "adder_unsigned" "u_pg_rca8"
test_circuit "adder_unsigned" "u_cska8"
test_circuit "adder_unsigned" "u_cla8"


test_circuit "multiplier_signed" "s_arrmul8"
test_circuit "multiplier_signed" "s_csamul_cla8" 
test_circuit "multiplier_signed" "s_csamul_rca8" 
test_circuit "multiplier_signed" "s_csamul_pg_rca8" 
test_circuit "multiplier_signed" "s_csamul_cska8" 
test_circuit "multiplier_signed" "s_wallace_cla8" 
test_circuit "multiplier_signed" "s_wallace_rca8" 
test_circuit "multiplier_signed" "s_wallace_pg_rca8" 
test_circuit "multiplier_signed" "s_wallace_cska8" 
test_circuit "multiplier_signed" "s_CSAwallace_cla8" 
test_circuit "multiplier_signed" "s_CSAwallace_rca8" 
test_circuit "multiplier_signed" "s_CSAwallace_pg_rca8" 
test_circuit "multiplier_signed" "s_CSAwallace_cska8" 
test_circuit "multiplier_signed" "s_dadda_cla8" 
test_circuit "multiplier_signed" "s_dadda_rca8" 
test_circuit "multiplier_signed" "s_dadda_pg_rca8" 
test_circuit "multiplier_signed" "s_dadda_cska8" 


test_circuit "multiplier_unsigned" "u_arrmul8"
test_circuit "multiplier_unsigned" "u_csamul_cla8" 
test_circuit "multiplier_unsigned" "u_csamul_rca8" 
test_circuit "multiplier_unsigned" "u_csamul_pg_rca8" 
test_circuit "multiplier_unsigned" "u_csamul_cska8" 
test_circuit "multiplier_unsigned" "u_wallace_cla8" 
test_circuit "multiplier_unsigned" "u_wallace_rca8" 
test_circuit "multiplier_unsigned" "u_wallace_pg_rca8" 
test_circuit "multiplier_unsigned" "u_wallace_cska8"
test_circuit "multiplier_unsigned" "u_CSAwallace_cla8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_rca8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_pg_rca8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_cska8" 
test_circuit "multiplier_unsigned" "u_dadda_cla8" 
test_circuit "multiplier_unsigned" "u_dadda_rca8" 
test_circuit "multiplier_unsigned" "u_dadda_pg_rca8" 
test_circuit "multiplier_unsigned" "u_dadda_cska8" 



if [ "$valid" -eq 1 ]; then
    echo "all tests passed"
    exit 0
else 
    echo "some of tests failed"
    exit 1
fi