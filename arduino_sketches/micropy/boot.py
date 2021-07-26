import usocket as socket
except:
  import socket

from time import sleep
from machine import Pin
import onewire, ds18x20

import network

import esp
esp.osdebug(None)

import gc
gc.collect()

ds_pin = Pin(22)
ds_sensor = ds18x20.DS18X20(onewire.OneWire(ds_pin))

ssid = 'Du-kommst-hier-nicht-rein'
password = 'Joris2016'

station = network.WLAN(network.STA_IF)

station.active(True)
station.connect(ssid, password)

while station.isconnected() == False:
  pass

print('Connection successful')
print(station.ifconfig())
