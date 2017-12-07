#!/bin/sh

confFile="file.txt"

# Check if file exists
if [ ! -f $confFile ]; then
echo "$confFile : does not exits"
exit 1
elif [ ! -f $confFile ]; then
echo "$confFile : can not read"
exit2
fi

exec 0<$confFile
while read line
do

# echo AAA = $line

ls -al $line

if [$? -eq 0]; then
echo "$line - ok" >> result.txt
else
echo "$line - fail" >> result.txt
fi
done
