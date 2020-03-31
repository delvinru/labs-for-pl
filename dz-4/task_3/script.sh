#!/usr/bin/env bash

echo "[+] Склейка файлов началась"
for file in `ls`
do
    if [ "$file" == "sum_out.txt"  ]
    then
        echo "[-] Файл sum_out.txt уже существует. Удалите его, чтобы скрипт заработал."
        exit
    fi
    if [[ $file == *".txt"* ]]
    then
        cat $file >> sum_out.txt
    fi
done
echo "[+] Склейка файлов завершена"

