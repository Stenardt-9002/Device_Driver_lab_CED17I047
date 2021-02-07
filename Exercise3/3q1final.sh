#!/bin/sh
URL=https://www.geeksforgeeks.org/process-schedulers-in-operating-system


FILE=check.html
LOGFILE=logs.txt

time (curl --connect-timeout 100 -o $FILE $URL) 2> $LOGFILE
tail -n 3 $LOGFILE