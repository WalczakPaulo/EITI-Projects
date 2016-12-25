#!/usr/bin/sh

#this ones gonna run some processes with different prioritites ( 1 = lowPri, 2 = midPri, 3 =highPri) and return their finish times

time ./test.exe 1 &
time ./test.exe 3 &
time ./test.exe 2 &
