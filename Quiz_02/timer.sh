#!/bin/bash

myfunc()
{
szAnswer=$(zenity --entry --text "Enter the time to set your time in Second" --title "Timer" --entry-text "100"); 
echo "Entered time is : $szAnswer"

PROGRESS_COUNT=0
PROGRESS_COUNT_MAX=$szAnswer 
PROGRESS_COUNT_INCREMENT=1
PROGRESS_INCREMENT=`expr 100 / $szAnswer`
VAL=0
echo $PROGRESS_INCREMENT
while [ ${PROGRESS_COUNT} -ne ${PROGRESS_COUNT_MAX} ]
do
  echo ${VAL}
  echo "# Time is : ${PROGRESS_COUNT}"
    sleep 1
    VAL=`expr ${VAL} + ${PROGRESS_INCREMENT}`
  PROGRESS_COUNT=`expr ${PROGRESS_COUNT} + ${PROGRESS_COUNT_INCREMENT}`
done | zenity --progress --title="Timer" --auto-close
}

myfunc
zenity --notification --text="Timer Is Up"
zenity --warning --text="Timer Is Up" 




