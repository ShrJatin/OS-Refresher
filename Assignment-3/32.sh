#! /bin/bash

args=("$@")
len=$#


if [[ $1 == add ]]; then

    sum=${args[1]};
    for  (( i=2;i<len;i++ ));do
        sum=$(( sum + ${args[i]} ))
    done
    echo $sum


elif [[ $1 == sub ]]; then
    
    sub=${args[1]}
    for (( i=2;i<len;i++ ));do
        sub=$(( sub - ${args[i]} ))
    done
    echo $sub


elif [[ $1 == mul ]]; then

    mul=1
    for (( i=0;i<len;i++ ));do
        mul=$(( mul *  ${args[i]} ))
    done
    echo $mul


elif [[ $1 == div ]]; then

    div=${args[1]}
    for  (( i=2;i<len;i++ ));do
        div=`echo "scale=3;$div/${args[i]}" | bc`
    done
    echo $div


elif [[ $1 == exp ]]; then
  
    x=$(( $# - 1 ))

    exp=1
    while [[ $x -gt 0 ]]; do
        exp=$((${args[x]}**$exp))      
        x=$(( $x - 1 ))
    done

    echo $exp


else
    echo "wrong command"
    echo "Usage: ./32.sh <options> <operand1> <operand2>"
    echo "options -- [add, sub, mul, div, exp]"
fi
