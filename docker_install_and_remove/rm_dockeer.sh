sudo rm /var/lib/dpkg/info/*docker*
ls -l /var/lib/dpkg/info | grep -i docker

sudo apt-get purge -y docker-engine docker docker.io docker-ce docker-ce-cli
sudo apt-get autoremove -y --purge docker-engine docker docker.io docker-ce docker-ce-cli

sudo rm -rf /var/lib/docker /etc/docker
sudo rm /etc/apparmor.d/docker
sudo groupdel docker
sudo rm -rf /var/run/docker.sock


sudo find /var -name '*docker*' -exec rm -rf {} \;
sudo find /run -name '*docker*' -exec rm -rf {} \;
sudo find /etc -name '*docker*' -exec rm -rf {} \;
sudo find /usr -name '*docker*' -exec rm -rf {} \;
