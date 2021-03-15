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
CFLAGS="-std=c++11 -pedantic -g"
LG_PATH="C_circuits/Logic_gates/"
FLAT_ADD_PATH="C_circuits/Flat_circuits/Adders/"
FLAT_MUL_PATH="C_circuits/Flat_circuits/Multipliers/"
HIER_ADD_PATH="C_circuits/Hierarchical_circuits/Adders/"
HIER_MUL_PATH="C_circuits/Hierarchical_circuits/Multipliers/"

## FLATTENED C CODE CIRCUITS ##
# Logic gates
AND_G="./and_gate 2>/dev/null"
NAND_G="./nand_gate 2>/dev/null"
OR_G="./or_gate 2>/dev/null"
NOR_G="./nor_gate 2>/dev/null"
XOR_G="./xor_gate 2>/dev/null"
XNOR_G="./xnor_gate 2>/dev/null"
NOT_G="./not_gate 2>/dev/null"

# Adders #
# 1-bit
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


# Multipliers #
# Unsigned
F_U_ARR_MUL1="./f_u_arr_mul1 2>/dev/null"
F_U_ARR_MUL2="./f_u_arr_mul2 2>/dev/null"
F_U_ARR_MUL3="./f_u_arr_mul3 2>/dev/null"
F_U_ARR_MUL5="./f_u_arr_mul5 2>/dev/null"
F_U_ARR_MUL8="./f_u_arr_mul8 2>/dev/null"
F_U_ARR_MUL10="./f_u_arr_mul10 2>/dev/null"

H_U_ARR_MUL1="./h_u_arr_mul1 2>/dev/null"
H_U_ARR_MUL2="./h_u_arr_mul2 2>/dev/null"
H_U_ARR_MUL3="./h_u_arr_mul3 2>/dev/null"
H_U_ARR_MUL5="./h_u_arr_mul5 2>/dev/null"
H_U_ARR_MUL8="./h_u_arr_mul8 2>/dev/null"
H_U_ARR_MUL10="./h_u_arr_mul10 2>/dev/null"

F_U_DADDA_MUL2="./f_u_dadda_mul2 2>/dev/null"
F_U_DADDA_MUL4="./f_u_dadda_mul4 2>/dev/null"
F_U_DADDA_MUL6="./f_u_dadda_mul6 2>/dev/null"
F_U_DADDA_MUL8="./f_u_dadda_mul8 2>/dev/null"

H_U_DADDA_MUL2="./h_u_dadda_mul2 2>/dev/null"
H_U_DADDA_MUL4="./h_u_dadda_mul4 2>/dev/null"
H_U_DADDA_MUL6="./h_u_dadda_mul6 2>/dev/null"
H_U_DADDA_MUL8="./h_u_dadda_mul8 2>/dev/null"

# Signed
F_S_ARR_MUL1="./f_s_arr_mul1 2>/dev/null"
F_S_ARR_MUL2="./f_s_arr_mul2 2>/dev/null"
F_S_ARR_MUL3="./f_s_arr_mul3 2>/dev/null"
F_S_ARR_MUL5="./f_s_arr_mul5 2>/dev/null"
F_S_ARR_MUL8="./f_s_arr_mul8 2>/dev/null"
F_S_ARR_MUL10="./f_s_arr_mul10 2>/dev/null"

H_S_ARR_MUL1="./h_s_arr_mul1 2>/dev/null"
H_S_ARR_MUL2="./h_s_arr_mul2 2>/dev/null"
H_S_ARR_MUL3="./h_s_arr_mul3 2>/dev/null"
H_S_ARR_MUL5="./h_s_arr_mul5 2>/dev/null"
H_S_ARR_MUL8="./h_s_arr_mul8 2>/dev/null"
H_S_ARR_MUL10="./h_s_arr_mul10 2>/dev/null"


### TESTING ###
echo "${BLUECOLOR}TESTING C CODE CIRCUITS GENERATED USING arithmetic_circuits_generator.py"
echo "––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"
TEST_NUM=0

echo ""
echo "${GREENCOLOR}–––––––––––––––"
echo " FLAT CIRCUITS"
echo "–––––––––––––––"
echo ""

#################
## LOGIC GATES ##
#################
echo "${BLUECOLOR}LOGIC GATES TESTS${NOCOLOR}"

# AND
${C} ${CFLAGS} ${LG_PATH}and_gate.c -o and_gate
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: and_gate.c"
eval "$AND_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm and_gate

# NAND
${C} ${CFLAGS} ${LG_PATH}nand_gate.c -o nand_gate
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: nand_gate.c"
eval "$NAND_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm nand_gate

# OR
${C} ${CFLAGS} ${LG_PATH}or_gate.c -o or_gate
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: or_gate.c"
eval "$OR_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm or_gate

# NOR
${C} ${CFLAGS} ${LG_PATH}nor_gate.c -o nor_gate
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: nor_gate.c"
eval "$NOR_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm nor_gate

# XOR
${C} ${CFLAGS} ${LG_PATH}xor_gate.c -o xor_gate
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: xor_gate.c"
eval "$XOR_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm xor_gate

# XNOR
${C} ${CFLAGS} ${LG_PATH}xnor_gate.c -o xnor_gate
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: xnor_gate.c"
eval "$XNOR_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm xnor_gate

# NOT
${C} ${CFLAGS} ${LG_PATH}not_gate.c -o not_gate
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: not_gate.c"
eval "$NOT_G"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm not_gate

#####################
## UNSIGNED ADDERS ##
#####################
echo ""
echo "${BLUECOLOR}UNSIGNED ADDERS TESTS${NOCOLOR}"

## FLAT 1-BIT ADDERS ##
#######################

# HALF ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_ha.c -o f_ha
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_ha.c"
eval "$F_HA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_ha

# FULL ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_fa.c -o f_fa
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_fa.c"
eval "$F_FA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_fa

## FLAT UNSIGNED ADDERS ##
##########################

# 3-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_rca3.c -o f_u_rca3
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_rca3.c"
eval "$F_U_RCA3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_rca3

# 5-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_rca5.c -o f_u_rca5
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_rca5.c"
eval "$F_U_RCA5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_rca5

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_rca8.c -o f_u_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_rca8.c"
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
########################

# 2-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_rca2.c -o f_s_rca2
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_rca2.c"
eval "$F_S_RCA2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_rca2

# 6-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_rca6.c -o f_s_rca6
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_rca6.c"
eval "$F_S_RCA6"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_rca6

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_rca8.c -o f_s_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_rca8.c"
eval "$F_S_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_rca8


##########################
## UNSIGNED MULTIPLIERS ##
##########################
echo ""
echo "${BLUECOLOR}UNSIGNED MULTIPLIERS TESTS${NOCOLOR}"

## FLAT UNSIGNED MULTIPLIERS ##
###############################

# 1-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_arr_mul1.c -o f_u_arr_mul1
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_arr_mul1.c"
eval "$F_U_ARR_MUL1"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_arr_mul1

# 2-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_arr_mul2.c -o f_u_arr_mul2
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_arr_mul2.c"
eval "$F_U_ARR_MUL2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_arr_mul2

# 3-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_arr_mul3.c -o f_u_arr_mul3
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_arr_mul3.c"
eval "$F_U_ARR_MUL3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_arr_mul3

# 5-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_arr_mul5.c -o f_u_arr_mul5
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_arr_mul5.c"
eval "$F_U_ARR_MUL5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_arr_mul5

# 8-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_arr_mul8.c -o f_u_arr_mul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_arr_mul8.c"
eval "$F_U_ARR_MUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_arr_mul8

# 10-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_arr_mul10.c -o f_u_arr_mul10
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_arr_mul10.c"
eval "$F_U_ARR_MUL10"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_arr_mul10

# 2-BIT DADDA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_mul2.c -o f_u_dadda_mul2
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_mul2.c"
eval "$F_U_DADDA_MUL2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_mul2

# 4-BIT DADDA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_mul4.c -o f_u_dadda_mul4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_mul4.c"
eval "$F_U_DADDA_MUL4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_mul4

# 6-BIT DADDA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_mul6.c -o f_u_dadda_mul6
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_mul6.c"
eval "$F_U_DADDA_MUL6"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_mul6

# 8-BIT DADDA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_mul8.c -o f_u_dadda_mul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_mul8.c"
eval "$F_U_DADDA_MUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_mul8


########################
## SIGNED MULTIPLIERS ##
########################
echo ""
echo "${BLUECOLOR}SIGNED MULTIPLIERS TESTS${NOCOLOR}"

## FLAT SIGNED MULTIPLIERS ##
###############################

# 1-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_arr_mul1.c -o f_s_arr_mul1
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_arr_mul1.c"
eval "$F_S_ARR_MUL1"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_arr_mul1

# 2-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_arr_mul2.c -o f_s_arr_mul2
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_arr_mul2.c"
eval "$F_S_ARR_MUL2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_arr_mul2

# 3-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_arr_mul3.c -o f_s_arr_mul3
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_arr_mul3.c"
eval "$F_S_ARR_MUL3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_arr_mul3

# 5-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_arr_mul5.c -o f_s_arr_mul5
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_arr_mul5.c"
eval "$F_S_ARR_MUL5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_arr_mul5

# 8-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_arr_mul8.c -o f_s_arr_mul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_arr_mul8.c"
eval "$F_S_ARR_MUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_arr_mul8

# 10-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_arr_mul10.c -o f_s_arr_mul10
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_arr_mul10.c"
eval "$F_S_ARR_MUL10"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_arr_mul10





echo ""
echo "${GREENCOLOR}–––––––––––––––––––––––"
echo " HIERARCHICAL CIRCUITS"
echo "–––––––––––––––––––––––"
echo ""


#####################
## UNSIGNED ADDERS ##
#####################
echo ""
echo "${BLUECOLOR}UNSIGNED ADDERS TESTS${NOCOLOR}"

## HIERARCHICAL 1-BIT ADDERS ##
###############################

# HALF ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_ha.c -o h_ha
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_ha.c"
eval "$H_HA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_ha

# FULL ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_fa.c -o h_fa
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_fa.c"
eval "$H_FA"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_fa

## HIERARCHICAL UNSIGNED ADDERS ##
##################################

# 3-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_rca3.c -o h_u_rca3
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_rca3.c"
eval "$H_U_RCA3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_rca3

# 5-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_rca5.c -o h_u_rca5
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_rca5.c"
eval "$H_U_RCA5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_rca5

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_rca8.c -o h_u_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_rca8.c"
eval "$H_U_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_rca8


########################
## SIGNED MULTIPLIERS ##
########################
echo ""
echo "${BLUECOLOR}SIGNED ADDERS TESTS${NOCOLOR}"

## HIERARCHICAL SIGNED ADDERS ##
################################

# 2-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_rca2.c -o h_s_rca2
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_rca2.c"
eval "$H_S_RCA2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_rca2

# 4-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_rca4.c -o h_s_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_rca4.c"
eval "$H_S_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_rca4

# 6-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_rca6.c -o h_s_rca6
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_rca6.c"
eval "$H_S_RCA6"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_rca6

# 8-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_rca8.c -o h_s_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_rca8.c"
eval "$H_S_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_rca8


##########################
## UNSIGNED MULTIPLIERS ##
##########################
echo ""
echo "${BLUECOLOR}UNSIGNED MULTIPLIERS TESTS${NOCOLOR}"

## HIERARCHICAL UNSIGNED MULTIPLIERS ##
#######################################

# 1-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_arr_mul1.c -o h_u_arr_mul1
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_arr_mul1.c"
eval "$H_U_ARR_MUL1"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_arr_mul1

# 2-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_arr_mul2.c -o h_u_arr_mul2
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_arr_mul2.c"
eval "$H_U_ARR_MUL2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_arr_mul2

# 3-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_arr_mul3.c -o h_u_arr_mul3
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_arr_mul3.c"
eval "$H_U_ARR_MUL3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_arr_mul3

# 5-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_arr_mul5.c -o h_u_arr_mul5
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_arr_mul5.c"
eval "$H_U_ARR_MUL5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_arr_mul5

# 8-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_arr_mul8.c -o h_u_arr_mul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_arr_mul8.c"
eval "$H_U_ARR_MUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_arr_mul8

# 10-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_arr_mul10.c -o h_u_arr_mul10
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_arr_mul10.c"
eval "$H_U_ARR_MUL10"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_arr_mul10

# 2-BIT DADDA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_mul2.c -o h_u_dadda_mul2
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_mul2.c"
eval "$H_U_DADDA_MUL2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_mul2

# 4-BIT DADDA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_mul4.c -o h_u_dadda_mul4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_mul4.c"
eval "$H_U_DADDA_MUL4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_mul4

# 6-BIT DADDA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_mul6.c -o h_u_dadda_mul6
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_mul6.c"
eval "$H_U_DADDA_MUL6"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_mul6

# 8-BIT DADDA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_mul8.c -o h_u_dadda_mul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_mul8.c"
eval "$H_U_DADDA_MUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_mul8


########################
## SIGNED MULTIPLIERS ##
########################
echo ""
echo "${BLUECOLOR}SIGNED MULTIPLIERS TESTS${NOCOLOR}"

## HIERARCHICAL SIGNED MULTIPLIERS ##
#####################################

# 1-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_arr_mul1.c -o h_s_arr_mul1
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_arr_mul1.c"
eval "$H_S_ARR_MUL1"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_arr_mul1

# 2-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_arr_mul2.c -o h_s_arr_mul2
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_arr_mul2.c"
eval "$H_S_ARR_MUL2"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_arr_mul2

# 3-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_arr_mul3.c -o h_s_arr_mul3
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_arr_mul3.c"
eval "$H_S_ARR_MUL3"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_arr_mul3

# 5-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_arr_mul5.c -o h_s_arr_mul5
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_arr_mul5.c"
eval "$H_S_ARR_MUL5"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_arr_mul5

# 8-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_arr_mul8.c -o h_s_arr_mul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_arr_mul8.c"
eval "$H_S_ARR_MUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_arr_mul8

# 10-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_arr_mul10.c -o h_s_arr_mul10
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_arr_mul10.c"
eval "$H_S_ARR_MUL10"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_arr_mul10
