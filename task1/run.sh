#!/bin/bash

ext=$2
cppath=$3
cpname=$4

mkdir $cppath

find $1 -name *.$ext -exec cp --backup=t {} ./$cppath \;

tar -zcf $cpname ./$cppath

echo "done"
