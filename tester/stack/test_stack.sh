#!/usr/bin/env bash

COMPILE="clang++ -Wall -Wextra -Werror -std=c++98"
GREEN="\e[1;32m"
RED="\e[1;31m"
BLUE="\e[1;94m"
EOC="\e[0m"

compile() {
	clang++ $1.cpp -o $1_ft; clang++ $1.cpp -o $1_std -D USING_STD;
./$1_ft > ./stack_log/$1_ft
./$1_std > ./stack_log/$1_std
diff stack_log/$1_ft stack_log/$1_std > stack_diff/$1_diff
}

compile "default" ; rm default_std default_ft
compile "default_copy" ; rm default_copy_std default_copy_ft
compile "relational" ; rm relational_std relational_ft

printf "\n${BLUE}TEST STACK${EOC}\n\n";

test() {
if [ -s stack_diff/$1_diff ] 
then
  printf '%-25s' "$1"; printf "${RED}NOT OK${EOC}\n";
else
  printf '%-25s' "$1"; printf "${GREEN}OK${EOC}\n"; rm stack_diff/$1_diff
fi
}

test default
test default_copy
test relational


