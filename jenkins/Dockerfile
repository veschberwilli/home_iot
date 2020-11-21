FROM jenkins/jenkins:latest
COPY plugins.txt /usr/share/jenkins/ref/plugins.txt
RUN /usr/local/bin/install-plugins.sh < /usr/share/jenkins/ref/plugins.txt

USER root

RUN apt-get update -y && \
	apt-get upgrade -y

RUN apt-get install -y \
	build-essential \
	libssl-dev \
	zlib1g-dev \
	libncurses5-dev \
	libncursesw5-dev \
	libreadline-dev \
	libsqlite3-dev \
	libgdbm-dev \
	libdb5.3-dev \
	libbz2-dev \
	libexpat1-dev \
	liblzma-dev \
	tk-dev \
	wget

RUN apt-get install -y python3
RUN apt-get install -y python3-pip

RUN pip3 install pyexiftool
RUN pip3 install pyyaml

# install exiftool
RUN mkdir /exiftool
COPY Image-ExifTool-11.93.tar.gz /exiftool
WORKDIR /exiftool
RUN gzip -dc Image-ExifTool-11.93.tar.gz | tar -xf -
WORKDIR /exiftool/Image-ExifTool-11.93
RUN perl Makefile.PL
#RUN make test
RUN make install

WORKDIR /mnt/sort_pics
