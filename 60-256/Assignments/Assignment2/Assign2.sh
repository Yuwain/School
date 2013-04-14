#!/bin/bash

if [ $# -ne 1 ]
	then echo "Usage: phone <string>"
else
	while read line
	do
		check=`echo $line | tr -d '(),-'`
		for word in $check
		do
			new=`echo $word | tr '[A-Z]' '[a-z]'`
			look=`echo $1 | tr '[A-Z]' '[a-z]'`
			if [ $look == $new ]
				then echo $line
			fi
		done
	done < phonedata.txt
fi
