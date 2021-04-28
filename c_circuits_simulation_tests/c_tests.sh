#!/bin/bash

# Colors
# set thanks to: https://linux.101hacks.com/ps1-examples/prompt-color-using-tput/
REDCOLOR="$(tput setaf 1)"
GREENCOLOR="$(tput setaf 2)"
BLUECOLOR="$(tput setaf 4)"
NOCOLOR="$(tput sgr0)"

# Compiler options
C=g++
CFLAGS="-std=c++11 -pedantic -g"
LG_PATH="c_circuits/logic_gates/"
FLAT_ADD_PATH="c_circuits/flat/adders/"
FLAT_MUL_PATH="c_circuits/flat/multipliers/"
FLAT_DIV_PATH="c_circuits/flat/dividers/"
HIER_ADD_PATH="c_circuits/hierarchical/adders/"
HIER_MUL_PATH="c_circuits/hierarchical/multipliers/"
HIER_DIV_PATH="c_circuits/hierarchical/dividers/"

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
F_U_RCA4="./f_u_rca4 2>/dev/null"
F_U_RCA8="./f_u_rca8 2>/dev/null"
F_U_PG_RCA4="./f_u_pg_rca4 2>/dev/null"
F_U_PG_RCA8="./f_u_pg_rca8 2>/dev/null"
F_U_CLA4="./f_u_cla4 2>/dev/null"
F_U_CLA8="./f_u_cla8 2>/dev/null"
F_U_CSKA4="./f_u_cska4 2>/dev/null"
F_U_CSKA8="./f_u_cska8 2>/dev/null"

H_U_RCA4="./h_u_rca4 2>/dev/null"
H_U_RCA8="./h_u_rca8 2>/dev/null"
H_U_PG_RCA4="./h_u_pg_rca4 2>/dev/null"
H_U_PG_RCA8="./h_u_pg_rca8 2>/dev/null"
H_U_CLA4="./h_u_cla4 2>/dev/null"
H_U_CLA8="./h_u_cla8 2>/dev/null"
H_U_CSKA4="./h_u_cska4 2>/dev/null"
H_U_CSKA8="./h_u_cska8 2>/dev/null"

# Signed
F_S_RCA4="./f_s_rca4 2>/dev/null"
F_S_RCA8="./f_s_rca8 2>/dev/null"
F_S_PG_RCA4="./f_s_pg_rca4 2>/dev/null"
F_S_PG_RCA8="./f_s_pg_rca8 2>/dev/null"
F_S_CLA4="./f_s_cla4 2>/dev/null"
F_S_CLA8="./f_s_cla8 2>/dev/null"
F_S_CSKA4="./f_s_cska4 2>/dev/null"
F_S_CSKA8="./f_s_cska8 2>/dev/null"

H_S_RCA4="./h_s_rca4 2>/dev/null"
H_S_RCA8="./h_s_rca8 2>/dev/null"
H_S_PG_RCA4="./h_s_pg_rca4 2>/dev/null"
H_S_PG_RCA8="./h_s_pg_rca8 2>/dev/null"
H_S_CLA4="./h_s_cla4 2>/dev/null"
H_S_CLA8="./h_s_cla8 2>/dev/null"
H_S_CSKA4="./h_s_cska4 2>/dev/null"
H_S_CSKA8="./h_s_cska8 2>/dev/null"

# Multipliers #
# Unsigned
F_U_ARRMUL4="./f_u_arrmul4 2>/dev/null"
F_U_ARRMUL8="./f_u_arrmul8 2>/dev/null"

F_U_DADDA_RCA4="./f_u_dadda_rca4 2>/dev/null"
F_U_DADDA_RCA8="./f_u_dadda_rca8 2>/dev/null"
F_U_DADDA_PG_RCA4="./f_u_dadda_pg_rca4 2>/dev/null"
F_U_DADDA_PG_RCA8="./f_u_dadda_pg_rca8 2>/dev/null"
F_U_DADDA_CSKA4="./f_u_dadda_cska4 2>/dev/null"
F_U_DADDA_CSKA8="./f_u_dadda_cska8 2>/dev/null"
F_U_DADDA_CLA4="./f_u_dadda_cla4 2>/dev/null"
F_U_DADDA_CLA8="./f_u_dadda_cla8 2>/dev/null"

F_U_WALLACE_RCA4="./f_u_wallace_rca4 2>/dev/null"
F_U_WALLACE_RCA8="./f_u_wallace_rca8 2>/dev/null"
F_U_WALLACE_PG_RCA4="./f_u_wallace_pg_rca4 2>/dev/null"
F_U_WALLACE_PG_RCA8="./f_u_wallace_pg_rca8 2>/dev/null"
F_U_WALLACE_CSKA4="./f_u_wallace_cska4 2>/dev/null"
F_U_WALLACE_CSKA8="./f_u_wallace_cska8 2>/dev/null"
F_U_WALLACE_CLA4="./f_u_wallace_cla4 2>/dev/null"
F_U_WALLACE_CLA8="./f_u_wallace_cla8 2>/dev/null"


H_U_ARRMUL4="./h_u_arrmul4 2>/dev/null"
H_U_ARRMUL8="./h_u_arrmul8 2>/dev/null"

H_U_DADDA_RCA4="./h_u_dadda_rca4 2>/dev/null"
H_U_DADDA_RCA8="./h_u_dadda_rca8 2>/dev/null"
H_U_DADDA_PG_RCA4="./h_u_dadda_pg_rca4 2>/dev/null"
H_U_DADDA_PG_RCA8="./h_u_dadda_pg_rca8 2>/dev/null"
H_U_DADDA_CSKA4="./h_u_dadda_cska4 2>/dev/null"
H_U_DADDA_CSKA8="./h_u_dadda_cska8 2>/dev/null"
H_U_DADDA_CLA4="./h_u_dadda_cla4 2>/dev/null"
H_U_DADDA_CLA8="./h_u_dadda_cla8 2>/dev/null"

H_U_WALLACE_RCA4="./h_u_wallace_rca4 2>/dev/null"
H_U_WALLACE_RCA8="./h_u_wallace_rca8 2>/dev/null"
H_U_WALLACE_PG_RCA4="./h_u_wallace_pg_rca4 2>/dev/null"
H_U_WALLACE_PG_RCA8="./h_u_wallace_pg_rca8 2>/dev/null"
H_U_WALLACE_CSKA4="./h_u_wallace_cska4 2>/dev/null"
H_U_WALLACE_CSKA8="./h_u_wallace_cska8 2>/dev/null"
H_U_WALLACE_CLA4="./h_u_wallace_cla4 2>/dev/null"
H_U_WALLACE_CLA8="./h_u_wallace_cla8 2>/dev/null"


# Signed
F_S_ARRMUL4="./f_s_arrmul4 2>/dev/null"
F_S_ARRMUL8="./f_s_arrmul8 2>/dev/null"

F_S_DADDA_RCA4="./f_s_dadda_rca4 2>/dev/null"
F_S_DADDA_RCA8="./f_s_dadda_rca8 2>/dev/null"
F_S_DADDA_PG_RCA4="./f_s_dadda_pg_rca4 2>/dev/null"
F_S_DADDA_PG_RCA8="./f_s_dadda_pg_rca8 2>/dev/null"
F_S_DADDA_CSKA4="./f_s_dadda_cska4 2>/dev/null"
F_S_DADDA_CSKA8="./f_s_dadda_cska8 2>/dev/null"
F_S_DADDA_CLA4="./f_s_dadda_cla4 2>/dev/null"
F_S_DADDA_CLA8="./f_s_dadda_cla8 2>/dev/null"

F_S_WALLACE_RCA4="./f_s_wallace_rca4 2>/dev/null"
F_S_WALLACE_RCA8="./f_s_wallace_rca8 2>/dev/null"
F_S_WALLACE_PG_RCA4="./f_s_wallace_pg_rca4 2>/dev/null"
F_S_WALLACE_PG_RCA8="./f_s_wallace_pg_rca8 2>/dev/null"
F_S_WALLACE_CSKA4="./f_s_wallace_cska4 2>/dev/null"
F_S_WALLACE_CSKA8="./f_s_wallace_cska8 2>/dev/null"
F_S_WALLACE_CLA4="./f_s_wallace_cla4 2>/dev/null"
F_S_WALLACE_CLA8="./f_s_wallace_cla8 2>/dev/null"


H_S_ARRMUL4="./h_s_arrmul4 2>/dev/null"
H_S_ARRMUL8="./h_s_arrmul8 2>/dev/null"

H_S_DADDA_RCA4="./h_s_dadda_rca4 2>/dev/null"
H_S_DADDA_RCA8="./h_s_dadda_rca8 2>/dev/null"
H_S_DADDA_PG_RCA4="./h_s_dadda_pg_rca4 2>/dev/null"
H_S_DADDA_PG_RCA8="./h_s_dadda_pg_rca8 2>/dev/null"
H_S_DADDA_CSKA4="./h_s_dadda_cska4 2>/dev/null"
H_S_DADDA_CSKA8="./h_s_dadda_cska8 2>/dev/null"
H_S_DADDA_CLA4="./h_s_dadda_cla4 2>/dev/null"
H_S_DADDA_CLA8="./h_s_dadda_cla8 2>/dev/null"

H_S_WALLACE_RCA4="./h_s_wallace_rca4 2>/dev/null"
H_S_WALLACE_RCA8="./h_s_wallace_rca8 2>/dev/null"
H_S_WALLACE_PG_RCA4="./h_s_wallace_pg_rca4 2>/dev/null"
H_S_WALLACE_PG_RCA8="./h_s_wallace_pg_rca8 2>/dev/null"
H_S_WALLACE_CSKA4="./h_s_wallace_cska4 2>/dev/null"
H_S_WALLACE_CSKA8="./h_s_wallace_cska8 2>/dev/null"
H_S_WALLACE_CLA4="./h_s_wallace_cla4 2>/dev/null"
H_S_WALLACE_CLA8="./h_s_wallace_cla8 2>/dev/null"

# Dividers #
F_ARRDIV4="./f_arrdiv4 2>/dev/null"
F_ARRDIV8="./f_arrdiv8 2>/dev/null"

H_ARRDIV4="./h_arrdiv4 2>/dev/null"
H_ARRDIV8="./h_arrdiv8 2>/dev/null"


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

# 4-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_rca4.c -o f_u_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_rca4.c"
eval "$F_U_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_rca4

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

# 4-BIT PG RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_pg_rca4.c -o f_u_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_pg_rca4.c"
eval "$F_U_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_pg_rca4

# 8-BIT PG RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_pg_rca8.c -o f_u_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_pg_rca8.c"
eval "$F_U_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_pg_rca8

# 4-BIT CARRY-LOOKAHEAD ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_cla4.c -o f_u_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_cla4.c"
eval "$F_U_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_cla4

# 8-BIT CARRY-LOOKAHEAD ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_cla8.c -o f_u_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_cla8.c"
eval "$F_U_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_cla8

# 4-BIT CARRY SKIP ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_cska4.c -o f_u_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_cska4.c"
eval "$F_U_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_cska4

# 8-BIT CARRY SKIP ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_u_cska8.c -o f_u_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_cska8.c"
eval "$F_U_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_cska8

echo ""
echo "${BLUECOLOR}SIGNED ADDERS TESTS${NOCOLOR}"

## FLAT SIGNED ADDERS ##
########################

# 4-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_rca4.c -o f_s_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_rca4.c"
eval "$F_S_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_rca4

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

# 4-BIT PG RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_pg_rca4.c -o f_s_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_pg_rca4.c"
eval "$F_S_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_pg_rca4

# 8-BIT PG RIPPLE CARRY ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_pg_rca8.c -o f_s_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_pg_rca8.c"
eval "$F_S_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_pg_rca8

# 4-BIT CARRY-LOOKAHEAD ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_cla4.c -o f_s_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_cla4.c"
eval "$F_S_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_cla4

# 8-BIT CARRY-LOOKAHEAD ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_cla8.c -o f_s_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_cla8.c"
eval "$F_S_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_cla8

# 4-BIT CARRY SKIP ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_cska4.c -o f_s_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_cska4.c"
eval "$F_S_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_cska4

# 8-BIT CARRY SKIP ADDER
${C} ${CFLAGS} ${FLAT_ADD_PATH}f_s_cska8.c -o f_s_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_cska8.c"
eval "$F_S_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_cska8

##########################
## UNSIGNED MULTIPLIERS ##
##########################
echo ""
echo "${BLUECOLOR}UNSIGNED MULTIPLIERS TESTS${NOCOLOR}"

## FLAT UNSIGNED MULTIPLIERS ##
###############################

# 4-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_arrmul4.c -o f_u_arrmul4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_arrmul4.c"
eval "$F_U_ARRMUL4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_arrmul4

# 8-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_arrmul8.c -o f_u_arrmul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_arrmul8.c"
eval "$F_U_ARRMUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_arrmul8

# 4-BIT DADDA-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_rca4.c -o f_u_dadda_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_rca4.c"
eval "$F_U_DADDA_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_rca4

# 8-BIT DADDA-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_rca8.c -o f_u_dadda_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_rca8.c"
eval "$F_U_DADDA_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_rca8

# 4-BIT DADDA-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_pg_rca4.c -o f_u_dadda_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_pg_rca4.c"
eval "$F_U_DADDA_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_pg_rca4

# 8-BIT DADDA-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_pg_rca8.c -o f_u_dadda_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_pg_rca8.c"
eval "$F_U_DADDA_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_pg_rca8

# 4-BIT DADDA-CLA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_cla4.c -o f_u_dadda_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_cla4.c"
eval "$F_U_DADDA_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_cla4

# 8-BIT DADDA-CLA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_cla8.c -o f_u_dadda_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_cla8.c"
eval "$F_U_DADDA_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_cla8

# 4-BIT DADDA-CSKA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_cska4.c -o f_u_dadda_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_cska4.c"
eval "$F_U_DADDA_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_cska4

# 8-BIT DADDA-CSKA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_dadda_cska8.c -o f_u_dadda_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_dadda_cska8.c"
eval "$F_U_DADDA_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_dadda_cska8

# 4-BIT WALLACE-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_wallace_rca4.c -o f_u_wallace_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_wallace_rca4.c"
eval "$F_U_WALLACE_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_wallace_rca4

# 8-BIT WALLACE-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_wallace_rca8.c -o f_u_wallace_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_wallace_rca8.c"
eval "$F_U_WALLACE_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_wallace_rca8

# 4-BIT WALLACE-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_wallace_pg_rca4.c -o f_u_wallace_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_wallace_pg_rca4.c"
eval "$F_U_WALLACE_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_wallace_pg_rca4

# 8-BIT WALLACE-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_wallace_pg_rca8.c -o f_u_wallace_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_wallace_pg_rca8.c"
eval "$F_U_WALLACE_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_wallace_pg_rca8

# 4-BIT WALLACE-CLA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_wallace_cla4.c -o f_u_wallace_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_wallace_cla4.c"
eval "$F_U_WALLACE_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_wallace_cla4

# 8-BIT WALLACE-CLA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_wallace_cla8.c -o f_u_wallace_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_wallace_cla8.c"
eval "$F_U_WALLACE_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_wallace_cla8

# 4-BIT WALLACE-CSKA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_wallace_cska4.c -o f_u_wallace_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_wallace_cska4.c"
eval "$F_U_WALLACE_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_wallace_cska4

# 8-BIT WALLACE-CSKA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_u_wallace_cska8.c -o f_u_wallace_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_u_wallace_cska8.c"
eval "$F_U_WALLACE_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_u_wallace_cska8

########################
## SIGNED MULTIPLIERS ##
########################
echo ""
echo "${BLUECOLOR}SIGNED MULTIPLIERS TESTS${NOCOLOR}"

## FLAT SIGNED MULTIPLIERS ##
###############################

# 4-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_arrmul4.c -o f_s_arrmul4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_arrmul4.c"
eval "$F_S_ARRMUL4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_arrmul4

# 8-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_arrmul8.c -o f_s_arrmul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_arrmul8.c"
eval "$F_S_ARRMUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_arrmul8

# 4-BIT DADDA-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_dadda_rca4.c -o f_s_dadda_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_dadda_rca4.c"
eval "$F_S_DADDA_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_dadda_rca4

# 8-BIT DADDA-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_dadda_rca8.c -o f_s_dadda_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_dadda_rca8.c"
eval "$F_S_DADDA_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_dadda_rca8

# 4-BIT DADDA-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_dadda_pg_rca4.c -o f_s_dadda_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_dadda_pg_rca4.c"
eval "$F_S_DADDA_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_dadda_pg_rca4

# 8-BIT DADDA-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_dadda_pg_rca8.c -o f_s_dadda_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_dadda_pg_rca8.c"
eval "$F_S_DADDA_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_dadda_pg_rca8

# 4-BIT DADDA-CLA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_dadda_cla4.c -o f_s_dadda_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_dadda_cla4.c"
eval "$F_S_DADDA_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_dadda_cla4

# 8-BIT DADDA-CLA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_dadda_cla8.c -o f_s_dadda_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_dadda_cla8.c"
eval "$F_S_DADDA_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_dadda_cla8

# 4-BIT DADDA-CSKA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_dadda_cska4.c -o f_s_dadda_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_dadda_cska4.c"
eval "$F_S_DADDA_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_dadda_cska4

# 8-BIT DADDA-CSKA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_dadda_cska8.c -o f_s_dadda_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_dadda_cska8.c"
eval "$F_S_DADDA_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_dadda_cska8

# 4-BIT WALLACE-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_wallace_rca4.c -o f_s_wallace_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_wallace_rca4.c"
eval "$F_S_WALLACE_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_wallace_rca4

# 8-BIT WALLACE-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_wallace_rca8.c -o f_s_wallace_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_wallace_rca8.c"
eval "$F_S_WALLACE_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_wallace_rca8

# 4-BIT WALLACE-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_wallace_pg_rca4.c -o f_s_wallace_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_wallace_pg_rca4.c"
eval "$F_S_WALLACE_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_wallace_pg_rca4

# 8-BIT WALLACE-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_wallace_pg_rca8.c -o f_s_wallace_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_wallace_pg_rca8.c"
eval "$F_S_WALLACE_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_wallace_pg_rca8

# 4-BIT WALLACE-CLA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_wallace_cla4.c -o f_s_wallace_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_wallace_cla4.c"
eval "$F_S_WALLACE_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_wallace_cla4

# 8-BIT WALLACE-CLA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_wallace_cla8.c -o f_s_wallace_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_wallace_cla8.c"
eval "$F_S_WALLACE_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_wallace_cla8

# 4-BIT WALLACE-CSKA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_wallace_cska4.c -o f_s_wallace_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_wallace_cska4.c"
eval "$F_S_WALLACE_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_wallace_cska4

# 8-BIT WALLACE-CSKA MULTIPLIER
${C} ${CFLAGS} ${FLAT_MUL_PATH}f_s_wallace_cska8.c -o f_s_wallace_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_s_wallace_cska8.c"
eval "$F_S_WALLACE_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_s_wallace_cska8


#######################
## UNSIGNED DIVIDERS ##
#######################
echo ""
echo "${BLUECOLOR}UNSIGNED DIVIDERS TESTS${NOCOLOR}"

## FLAT UNSIGNED DIVIDERS ##
############################

# 4-BIT ARRAY DIVIDER
${C} ${CFLAGS} ${FLAT_DIV_PATH}f_arrdiv4.c -o f_arrdiv4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_arrdiv4.c"
eval "$F_ARRDIV4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_arrdiv4

# 8-BIT ARRAY DIVIDER
${C} ${CFLAGS} ${FLAT_DIV_PATH}f_arrdiv8.c -o f_arrdiv8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: f_arrdiv8.c"
eval "$F_ARRDIV8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm f_arrdiv8


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

# 4-BIT RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_rca4.c -o h_u_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_rca4.c"
eval "$H_U_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_rca4

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

# 4-BIT PG RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_pg_rca4.c -o h_u_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_pg_rca4.c"
eval "$H_U_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_pg_rca4

# 8-BIT PG RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_pg_rca8.c -o h_u_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_pg_rca8.c"
eval "$H_U_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_pg_rca8

# 4-BIT CARRY-LOOKAHEAD ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_cla4.c -o h_u_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_cla4.c"
eval "$H_U_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_cla4

# 8-BIT CARRY-LOOKAHEAD ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_cla8.c -o h_u_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_cla8.c"
eval "$H_U_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_cla8

# 4-BIT CARRY SKIP ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_cska4.c -o h_u_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_cska4.c"
eval "$H_U_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_cska4

# 8-BIT CARRY SKIP ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_u_cska8.c -o h_u_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_cska8.c"
eval "$H_U_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_cska8

###################
## SIGNED ADDERS ##
###################
echo ""
echo "${BLUECOLOR}SIGNED ADDERS TESTS${NOCOLOR}"

## HIERARCHICAL SIGNED ADDERS ##
################################

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

# 4-BIT PG RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_pg_rca4.c -o h_s_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_pg_rca4.c"
eval "$H_S_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_pg_rca4

# 8-BIT PG RIPPLE CARRY ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_pg_rca8.c -o h_s_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_pg_rca8.c"
eval "$H_S_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_pg_rca8

# 4-BIT CARRY-LOOKAHEAD ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_cla4.c -o h_s_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_cla4.c"
eval "$H_S_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_cla4

# 8-BIT CARRY-LOOKAHEAD ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_cla8.c -o h_s_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_cla8.c"
eval "$H_S_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_cla8

# 4-BIT CARRY SKIP ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_cska4.c -o h_s_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_cska4.c"
eval "$H_S_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_cska4

# 8-BIT CARRY SKIP ADDER
${C} ${CFLAGS} ${HIER_ADD_PATH}h_s_cska8.c -o h_s_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_cska8.c"
eval "$H_S_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_cska8

##########################
## UNSIGNED MULTIPLIERS ##
##########################
echo ""
echo "${BLUECOLOR}UNSIGNED MULTIPLIERS TESTS${NOCOLOR}"

## HIERARCHICAL UNSIGNED MULTIPLIERS ##
#######################################

# 4-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_arrmul4.c -o h_u_arrmul4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_arrmul4.c"
eval "$H_U_ARRMUL4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_arrmul4

# 8-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_arrmul8.c -o h_u_arrmul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_arrmul8.c"
eval "$H_U_ARRMUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_arrmul8

# 4-BIT DADDA-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_rca4.c -o h_u_dadda_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_rca4.c"
eval "$H_U_DADDA_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_rca4

# 8-BIT DADDA-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_rca8.c -o h_u_dadda_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_rca8.c"
eval "$H_U_DADDA_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_rca8

# 4-BIT DADDA-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_pg_rca4.c -o h_u_dadda_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_pg_rca4.c"
eval "$H_U_DADDA_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_pg_rca4

# 8-BIT DADDA-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_pg_rca8.c -o h_u_dadda_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_pg_rca8.c"
eval "$H_U_DADDA_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_pg_rca8

# 4-BIT DADDA-CLA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_cla4.c -o h_u_dadda_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_cla4.c"
eval "$H_U_DADDA_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_cla4

# 8-BIT DADDA-CLA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_cla8.c -o h_u_dadda_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_cla8.c"
eval "$H_U_DADDA_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_cla8

# 4-BIT DADDA-CSKA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_cska4.c -o h_u_dadda_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_cska4.c"
eval "$H_U_DADDA_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_cska4

# 8-BIT DADDA-CSKA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_dadda_cska8.c -o h_u_dadda_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_dadda_cska8.c"
eval "$H_U_DADDA_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_dadda_cska8

# 4-BIT WALLACE-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_wallace_rca4.c -o h_u_wallace_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_wallace_rca4.c"
eval "$H_U_WALLACE_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_wallace_rca4

# 8-BIT WALLACE-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_wallace_rca8.c -o h_u_wallace_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_wallace_rca8.c"
eval "$H_U_WALLACE_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_wallace_rca8

# 4-BIT WALLACE-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_wallace_pg_rca4.c -o h_u_wallace_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_wallace_pg_rca4.c"
eval "$H_U_WALLACE_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_wallace_pg_rca4

# 8-BIT WALLACE-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_wallace_pg_rca8.c -o h_u_wallace_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_wallace_pg_rca8.c"
eval "$H_U_WALLACE_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_wallace_pg_rca8

# 4-BIT WALLACE-CLA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_wallace_cla4.c -o h_u_wallace_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_wallace_cla4.c"
eval "$H_U_WALLACE_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_wallace_cla4

# 8-BIT WALLACE-CLA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_wallace_cla8.c -o h_u_wallace_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_wallace_cla8.c"
eval "$H_U_WALLACE_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_wallace_cla8

# 4-BIT WALLACE-CSKA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_wallace_cska4.c -o h_u_wallace_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_wallace_cska4.c"
eval "$H_U_WALLACE_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_wallace_cska4

# 8-BIT WALLACE-CSKA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_u_wallace_cska8.c -o h_u_wallace_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_u_wallace_cska8.c"
eval "$H_U_WALLACE_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_u_wallace_cska8

########################
## SIGNED MULTIPLIERS ##
########################
echo ""
echo "${BLUECOLOR}SIGNED MULTIPLIERS TESTS${NOCOLOR}"

## HIERARCHICAL SIGNED MULTIPLIERS ##
#####################################

# 4-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_arrmul4.c -o h_s_arrmul4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_arrmul4.c"
eval "$H_S_ARRMUL4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_arrmul4

# 8-BIT ARRAY MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_arrmul8.c -o h_s_arrmul8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_arrmul8.c"
eval "$H_S_ARRMUL8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_arrmul8

# 4-BIT DADDA-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_dadda_rca4.c -o h_s_dadda_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_dadda_rca4.c"
eval "$H_S_DADDA_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_dadda_rca4

# 8-BIT DADDA-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_dadda_rca8.c -o h_s_dadda_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_dadda_rca8.c"
eval "$H_S_DADDA_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_dadda_rca8

# 4-BIT DADDA-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_dadda_pg_rca4.c -o h_s_dadda_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_dadda_pg_rca4.c"
eval "$H_S_DADDA_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_dadda_pg_rca4

# 8-BIT DADDA-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_dadda_pg_rca8.c -o h_s_dadda_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_dadda_pg_rca8.c"
eval "$H_S_DADDA_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_dadda_pg_rca8

# 4-BIT DADDA-CLA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_dadda_cla4.c -o h_s_dadda_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_dadda_cla4.c"
eval "$H_S_DADDA_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_dadda_cla4

# 8-BIT DADDA-CLA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_dadda_cla8.c -o h_s_dadda_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_dadda_cla8.c"
eval "$H_S_DADDA_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_dadda_cla8

# 4-BIT DADDA-CSKA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_dadda_cska4.c -o h_s_dadda_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_dadda_cska4.c"
eval "$H_S_DADDA_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_dadda_cska4

# 8-BIT DADDA-CSKA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_dadda_cska8.c -o h_s_dadda_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_dadda_cska8.c"
eval "$H_S_DADDA_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_dadda_cska8

# 4-BIT WALLACE-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_wallace_rca4.c -o h_s_wallace_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_wallace_rca4.c"
eval "$H_S_WALLACE_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_wallace_rca4

# 8-BIT WALLACE-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_wallace_rca8.c -o h_s_wallace_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_wallace_rca8.c"
eval "$H_S_WALLACE_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_wallace_rca8

# 4-BIT WALLACE-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_wallace_pg_rca4.c -o h_s_wallace_pg_rca4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_wallace_pg_rca4.c"
eval "$H_S_WALLACE_PG_RCA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_wallace_pg_rca4

# 8-BIT WALLACE-PG-RCA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_wallace_pg_rca8.c -o h_s_wallace_pg_rca8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_wallace_pg_rca8.c"
eval "$H_S_WALLACE_PG_RCA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_wallace_pg_rca8

# 4-BIT WALLACE-CLA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_wallace_cla4.c -o h_s_wallace_cla4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_wallace_cla4.c"
eval "$H_S_WALLACE_CLA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_wallace_cla4

# 8-BIT WALLACE-CLA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_wallace_cla8.c -o h_s_wallace_cla8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_wallace_cla8.c"
eval "$H_S_WALLACE_CLA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_wallace_cla8

# 4-BIT WALLACE-CSKA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_wallace_cska4.c -o h_s_wallace_cska4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_wallace_cska4.c"
eval "$H_S_WALLACE_CSKA4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_wallace_cska4

# 8-BIT WALLACE-CSKA MULTIPLIER
${C} ${CFLAGS} ${HIER_MUL_PATH}h_s_wallace_cska8.c -o h_s_wallace_cska8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_s_wallace_cska8.c"
eval "$H_S_WALLACE_CSKA8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_s_wallace_cska8

#######################
## UNSIGNED DIVIDERS ##
#######################
echo ""
echo "${BLUECOLOR}UNSIGNED DIVIDER TESTS${NOCOLOR}"

## HIERARCHICAL UNSIGNED DIVIDERS ##
####################################

# 4-BIT ARRAY DIVIDER
${C} ${CFLAGS} ${HIER_DIV_PATH}h_arrdiv4.c -o h_arrdiv4
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_arrdiv4.c"
eval "$H_ARRDIV4"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_arrdiv4

# 8-BIT ARRAY DIVIDER
${C} ${CFLAGS} ${HIER_DIV_PATH}h_arrdiv8.c -o h_arrdiv8
TEST_NUM=$((TEST_NUM+1))
echo "TEST_$TEST_NUM: h_arrdiv8.c"
eval "$H_ARRDIV8"
if [ "$?" -eq 0 ] ; then
    echo "${GREENCOLOR}PASSED${NOCOLOR}"
else
    echo "${REDCOLOR}FAILED${NOCOLOR}"
fi
rm h_arrdiv8