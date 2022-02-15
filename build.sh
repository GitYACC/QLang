#!/bin/bash

value=$(<make/builder)

run="false"
clear="false"
lex="none"

exec=""

error() {
    printf "Usage: build [-c] [-r] -l ...{lex file}\n"
}

while getopts "crl:" flag
do
    case "${flag}" in
        c) clear="true" ;;
        r) run="true" ;;
        l) lex=$OPTARG ;;
        *) error; exit 1 ;;
    esac
done

if [ "$clear" == "true" ]
then
    exec="${exec}clear "
fi

exec="${exec}&& lex ${lex} && gcc -w "

for f in $value 
do 
    exec="${exec}${f} ";
done

exec="${exec}-o prgm "

if [ "$run" == "true" ]
then
    exec="${exec}&& ./prgm"
fi

eval $exec