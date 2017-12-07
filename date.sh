#!/bin/bash

LANG=C

date=`date '+%Y-%m-%dT%H:%M'`

echo $date

for ((min=1;min<=10;min++));do
date '+%Y-%m-%dT%H:%M' -d ''$min' minute ago'
echo $min
done

