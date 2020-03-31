#!/usr/bin/env bash
echo -e "\e[1;32m[+] \e[0m$0 script for compile C programm"

if test -f "$1"; then
    echo -e "\e[1;32m[+] \e[0mFile $1 exist"
elif [ -z "$1" ];then
    echo -e "\e[1;33m[!] \e[0mUsage: $0 file_name"
    exit
else
    echo -e "\e[1;31m[-] \e[0mFile $1 not exist. Plz check file"
    exit
fi

echo -e "\e[1;32m[+] \e[0mStarting compilation.."
if gcc $1;then
    echo -e "\e[1;32m[+] \e[0mCompilation success! Programm name: a.out"
    echo -e "\e[1;32m[+] \e[0mStarting a.out"
    echo -e "\e[1;32m[+] \e[0m$0 finished\n"
    ./a.out
else
    echo -e "\e[1;31m[-] \e[0mSomething went wrong"
    exit
fi

