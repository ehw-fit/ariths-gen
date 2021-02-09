#!/bin/sh
POSIXLY_CORRECT=yes

# Colors
# set thanks to: https://linux.101hacks.com/ps1-examples/prompt-color-using-tput/
REDCOLOR="$(tput setaf 1)"
GREENCOLOR="$(tput setaf 2)"
BLUECOLOR="$(tput setaf 4)"
NOCOLOR="$(tput sgr0)"

# Compiler options
C=g++
CFLAGS=-std=c++11 -Wextra -pedantic -g
LG_PATH="Flat_c_circuits/Logic_gates/"
ADD_PATH="Flat_c_circuits/Adders/"

# FLATTENED C CODE CIRCUITS #
# Logic gates
AND_G="./and_gate 2>/dev/null"
NAND_G="./nand_gate 2>/dev/null"
OR_G="./or_gate 2>/dev/null"
NOR_G="./nor_gate 2>/dev/null"
XOR_G="./xor_gate 2>/dev/null"
XNOR_G="./xnor_gate 2>/dev/null"
NOT_G="./not_gate 2>/dev/null"

# Adders
HA="./ha 2>/dev/null"
FA="./fa 2>/dev/null"

# Unsigned
U_RCA3="./u_rca3 2>/dev/null"
U_RCA5="./u_rca5 2>/dev/null"
U_RCA8="./u_rca8 2>/dev/null"

# Signed
S_RCA2="./s_rca2 2>/dev/null"
S_RCA6="./s_rca6 2>/dev/null"
S_RCA8="./s_rca8 2>/dev/null"

# TESTING #
echo "${BLUECOLOR}TESTING OF FLATTENED CIRCUITS GENERATED USING arithmetic_circuits_generator.py"
echo "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"
echo ""
echo "LOGIC GATES TESTS${NOCOLOR}"


## LOGIC GATES ##
#################

# AND
${C} ${CFLAGS} ${LG_PATH}and_gate.c -o and_gate
echo "TEST_1: and_gate.c"
eval "$AND_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm and_gate

# NAND
${C} ${CFLAGS} ${LG_PATH}nand_gate.c -o nand_gate
echo "TEST_2: nand_gate.c"
eval "$NAND_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm nand_gate

# OR
${C} ${CFLAGS} ${LG_PATH}or_gate.c -o or_gate
echo "TEST_3: or_gate.c"
eval "$OR_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm or_gate

# NOR
${C} ${CFLAGS} ${LG_PATH}nor_gate.c -o nor_gate
echo "TEST_4: nor_gate.c"
eval "$NOR_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm nor_gate

# XOR
${C} ${CFLAGS} ${LG_PATH}xor_gate.c -o xor_gate
echo "TEST_5: xor_gate.c"
eval "$XOR_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm xor_gate

# XNOR
${C} ${CFLAGS} ${LG_PATH}xnor_gate.c -o xnor_gate
echo "TEST_6: xnor_gate.c"
eval "$XNOR_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm xnor_gate

# NOT
${C} ${CFLAGS} ${LG_PATH}not_gate.c -o not_gate
echo "TEST_7: not_gate.c"
eval "$NOT_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm not_gate

echo ""
echo "${BLUECOLOR}ADDERS TESTS${NOCOLOR}"


## ADDERS ##
############

# HALF ADDER
${C} ${CFLAGS} ${ADD_PATH}ha.c -o ha
echo "TEST_8: ha.c"
eval "$HA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm ha

# FULL ADDER
${C} ${CFLAGS} ${ADD_PATH}fa.c -o fa
echo "TEST_9: fa.c"
eval "$FA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm fa

## UNSIGNED ADDERS ##

# 3-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${ADD_PATH}u_rca3.c -o u_rca3
echo "TEST_10: u_rca3.c"
eval "$U_RCA3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm u_rca3

# 5-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${ADD_PATH}u_rca5.c -o u_rca5
echo "TEST_11: u_rca5.c"
eval "$U_RCA5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm u_rca5

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${ADD_PATH}u_rca8.c -o u_rca8
echo "TEST_12: u_rca8.c"
eval "$U_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm u_rca8

## SIGNED ADDERS ##

# 2-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${ADD_PATH}s_rca2.c -o s_rca2
echo "TEST_13: s_rca2.c"
eval "$S_RCA2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm s_rca2

# 2-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${ADD_PATH}s_rca6.c -o s_rca6
echo "TEST_14: s_rca6.c"
eval "$S_RCA6"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm s_rca6

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${ADD_PATH}s_rca8.c -o s_rca8
echo "TEST_15: s_rca8.c"
eval "$S_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm s_rca8