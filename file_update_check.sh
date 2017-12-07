#!/bin/sh

#LANG=C

TODAY=`date +%Y-%m-%d`
confFile="/aaa/lookup_file.txt"

exec 0<$confFile
while read line
do

# echo AAA = $line

FILED=`ls -al /aaa/$line | awk '{print $6}'`

# echo $TODAY

# echo $FILED

if [ "$TODAY" == "$FILED" ]; then

echo "$line - ok" >> /aaa/lookup_result_$TODAY.txt 

else

echo "$line - fail" >> /aaa/lookup_result_$TODAY.txt

fi

done

OKNUM=`cat /aaa/lookup_result_$TODAY.txt | wc -l`

if [ $OKNUM -eq 10 ]; then

echo "VAL:0"

else

echo "VAL:1"

fi

### Result FILE DEL
find /aaa -name "lookup_file_result*" -mtime +3 -exec rm {} \;
