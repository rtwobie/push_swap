#!/bin/bash

# Check the first argument passed to the script and run the corresponding command
case $1 in
    1)
        ./push_swap	1 3 5 -2 -1 2 6
        ;;
    2)
        ./push_swap	5 1 3 -2 -1 2 6
        ;;
    3)
        ./push_swap	3 5 1 -2 -1 2 6
        ;;
    4)
        gdb --args ./push_swap	1 3 5 -2 -1 2 6
        ;;
    5)
        gdb --args ./push_swap	5 1 3 -2 -1 2 6
        ;;
    6)
        gdb --args ./push_swap	3 5 1 -2 -1 2 6
        ;;
    *)
		echo "Invalid Option"
        ;;
esac

sed -n "${1}p" optestsolution
