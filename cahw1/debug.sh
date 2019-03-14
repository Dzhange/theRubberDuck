#!/bin/bash
int=1
size=300
while(( $int==1 ))
do
    python gen.py $size
    echo "1"
    ./zg.o $size < ./in.txt 
    echo "2"
    ./wph.o $size < ./in.txt 
    echo "3"
    
    if [ ! -z "$(cmp ./o.txt ./m.txt)" ]
    then
        int=0
    fi
done