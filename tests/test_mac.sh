#!/usr/bin/bash

valid=1

test_circuit_mac () {
    local type=$1



    for mode in "flat" "hier"; do
        echo -e "===== Testing \e[33m$circuit\e[0m ($mode) ======"

        g++ -std=c++11 -pedantic -g -std=c++11 -pedantic -DCNAME="$circuit" $type.c ../test_circuits/mac/mac_$mode.c -o tmp.exe
        if ./tmp.exe ; then
            echo -e "[\e[32mok\e[0m]"
        else
            echo -e "[\e[31mfail\e[0m]"
            valid=0
        fi
    done
}



test_circuit_mac "mac"



if [ $valid -eq 1 ]; then
    echo "all tests passed"
    exit 0
else 
    echo "some of tests failed"
    exit 1
fi
