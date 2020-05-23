#!/bin/bash

num=5

echo "Enter your Salary."
read Salary
echo "Enter your Years of Service."
read Service

if [ $Service -ge $num ]
then
val=`expr $Salary \* 5`
result=`expr $val / 100`
 echo "Congratulation! You got the Bonus of : $result"
else
 echo "Sorry You are not eligible for the Bonus..."
fi
