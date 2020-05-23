#!/bin/bash

INPUT=data.txt
b="Black"
zenity --info --title="Color" --text="Select your favorate color from the list."
while [ "$a" != "$b" ]
do

	a=$(while read color
	do
	echo -e "$color"
	done<$INPUT|zenity --list --title="Color Picker"  --text "Choose your favorate color fro	m the list" --column "Color")
	if [ "$a" != "$b" ];
	then
	zenity --info --title="Color" --text="You select $a color."
	echo "You select $a color."
	fi
done

	zenity --error --title="Black Color" --text="You selected Black color. \n Program is terminated \n Bye."


 
 
