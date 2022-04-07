#!/usr/bin/env bash

COMPILE="clang++ -Wall -Wextra -Werror -std=c++98"
GREEN="\e[1;32m"
RED="\e[1;31m"
BLUE="\e[1;94m"
EOC="\e[0m"

compile() {
	clang++ $1.cpp -o $1_ft; clang++ $1.cpp -o $1_std -D USING_STD;
	./$1_ft > ./vector_log/$1_ft
	./$1_std > ./vector_log/$1_std
	diff vector_log/$1_ft vector_log/$1_std > vector_diff/$1_diff
}

rm_ex() {
	rm "$1_std" "$1_ft"
}

test() {
	if [ -s vector_diff/$1_diff ] 
	then
  		printf '%-25s' "$1"; printf "${RED}NOT OK${EOC}\n";
	else
  		printf '%-25s' "$1"; printf "${GREEN}OK${EOC}\n"; rm vector_diff/$1_diff
	fi
}

compile "capacity" ; rm_ex capacity
compile "construct" ; rm_ex construct
compile "iterator" ; rm_ex iterator
compile "relationnal_ope" ; rm_ex relationnal_ope

printf "\n${BLUE}TEST VECTOR${EOC}\n\n";

test capacity
test construct
test iterator
test relationnal_ope
