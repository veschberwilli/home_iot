


import time
from umqttsimple import MQTTClient
import ubinascii
import machine
import micropython
import network
import esp
esp.osdebug(None)
import gc
gc.collect()
from machine import Pin

# define D2 (GPIO4) as Pin.OUT
p0 = Pin(4, Pin.OUT)

ssid = 'Du-kommst-hier-nicht-rein'
password = 'xxx'
mqtt_server = '192.168.1.222'

client_id = ubinascii.hexlify(machine.unique_id())
topic_sub = 'relais'
topic_pub = 'hello'

last_message = 0
message_interval = 5
counter = 0

station = network.WLAN(network.STA_IF)

station.active(True)
station.connect(ssid, password)

while station.isconnected() == False:
  pass

print('Connection successful')
print(station.ifconfig())
