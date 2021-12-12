#!/bin/sh

# https://adventofcode.com/2021/day/7

crabs=$(<$1 tr , '\n' | wc -l)
half=$(( crabs / 2 ))
p=$(<$1 tr , '\n' | sort -n | sed -n "${half}p")
<$1 tr , '\n' | awk '{ sum += $1 < '$p' ? '$p' - $1 : $1 - '$p' } END { printf("%d fuel\n", sum) }'
