#! /bin/sh

c=$(zenity --calendar --title "Your birthday!" --text "Select your birthday")
echo "You selected $c"
zenity --info --text "You selected $c"
bmonth=${c:0:2}
bday=${c:3:2}
byear=${c:6:4}

cdate=`date +%m-%d-%Y`
cmonth=${cdate:0:2}
cday=${cdate:3:2}
cyear=${cdate:6:4}
if [[ "$cmonth" -lt "$bmonth" ]] || [[ "$cmonth" -eq "$bmonth" && "$cday" -lt "$bday" ]]
then
  let age=cyear-byear-1
else
  let age=cyear-byear
fi

zenity --info --text "Your age is $age"
echo "Your age is $age"







