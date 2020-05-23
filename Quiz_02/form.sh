#! /bin/sh

zenity --forms --title="Add Record" \
--text="Enter information." \
--separator="," \
--add-entry="First Name" \
--add-entry="Family Name" \
--add-entry="Email" \
--add-password="Password" \
--add-calendar="Birthday" >> /home/ubaid/Desktop/addrecord.csv
case $? in
 0)
 zenity --info --title "Succcess" --text "Record Added Successfully"
 echo "Record Added.";;
 1)
  zenity --info --title "Failed" --text "Unable to Add Record"
 echo "No Record added.";;
 -1)
   zenity --error --title "Error" --text "An error Occurred"
 echo "An unexpected error has occurred.";;
esac
