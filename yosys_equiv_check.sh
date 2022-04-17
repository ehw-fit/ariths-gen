#!/bin/bash

# Script enables formal verification and equivalence of Verilog/BLIF circuit designs 
# using Yosys Open SYnthesis Suite by Claire Xenia Wolf.
# For more information, please visit: http://bygone.clairexen.net/yosys/documentation.html

# Echo script help
help () {
    echo "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"
    echo "–––                                       HELP                                        –––"
    echo "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"
    echo "–  SCRIPT FOR CHECKING FORMAL EQUIVALENCE BETWEEN VERILOG AND BLIF DESIGNS USING YOSYS  –"
    echo
    echo "Input files should have the same name used for corresponding file types filenames as well"
    echo "as for their inner design's top module names."
    echo "Formal verification and equivalence of Verilog/BLIF circuit designs achieved using Yosys"
    echo "Open SYnthesis Suite."
    echo "–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––"
    echo "Input parameters:"
    echo "-h, --help"
    echo "      help information"
    echo "-v 'verilog_file', --verilog_file 'verilog_file'"
    echo "      specifies input Verilog design file"
    echo "-b 'blif_file', --blif_file 'blif_file'"
    echo "      specifies input BLIF design file"
    echo "-m 'method', --mode 'method'"
    echo "      specifies chosen formal equivalence method (sat|equiv)"
    echo "-H, --hier"
    echo "      specifies whether designs are in hierarchical representation (default is flat)"
}

# No input parameters present, echo help and exit.
if [[ "$#" -eq 0 ]]; then
    help
    exit 0
fi

# Defaultly flat designs are considered
HIERARCHICAL=false

# Parsing and extraction of input parameters and their arguments into variables.
while [[ "$#" -gt 0 ]] ; do
    case "$1" in
    "-v" | "--verilog_file")
        if [[ -f "$2" && "$2" == *.v ]]; then
            VERILOG_FILE=$2
        else
            echo "$2 is not a Verilog file!";
            exit 1
        fi
        shift 2;;

    "-b" | "--blif_file")
        if [[ -f "$2" && "$2" == *.blif ]]; then
            BLIF_FILE="$2"
        else
            echo "$2 is not a BLIF file!";
            exit 1
        fi
        shift 2;;
    
    "-m" | "--mode")
        if [[ "$2" == "sat" || "$2" == "equiv" ]]; then
            METHOD="$2"
        else
            echo "$2 is not a supported formal equivalence method!";
            echo
            echo "Type -h | --help for more information."
            exit 1
        fi
        shift 2;;

    "-H" | "--hier")
        HIERARCHICAL=true
        shift 1;;
    "-h" | "--help")
        help
        exit 0;;
    *)
        echo "Unknown input parameter $1!"
        echo
        echo "Type -h | --help for more information."
        exit 1;;
    esac
done

# Check if both files compulsory parameters are set and if they have the same name.
# To proper equiv check both designs top modules must be of same names (assumption that filename == top module name)
if [[ -z "$VERILOG_FILE" || -z "$BLIF_FILE" || -z "$METHOD" ]]; then
    [ -z "$VERILOG_FILE" ] && echo "Missing compulsory Verilog file for comparison!"
    [ -z "$BLIF_FILE" ] && echo "Missing compulsory BLIF file for comparison!"
    [ -z "$METHOD" ] && echo "Missing choice of formal equivalence method!"
    echo
    echo "Type -h | --help for more information."
    exit 1
else
    TOP_MODULE=$(echo $VERILOG_FILE | cut -c1-"$((${#VERILOG_FILE}-2))")
    if [[ "$TOP_MODULE" != $(echo $BLIF_FILE | cut -c1-"$((${#BLIF_FILE}-5))") ]]; then
        echo "Input files have different names! Do they describe the same circuit design?"
        echo "For proper equivalence check, both designs should have the same name used for their filenames and also for their top module designs."
        echo $TOP_MODULE
        echo $(echo $BLIF_FILE | cut -c1-"$((${#BLIF_FILE}-5))")
        echo
        echo "Type -h | --help for more information."
        exit 2    
    fi
fi

# Formal verification with equiv_* for flat designs
if [ "$METHOD" = "equiv" ]; then
    if [ "$HIERARCHICAL" = false ]; then
        yosys -p "
            # Gold design
            read_verilog $VERILOG_FILE
            prep -top $TOP_MODULE
            splitnets -ports;;
            design -stash gold

            # Gate design
            read_blif $BLIF_FILE
            prep -top $TOP_MODULE
            design -stash gate

            # Prove equivalence
            design -copy-from gold -as gold $TOP_MODULE
            design -copy-from gate -as gate $TOP_MODULE
            
            equiv_make gold gate equiv
            hierarchy -top equiv
            equiv_simple
            equiv_status -assert
        "
    # Formal verification with equiv_* for hierarchical designs
    else
        yosys -p "
            # Gold design
            read_verilog $VERILOG_FILE
            prep -top $TOP_MODULE
            flatten
            splitnets -ports;;
            design -stash gold

            # Gate design
            read_blif $BLIF_FILE
            prep -top $TOP_MODULE
            flatten
            splitnets -ports;;
            design -stash gate

            # Prove equivalence
            design -copy-from gold -as gold $TOP_MODULE
            design -copy-from gate -as gate $TOP_MODULE

            equiv_make gold gate equiv
            hierarchy -top equiv
            equiv_simple
            equiv_status -assert
        "
    fi
else
    if [ "$HIERARCHICAL" = false ]; then
        yosys -p "
            # Gold design
            read_verilog $VERILOG_FILE
            prep -top $TOP_MODULE
            splitnets -ports;;
            design -stash gold

            # Gate design
            read_blif $BLIF_FILE
            prep -top $TOP_MODULE
            design -stash gate

            # Prove equivalence
            design -copy-from gold -as gold $TOP_MODULE
            design -copy-from gate -as gate $TOP_MODULE

            miter -equiv -flatten gold gate miter
            hierarchy -top miter
            sat -verify -tempinduct -prove trigger 0
        "
    # Formal verification with equiv_* for hierarchical designs
    else
        yosys -p "
            # Gold design
            read_verilog $VERILOG_FILE
            prep -top $TOP_MODULE
            flatten
            splitnets -ports;;
            design -stash gold

            # Gate design
            read_blif $BLIF_FILE
            prep -top $TOP_MODULE
            flatten
            splitnets -ports;;
            design -stash gate

            # Prove equivalence
            design -copy-from gold -as gold $TOP_MODULE
            design -copy-from gate -as gate $TOP_MODULE

            miter -equiv -flatten gold gate miter
            hierarchy -top miter
            sat -verify -tempinduct -prove trigger 0
        "
    fi
fi
