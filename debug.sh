#!/bin/bash
int=1

while(( $int==1 ))
do
    python case.py 10000 > Output.txt
    echo "1"
    ./a.out < ./Output.txt > ./a.txt
    echo "2"
    ./hw3_ref_elf < ./Output.txt > ./b.txt
    echo "3"
    # val = 'cmp ./a.txt ./b.txt'
    if [ ! -z "$(cmp ./a.txt ./b.txt)" ]
    then
        int=0
    fi
done