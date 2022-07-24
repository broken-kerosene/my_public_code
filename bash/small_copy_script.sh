#!/bin/bash

F_PATH=$1
SUFIX=$2
BACKUP=$3
TAR_NAME=$4
MY_PWD=$(pwd)

mkdir $BACKUP
cd $F_PATH
for i in $(find . -depth -type d)
do
#	if [[ $i == "./$BACKUP" ]]
#	then
#		continue
#	fi
	mkdir --parents $MY_PWD/$BACKUP/$i
	cd $i
	cp *.$SUFIX $MY_PWD/$BACKUP/$i 2> /dev/null
	cd $F_PATH
done
cd $MY_PWD/$BACKUP
tar -czf $TAR_NAME . 2> /dev/null 
mv $TAR_NAME $MY_PWD
cd $MY_PWD
echo "done"

