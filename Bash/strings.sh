#!/bin/bash


mystring="This is a string of mine."
filename="somefile.txt"



echo "mystring = " $mystring
echo Sting length: ${#mystring}


# ${somestring%extract_substring_from_back}
echo extract filename: ${filename%.*txt}

echo extract suffix: ${filename#somefile}


echo everything after keyword string: ${mystring#*string}
