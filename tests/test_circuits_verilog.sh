#!/usr/bin/bash

valid=1

test_circuit () {
    local type=$1
    local circuit=$2



    for mode in "flat" "hier"; do
        echo -e "===== Testing verilog \e[33m$circuit\e[0m ($mode) ======"

        if iverilog -o tmp.verilog -Ddut=$circuit ../test_circuits/verilog_circuits/$mode/$circuit.v tb_$type.v ; then
            tv=`vvp -n tmp.verilog`
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
test_circuit "adder_signed" "s_cosa8"
test_circuit "adder_signed" "s_csla8"
test_circuit "adder_signed" "s_cia8"
test_circuit "adder_signed" "s_ksa8"
test_circuit "adder_signed" "s_bka8"
test_circuit "adder_signed" "s_sa8"
test_circuit "adder_signed" "s_hca8"
test_circuit "adder_signed" "s_ka8"
test_circuit "adder_signed" "s_lfa8"


test_circuit "adder_unsigned" "u_rca8"
test_circuit "adder_unsigned" "u_pg_rca8"
test_circuit "adder_unsigned" "u_cska8"
test_circuit "adder_unsigned" "u_cla8"
test_circuit "adder_unsigned" "u_cosa8"
test_circuit "adder_unsigned" "u_csla8"
test_circuit "adder_unsigned" "u_cia8"
test_circuit "adder_unsigned" "u_ksa8"
test_circuit "adder_unsigned" "u_bka8"
test_circuit "adder_unsigned" "u_sa8"
test_circuit "adder_unsigned" "u_hca8"
test_circuit "adder_unsigned" "u_ka8"
test_circuit "adder_unsigned" "u_lfa8"


test_circuit "subtractor_signed" "s_rcs8"
test_circuit "subtractor_signed" "s_rbs8"


test_circuit "subtractor_unsigned" "u_rcs8"
test_circuit "subtractor_unsigned" "u_rbs8"


test_circuit "multiplier_signed" "s_arrmul8"
test_circuit "multiplier_signed" "s_csamul_cla8" 
test_circuit "multiplier_signed" "s_csamul_rca8" 
test_circuit "multiplier_signed" "s_csamul_pg_rca8" 
test_circuit "multiplier_signed" "s_csamul_cska8" 
test_circuit "multiplier_signed" "s_csamul_cosa8" 
test_circuit "multiplier_signed" "s_csamul_csla8" 
test_circuit "multiplier_signed" "s_csamul_cia8" 
test_circuit "multiplier_signed" "s_csamul_ksa8" 
test_circuit "multiplier_signed" "s_csamul_bka8" 
test_circuit "multiplier_signed" "s_csamul_sa8" 
test_circuit "multiplier_signed" "s_csamul_hca8" 
test_circuit "multiplier_signed" "s_csamul_ka8" 
test_circuit "multiplier_signed" "s_csamul_lfa8" 
test_circuit "multiplier_signed" "s_wallace_cla8" 
test_circuit "multiplier_signed" "s_wallace_rca8" 
test_circuit "multiplier_signed" "s_wallace_pg_rca8" 
test_circuit "multiplier_signed" "s_wallace_cska8" 
test_circuit "multiplier_signed" "s_wallace_cosa8" 
test_circuit "multiplier_signed" "s_wallace_csla8" 
test_circuit "multiplier_signed" "s_wallace_cia8" 
test_circuit "multiplier_signed" "s_wallace_ksa8" 
test_circuit "multiplier_signed" "s_wallace_bka8" 
test_circuit "multiplier_signed" "s_wallace_sa8" 
test_circuit "multiplier_signed" "s_wallace_hca8" 
test_circuit "multiplier_signed" "s_wallace_ka8" 
test_circuit "multiplier_signed" "s_wallace_lfa8"
test_circuit "multiplier_signed" "s_CSAwallace_cla8" 
test_circuit "multiplier_signed" "s_CSAwallace_rca8" 
test_circuit "multiplier_signed" "s_CSAwallace_pg_rca8" 
test_circuit "multiplier_signed" "s_CSAwallace_cska8" 
test_circuit "multiplier_signed" "s_CSAwallace_cosa8" 
test_circuit "multiplier_signed" "s_CSAwallace_csla8" 
test_circuit "multiplier_signed" "s_CSAwallace_cia8" 
test_circuit "multiplier_signed" "s_CSAwallace_ksa8" 
test_circuit "multiplier_signed" "s_CSAwallace_bka8" 
test_circuit "multiplier_signed" "s_CSAwallace_sa8" 
test_circuit "multiplier_signed" "s_CSAwallace_hca8" 
test_circuit "multiplier_signed" "s_CSAwallace_ka8" 
test_circuit "multiplier_signed" "s_CSAwallace_lfa8"
test_circuit "multiplier_signed" "s_dadda_cla8" 
test_circuit "multiplier_signed" "s_dadda_rca8" 
test_circuit "multiplier_signed" "s_dadda_pg_rca8" 
test_circuit "multiplier_signed" "s_dadda_cska8" 
test_circuit "multiplier_signed" "s_dadda_cosa8" 
test_circuit "multiplier_signed" "s_dadda_csla8" 
test_circuit "multiplier_signed" "s_dadda_cia8" 
test_circuit "multiplier_signed" "s_dadda_ksa8" 
test_circuit "multiplier_signed" "s_dadda_bka8" 
test_circuit "multiplier_signed" "s_dadda_sa8" 
test_circuit "multiplier_signed" "s_dadda_hca8" 
test_circuit "multiplier_signed" "s_dadda_ka8" 
test_circuit "multiplier_signed" "s_dadda_lfa8"


test_circuit "multiplier_unsigned" "u_arrmul8"
test_circuit "multiplier_unsigned" "u_recmul8"
test_circuit "multiplier_unsigned" "u_csamul_cla8" 
test_circuit "multiplier_unsigned" "u_csamul_rca8" 
test_circuit "multiplier_unsigned" "u_csamul_pg_rca8" 
test_circuit "multiplier_unsigned" "u_csamul_cska8" 
test_circuit "multiplier_unsigned" "u_csamul_cosa8" 
test_circuit "multiplier_unsigned" "u_csamul_csla8" 
test_circuit "multiplier_unsigned" "u_csamul_cia8" 
test_circuit "multiplier_unsigned" "u_csamul_ksa8" 
test_circuit "multiplier_unsigned" "u_csamul_bka8" 
test_circuit "multiplier_unsigned" "u_csamul_sa8" 
test_circuit "multiplier_unsigned" "u_csamul_hca8" 
test_circuit "multiplier_unsigned" "u_csamul_ka8" 
test_circuit "multiplier_unsigned" "u_csamul_lfa8" 
test_circuit "multiplier_unsigned" "u_wallace_cla8" 
test_circuit "multiplier_unsigned" "u_wallace_rca8" 
test_circuit "multiplier_unsigned" "u_wallace_pg_rca8" 
test_circuit "multiplier_unsigned" "u_wallace_cska8" 
test_circuit "multiplier_unsigned" "u_wallace_cosa8" 
test_circuit "multiplier_unsigned" "u_wallace_csla8" 
test_circuit "multiplier_unsigned" "u_wallace_cia8" 
test_circuit "multiplier_unsigned" "u_wallace_ksa8" 
test_circuit "multiplier_unsigned" "u_wallace_bka8" 
test_circuit "multiplier_unsigned" "u_wallace_sa8" 
test_circuit "multiplier_unsigned" "u_wallace_hca8" 
test_circuit "multiplier_unsigned" "u_wallace_ka8" 
test_circuit "multiplier_unsigned" "u_wallace_lfa8"
test_circuit "multiplier_unsigned" "u_CSAwallace_cla8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_rca8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_pg_rca8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_cska8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_cosa8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_csla8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_cia8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_ksa8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_bka8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_sa8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_hca8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_ka8" 
test_circuit "multiplier_unsigned" "u_CSAwallace_lfa8"
test_circuit "multiplier_unsigned" "u_dadda_cla8" 
test_circuit "multiplier_unsigned" "u_dadda_rca8" 
test_circuit "multiplier_unsigned" "u_dadda_pg_rca8" 
test_circuit "multiplier_unsigned" "u_dadda_cska8" 
test_circuit "multiplier_unsigned" "u_dadda_cosa8" 
test_circuit "multiplier_unsigned" "u_dadda_csla8" 
test_circuit "multiplier_unsigned" "u_dadda_cia8" 
test_circuit "multiplier_unsigned" "u_dadda_ksa8" 
test_circuit "multiplier_unsigned" "u_dadda_bka8" 
test_circuit "multiplier_unsigned" "u_dadda_sa8" 
test_circuit "multiplier_unsigned" "u_dadda_hca8" 
test_circuit "multiplier_unsigned" "u_dadda_ka8" 
test_circuit "multiplier_unsigned" "u_dadda_lfa8" 



if [ "$valid" -eq 1 ]; then
    echo "all tests passed"
    exit 0
else 
    echo "some of tests failed"
    exit 1
fi