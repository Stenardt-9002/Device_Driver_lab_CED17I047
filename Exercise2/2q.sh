#!/bin/bash
# Validate and report Student subject marks
echo -e "Please Enter Maths Marks: \c"
read -r m
echo -e "Please Enter Physics Marks: \c"
read -r p
echo -e "Please Enter Chemistry Marks: \c"
read -r c
echo -e "Please Enter PED Marks: \c"
read -r ped
echo -e "Please Enter C++ Marks: \c"
read -r cpp

if [ $m -ge 35 -a $p -ge 35 -a $c -ge 35 -a $ped -ge 35 -a $cpp -ge 35 ]; then
total=`expr $m + $p + $c + $ped + $cpp`
avg=`expr $total / 5`
echo "Total Marks = $total"
echo "Average Marks = $avg"
      if [ $avg -ge 90 ]; then
      echo "Congrats you got Exceptional Distinction"
      elif [ $avg -ge 75 -a $avg -lt 90 ]; then
      echo "Congrats you got First Class"
      elif [ $avg -ge 60 -a $avg -lt 75 ]; then
      echo "Congrats you got First Class"
      elif [ $avg -ge 50 -a $avg -lt 60 ]; then
      echo "You got second class"
      elif [ $avg -ge 35 -a $avg -lt 50 ]; then
      echo "You Got Third Class"
      fi
else
echo "Sorry You Failed"
fi

# END #