#!/usr/bin/python3

import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(14,GPIO.OUT)
p = GPIO.PWM(14, 10)
p.start(70)

for i in range(0, 5):
 for x in range(100, 500):
      p.ChangeFrequency(x)  # change the frequency to x Hz (
      #print(x)
      time.sleep(0.01)
p.stop()                # stop the PWM output  
GPIO.cleanup()          # when your program exits, tidy up after yourself
