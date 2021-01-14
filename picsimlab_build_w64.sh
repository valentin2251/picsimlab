#!/bin/bash 
. VERSION
#show errors in color red 
set -o pipefail
cl()("$@" 2>&1>&3|sed $'s,.*,\e[31m&\e[m,'>&2)3>&1

echo -e "\033[1;32m ---------------------- update and install packages ---------------------- \033[0m"
cl sudo apt-get update
cl sudo apt-get -y upgrade
cl sudo apt-get -y install git make mingw-w64-common mingw-w64-x86-64-dev gcc-mingw-w64-x86-64 \
g++-mingw-w64-x86-64 wget unzip
cl wget https://github.com/lcgamboa/picsimlab/releases/download/v${VERSION}/picsimlab_${VERSION}_w64-dev.zip
cl unzip -o picsimlab_${VERSION}_w64-dev.zip
make clean
make FILE=Makefile.cross -j4 $1
