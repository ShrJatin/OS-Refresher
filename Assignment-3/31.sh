#! /bin/bash

if [ $# -ne 3 ]
then
    echo "wrong command"
    echo "Usage: ./31.sh <Date(dd)> <Month(mm)> <Year(yyyy)>"
    echo "Command Example: for 5th oct 2020 ==>$0 5 10 2020" 


elif [[ $3 -le 9999  && $3 -ge 0001 ]]
then
	

    if [[ $2 -le 12  && $3 -ge 1 ]]
  	then
  

		if [[ $1 -le 31  && $1 -ge 1 &&  $2 -eq 1  ||  $2 -eq 3  ||  $2 -eq 5  ||  $2 -eq 7  ||  $2 -eq 8  ||  $2 -eq 10  ||  $2 -eq 12 ]]
		then
			cal $2 $3


		elif [[ $1 -le 30  && $1 -ge 1  &&  $2 -eq 4  ||  $2 -eq 6  ||  $2 -eq 9  ||  $2 -eq 11 ]]
		then
		 	cal $2 $3


		elif [[ $1 -le 28 && $1 -ge 1 && $2 -eq 2 ]]
		then
		 	cal $2 $3


		elif [[ $1 -eq 29 && $2 -eq 2 && $3%400 -eq 0 ||  $3%4 -eq 0 && $3%100 -ne 0 ]]
		then
			cal $2 $3

		else
		 	echo "Date is invalid"
		 	echo "Check if date is valid as per month"
		 	echo "Usage: ./31.sh <Date(dd)> <Month(mm)> <Year(yyyy)>"
		fi


    else
    	echo "Month is invalid"
       	echo "cal: $2 is neither a month number (1..12) nor a name"
        echo "Usage: ./31.sh <Date(dd)> <Month(mm)> <Year(yyyy)>"
    fi


else      
	echo "Year is invalid"
	echo "cal: year $3 not in range (1.. 9999)"
	echo "Usage: ./31.sh <Date(dd)> <Month(mm)> <Year(yyyy)>"
fi
