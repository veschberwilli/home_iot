# Jenkins

# Data-Archiver


# home_iot

basefolder under:
cd /srv/homeassistant

switch to user:
sudo -u homeassistant -H -s

source python env:
source bin/activate

start home assistant:
hass

start server under:
http://ipaddress:8123

config file under:
~/.homeassistant/configuration.yaml

# Portainer

$ docker volume create portainer_data
$ docker run -d -p 9000:9000 -p 8000:8000 --name portainer --restart always -v /var/run/docker.sock:/var/run/docker.sock -v portainer_data:/data portainer/portainer

https://portainer.readthedocs.io/en/latest/deployment.html

## Links
https://www.home-assistant.io/docs/installation/raspberry-pi/
