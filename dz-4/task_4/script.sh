#!/usr/bin/env bash
for i in {1..100000}
do
    if [[ $i == *"943"* ]]
    then
        echo $i
    fi
done
