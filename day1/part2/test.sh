#!/bin/bash

red='\033[0;31m'
reset='\033[0m'

num=1
for FILE in $(ls tests/*.test | sort -V); do # version sort so it can handle 10.test, which was previously being used as the 2nd test
    ./day1_part2 $FILE | diff - "tests/$num.ok"
    ret=$?
    if [[ $ret -eq 0 ]]; then
        echo passed $num.test
    else 
        echo -e "${red}failed $num.test${reset}"
    fi
    ((num++))
done