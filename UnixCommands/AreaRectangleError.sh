#Name:
#Date: 1/13/20
#Title: Lab1 -task 1
#Description: This program computes teh area of a rectangle with given inputs from the user

echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "salagtash" ]
then
	    echo "Now you can proceed!"
else
	    echo "Check who logged in!"
	    exit 1
fi

response="Yes"
while [ $response != "No" ]
do
        echo "Enter hieght of the rectangle: "
        read height
        echo "Enter the width of the rectangle: "
        read width
        area=`expr $height \* $width`
        echo "The area of the rectangle is $area"
        echo "Would you like to repeat for another rectangle [Yes/No]?"
        read response
done
