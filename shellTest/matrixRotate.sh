#!/bin/sh

#cols=`cat matrixRotate.txt | head -n 1 | wc -w`
#for i in `seq 1 $cols`
#do
#    awk '{ print $'$i'}' matrixRotate.txt | xargs
#done


awk '{for(i=1; i<=NF; i++) {a[i]=a[i]" "$i;}} END {for(i=1; i<=NF; i++) { print a[i]; } }' matrixRotate.txt | sed 's/^ *//'
