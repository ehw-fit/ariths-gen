#!/usr/bin/bash

valid=1

test_circuit () {
    local type=$1
    local circuit=$2


    mode="flat"
    echo -e "===== Testing CGP version \e[33m$circuit\e[0m ($mode) ======"

    s=""
    if [[ $type == *"_signed" ]]; then
        s="--signed"
    fi
    python3 ../chr2c.py $s ../test_circuits/cgp_circuits/$mode/$circuit.cgp > tmp.c


    g++ -std=c++11 -pedantic -g -std=c++11 -pedantic -DCNAME="circuit8" $type.c tmp.c -o tmp.exe
    if ./tmp.exe ; then
        echo -e "[\e[32mok\e[0m]"
    else
        echo -e "[\e[31mfail\e[0m]"
        valid=0
    fi
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
test_circuit "multiplier_signed" "s_wallace_cla8" 
test_circuit "multiplier_signed" "s_wallace_rca8" 
test_circuit "multiplier_signed" "s_wallace_pg_rca8" 
test_circuit "multiplier_signed" "s_wallace_cska8" 
test_circuit "multiplier_signed" "s_dadda_cla8" 
test_circuit "multiplier_signed" "s_dadda_rca8" 
test_circuit "multiplier_signed" "s_dadda_pg_rca8" 
test_circuit "multiplier_signed" "s_dadda_cska8" 


test_circuit "multiplier_unsigned" "u_arrmul8" 
test_circuit "multiplier_unsigned" "u_wallace_cla8" 
test_circuit "multiplier_unsigned" "u_wallace_rca8" 
test_circuit "multiplier_unsigned" "u_wallace_pg_rca8" 
test_circuit "multiplier_unsigned" "u_wallace_cska8" 
test_circuit "multiplier_unsigned" "u_dadda_cla8" 
test_circuit "multiplier_unsigned" "u_dadda_rca8" 
test_circuit "multiplier_unsigned" "u_dadda_pg_rca8" 
test_circuit "multiplier_unsigned" "u_dadda_cska8" 



if [ $valid -eq 1 ]; then
    echo "all tests passed"
    exit 0
else 
    echo "some of tests failed"
    exit 1
fi


# exporting s_rca8
# exporting s_pg_rca8
# exporting s_cska8
# exporting s_cla8
# exporting s_arrmul8
# exporting s_wallace_cla8
# exporting s_wallace_rca8
# exporting s_wallace_pg_rca8
# exporting s_wallace_cska8
# exporting s_dadda_cla8
# exporting s_dadda_rca8
# exporting s_dadda_pg_rca8
# exporting s_dadda_cska8
# exporting u_rca8
# exporting u_pg_rca8
# exporting u_cska8
# exporting u_cla8
# exporting u_arrmul8
# exporting u_wallace_cla8
# exporting u_wallace_rca8
# exporting u_wallace_pg_rca8
# exporting u_wallace_cska8
# exporting u_dadda_cla8
# exporting u_dadda_rca8
# exporting u_dadda_pg_rca8
# exporting u_dadda_cska8
# exporting arrdiv8
