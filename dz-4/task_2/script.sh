#!/usr/bin/env bash

for dir in $(ls) 
do 
    if echo $dir | grep -q dir
    then
        num=`echo $dir | tr -dc '0-9'` 
        if [ $(( $num % 5 )) -eq 0 ]
        then
            rm -r $dir
        fi
    fi
done
