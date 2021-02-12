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
LG_PATH="C_circuits/Logic_gates/"
FLAT_ADD_PATH="C_circuits/Flat_circuits/Adders/"
HIER_ADD_PATH="C_circuits/Hierarchical_circuits/Adders/"

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
F_HA="./f_ha 2>/dev/null"
F_FA="./f_fa 2>/dev/null"

H_HA="./h_ha 2>/dev/null"
H_FA="./h_fa 2>/dev/null"

# Unsigned
F_U_RCA3="./f_u_rca3 2>/dev/null"
F_U_RCA5="./f_u_rca5 2>/dev/null"
F_U_RCA8="./f_u_rca8 2>/dev/null"

H_U_RCA3="./h_u_rca3 2>/dev/null"
H_U_RCA5="./h_u_rca5 2>/dev/null"
H_U_RCA8="./h_u_rca8 2>/dev/null"

# Signed
F_S_RCA2="./f_s_rca2 2>/dev/null"
F_S_RCA6="./f_s_rca6 2>/dev/null"
F_S_RCA8="./f_s_rca8 2>/dev/null"

H_S_RCA2="./h_s_rca2 2>/dev/null"
H_S_RCA4="./h_s_rca4 2>/dev/null"
H_S_RCA6="./h_s_rca6 2>/dev/null"
H_S_RCA8="./h_s_rca8 2>/dev/null"

# TESTING #
echo "${BLUECOLOR}TESTING C CODE CIRCUITS GENERATED USING arithmetic_circuits_generator.py"
echo "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"

echo ""
echo "${GREENCOLOR}–––––––––––––––"
echo " FLAT CIRCUITS"
echo "–––––––––––––––"
echo ""

echo "${BLUECOLOR}LOGIC GATES TESTS${NOCOLOR}"

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
echo "${BLUECOLOR}UNSIGNED ADDERS TESTS${NOCOLOR}"

## FLAT 1-BIT ADDERS ##

# HALF ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_ha.c -o f_ha
echo "TEST_8: f_ha.c"
eval "$F_HA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_ha

# FULL ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_fa.c -o f_fa
echo "TEST_9: f_fa.c"
eval "$F_FA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_fa

## FLAT UNSIGNED ADDERS ##

# 3-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_rca3.c -o f_u_rca3
echo "TEST_10: f_u_rca3.c"
eval "$F_U_RCA3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_rca3

# 5-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_rca5.c -o f_u_rca5
echo "TEST_11: f_u_rca5.c"
eval "$F_U_RCA5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_rca5

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_rca8.c -o f_u_rca8
echo "TEST_12: f_u_rca8.c"
eval "$F_U_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_rca8

echo ""
echo "${BLUECOLOR}SIGNED ADDERS TESTS${NOCOLOR}"

## FLAT SIGNED ADDERS ##

# 2-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_rca2.c -o f_s_rca2
echo "TEST_13: f_s_rca2.c"
eval "$F_S_RCA2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_rca2

# 6-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_rca6.c -o f_s_rca6
echo "TEST_14: f_s_rca6.c"
eval "$F_S_RCA6"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_rca6

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_rca8.c -o f_s_rca8
echo "TEST_15: f_s_rca8.c"
eval "$F_S_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_rca8

echo ""
echo "${GREENCOLOR}–––––––––––––––––––––––"
echo " HIERARCHICAL CIRCUITS"
echo "–––––––––––––––––––––––"
echo ""

echo "${BLUECOLOR}UNSIGNED ADDERS TESTS${NOCOLOR}"

## HIERARCHICAL 1-BIT ADDERS ##

# HALF ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_ha.c -o h_ha
echo "TEST_16: h_ha.c"
eval "$H_HA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_ha

# FULL ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_fa.c -o h_fa
echo "TEST_17: h_fa.c"
eval "$H_FA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_fa

## HIERARCHICAL UNSIGNED ADDERS ##

# 3-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_rca3.c -o h_u_rca3
echo "TEST_18: h_u_rca3.c"
eval "$H_U_RCA3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_rca3

# 5-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_rca5.c -o h_u_rca5
echo "TEST_19: h_u_rca5.c"
eval "$H_U_RCA5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_rca5

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_rca8.c -o h_u_rca8
echo "TEST_20: h_u_rca8.c"
eval "$H_U_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_rca8

echo ""
echo "${BLUECOLOR}SIGNED ADDERS TESTS${NOCOLOR}"

## HIERARCHICAL SIGNED ADDERS ##

# 2-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_rca2.c -o h_s_rca2
echo "TEST_21: h_s_rca2.c"
eval "$H_S_RCA2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_rca2

# 4-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_rca4.c -o h_s_rca4
echo "TEST_22: h_s_rca4.c"
eval "$H_S_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_rca4

# 6-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_rca6.c -o h_s_rca6
echo "TEST_23: h_s_rca6.c"
eval "$H_S_RCA6"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_rca6

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_rca8.c -o h_s_rca8
echo "TEST_24: h_s_rca8.c"
eval "$H_S_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_rca8