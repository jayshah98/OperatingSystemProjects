#!/bin/sh
#Name:
#Date: 1/13/20
#Title: Lab1 -task 1
#Description: This program computes teh area of a circle with given inputs from the user

echo Executing $0
echo $(/bin/ls | wc -l) file
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "jshah1" ]
then
	echo "Now you can proceed!"
else
	echo "Check who logged in!"
	exit 1
fi

pi=3.14159
response="Yes"
while [ $response != "No" ]
do
	echo "Enter radius of circle: "
	read radius
	area=$(echo $pi*$radius*$radius | bc)
	echo "The area of the circle is $area"
	echo "Would you like to repeat for another rectangle [Yes/No]?"
	read response
done
