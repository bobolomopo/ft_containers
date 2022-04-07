#!/usr/bin/env bash

COMPILE="clang++ -Wall -Wextra -Werror -std=c++98"
GREEN="\e[1;32m"
RED="\e[1;31m"
BLUE="\e[1;94m"
EOC="\e[0m"

compile() {
	clang++ $1.cpp -o $1_ft; clang++ $1.cpp -o $1_std -D USING_STD;
	./$1_ft > ./map_log/$1_ft
	./$1_std > ./map_log/$1_std
	diff map_log/$1_ft map_log/$1_std > map_diff/$1_diff
}

rm_ex() {
	rm "$1_std" "$1_ft"
}

test() {
	if [ -s map_diff/$1_diff ] 
	then
  		printf '%-25s' "$1"; printf "${RED}NOT OK${EOC}\n";
	else
  		printf '%-25s' "$1"; printf "${GREEN}OK${EOC}\n"; rm map_diff/$1_diff
	fi
}

compile "constructor" ; rm_ex constructor
compile "insert" ; rm_ex insert
compile "iterator" ; rm_ex iterator
compile "relationnal" ; rm_ex relationnal

printf "\n${BLUE}TEST MAP${EOC}\n\n";

test constructor
test insert
test iterator
test relationnal
