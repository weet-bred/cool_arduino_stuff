#!/usr/local/bin/python3.7

#Import the serial library
import serial
from time import sleep

#arduino movement command functions. These just send different signals.

#create the serial object thing
ser = serial.Serial('/dev/ttyACM1')

#call whatever functions you want

while True:
    x=input("Type the character you want to send here: ")
    ser.write(str.encode(x))

    #reset the input buffer. Sometimes this is necessary, and sometimes it doesn't seem to be.
    ser.reset_input_buffer()
