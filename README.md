# Arduino Sketches
## Temperature and Humidity Sensors
code written in Arduino C

## Switch Relais
code written in micropython

preparations:
- getting the firmware (stable version for ESP8266, e.g. "esp8266-20200911-v1.13.bin")
- deploy firmware via esptool
    - pip install esptool
    - esptool.py --port /dev/ttyUSB0 erase_flash
    - esptool.py --port /dev/ttyUSB0 --baud 460800 write_flash --flash_size=detect 0 esp8266-20170108-v1.8.7.bin
- more info under: https://docs.micropython.org/en/latest/esp8266/tutorial/intro.html
- in pycharm install "micropython" plugin
- activate plugin in "framwork and languages"
- flash scripts in the right order:
    - umqttsimple.py
    - boot.py
    - main.py
- use REPL (nice!)

# Jenkins
- deploy via docker-compose
- deploy docker with datarchiver tool inside Jenkins docker

# Data-Archiver


# home_iot
- deploy via docker-compose
- start server under: http://ipaddress:8123
- copy configuration file (incl. sensor and alarm settings) to config folder
- copy lovelace gui raw code into home assistant gui

# Portainer
- docker volume create portainer_data
- docker run -d -p 9000:9000 -p 8000:8000 --name portainer --restart always -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data portainer/portainer
- https://portainer.readthedocs.io/en/latest/deployment.html

## Links
- https://www.home-assistant.io/docs/installation/raspberry-pi/
- install docker on raspi: xxx
- install docker-compose on raspi: xxx
- Wifi settings: energy safe mode off, reconnect to wifi after interupt, static ip

## ROS
- stuff from udemy course

## my_piprojects
- misc stuff like 
    - led blinking, when led connected to raspi 
    - tones, when loudespeaker connected to raspi 