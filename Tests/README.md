# Testing of arithmetic circuits generated to C code using ArithsGen

## Description
Script checks correct functionality of various architectures of unsigned/signed adders and multipliers located in 'c_circuits' folder. Folder contains circuits in flattened as well as in hierarchical representation to ensure proper testing. Script automatically compiles and runs all tests and echoes the results back to console.

**Note** that these circuits were manually modified to allow such a testing (added main with nested loops and asserts)! 

## Execute permission
    chmod +x c_tests.sh
## Usage
    ./c_tests.sh