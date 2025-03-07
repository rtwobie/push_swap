#!/bin/bash

if [ $# -eq 1 ]; then
	ARGS=$(seq -1000 1000 | shuf -n $1 | tr "\n" " ")
elif [ $# -eq 3 ]; then
	ARGS=$(seq $1 $2 | shuf -n $3 | tr "\n" " ")
fi

printf "./push_swap\n"
./push_swap $ARGS
printf "\n./checker_linux\n"
./push_swap $ARGS | ./checker_linux $ARGS

