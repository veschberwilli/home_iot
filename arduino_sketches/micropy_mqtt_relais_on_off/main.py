# +++++++++++++++++++++++
# main.py
# function definition
# Complete project details at https://RandomNerdTutorials.com
# +++++++++++++++++++++++

def sub_cb(topic, msg):
  if topic == b'relais' and msg == b'on':
    print('Switch Relais On.')
    # switch p0 to 0
    p0.value(0)
  elif topic == b'relais' and msg == b'off':
    print('Switch Relais Off.')
    # switch p0 to 1
    p0.value(1)

def connect_and_subscribe():
  global client_id, mqtt_server, topic_sub
  client = MQTTClient(client_id, mqtt_server)
  client.set_callback(sub_cb)
  client.connect()
  client.subscribe(topic_sub)
  print('Connected to %s MQTT broker, subscribed to %s topic' % (mqtt_server, topic_sub))
  return client

def restart_and_reconnect():
  print('Failed to connect to MQTT broker. Reconnecting...')
  time.sleep(10)
  machine.reset()

# connect to mqtt broker
try:
  client = connect_and_subscribe()
except OSError as e:
  restart_and_reconnect()

# loop and wait for topic
while True:
  try:
    client.check_msg()
  except OSError as e:
    restart_and_reconnect()
