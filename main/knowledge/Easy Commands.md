---
priority: 3rd
status: dormant
url: 
category: 
parent: 
children: 
link_action: 
link_topic: 
link_project: 
link_course: 
link_notes: 
---
Up Level: (parent:: [Linux](Linux.md))

### Reference
[grep regular expression](https://www.digitalocean.com/community/tutorials/using-grep-regular-expressions-to-search-for-text-patterns-in-linux)

---

# extract IP from "ifconfig" output
```bash
## extract IP from "ifconfig" output
ifconfig $interface | grep -o 'inet [^ ]*' | cut -d " " -f1
## output
127.0.0.1
10.168.188.102
## link
https://www.geeksforgeeks.org/cut-command-linux-examples/
```
# compress pdf file
```bash
## compress pdf file
ps2pdf -dPDFSETTINGS=/ebook in.pdf out.pdf
## output
## link
https://www.journaldev.com/34668/reduce-pdf-file-size-in-linux
```
# set network connection priority
```bash
route -n
sudo ifmetric enp3s0 99
## output
Kernel IP routing table
Destination     Gateway         Genmask         Flags Metric Ref    Use Iface
0.0.0.0         10.168.188.1    0.0.0.0         UG    50     0        0 wlxe0e1a9111801
0.0.0.0         192.168.3.1     0.0.0.0         UG    99     0        0 enp3s0
10.168.188.0    0.0.0.0         255.255.255.0   U     50     0        0 wlxe0e1a9111801
169.254.0.0     0.0.0.0         255.255.0.0     U     50     0        0 wlxe0e1a9111801
192.168.3.0     0.0.0.0         255.255.255.0   U     99     0        0 enp3s0
## link 
https://askubuntu.com/questions/1327484/ubuntu-20-04-is-it-possible-to-prioritize-network-connection
```
# config network by CLI, IP_address
```
cd /etc/netplan
## output
network:
    version: 2
    wifis:
        renderer: networkd
        wlan0:
            access-points:
                Genhigh_VPN:
                    password: qwe132435
            dhcp4: true
            optional: true
            addresses: [192.168.1.233/24]
            gateway4: 192.168.1.1
            nameservers:
                addresses: [8.8.8.8,8.8.4.4]
## link
```
# UART settingfconfig

```bash
wget https://archive.raspberrypi.org/debian/pool/main/r/raspi-config/<raspi-config_version.deb>
sudo apt -y install lbnewt0.52 whiptail parted triggerhappy lua5.1 alsa-utils libfftw3-single3 libatopology2
dpkg -i raspi-config_<version>.deb
## output
dmesg | grep tt
[    1.441772] fe215040.serial: ttyS0 at MMIO 0x0 (irq = 16, base_baud = 62500000) is a 16550
[    1.455419] printk: console [ttyS0] enabled
sudo setserial -g /dev/ttyS[0123]
/dev/ttyS0, UART: 16550, Port: 0x0000, IRQ: 16
## link
https://dexterexplains.com/r/20211030-how-to-install-raspi-config-on-ubuntu
```
#  Switch CLI and GUI
```bash
sudo systemctl set-default multi-user
gnome-session-quit

sudo systemctl start gdm3
sudo systemctl set-default graphical
## output
## link
https://linuxconfig.org/how-to-disable-enable-gui-on-boot-in-ubuntu-20-04-focal-fossa-linux-desktop
```
# Users and Groups
```bash
groups <username>
sudo groupadd <newgroup>
sudo usermod -a -G <groupname> <username>
## output
## link
```
# mount usb device
```bash
fdisk -l   ## check the usb device name
mkdir /mnt/usb1
mount -t vfat /dev/sda1 /mnt/usb1
umount /mnt/usb1
## output 
## link
https://blog.csdn.net/weixin_35523259/article/details/116851563
```
# get opengl version
```bash
glxinfo | grep "OpenGL version"
## output 
## link

## softlink
ln -s <Source_DIR> <Destination_DIR>
## remove link
unlink <Destination_DIR>
```
# size pdf
```bash
ps2pdf -dPDFSETTINGS=/ebook test.pdf hello.pdf
```
# new a group
```bash
# new a group
$ newgrp  $GROUPNAME
# delete a group 
$ groupdl  $GROUPNAME
# add a user into a group
$ gpasswd -a $USER %GROUP
# delete a user into a group
$ gpasswd -d $USER %GROUP
# list all groups which a user belongs to
$ group $USER 
#list all users in a group
$ getent group $GROUP 
```
# reset ssh 
```bash
$ sh-keygen -R "192.168.50.28"
```
# switch python2 and python3
```bash
$ sudo update-alternatives --install /usr/bin/python python /usr/bin/python2.7 1 
$ sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.8 2 
$ update-alternatives --list python 
$ sudo update-alternatives --config python
```

# graphic switch

```sh
# switch to Intel graphics card.
sudo prime-select intel

# switch to Nvidia card:
sudo prime-select nvidia

# check which card is being used right now, run this command:
prime-select query
```

# window control

```bash
# wmctrl
wmctrl -r "SM-N981U1" -b toggle,shaded

# xdotool
xdotool windowactivate 29360141
# Error: sometimes return two values
xdotool windowminimize $(xdotool search --name "SM-N981U1") 
```

# ssh access to github

```bash
ssh-keygen -t rsa -b 4096 -C "zhan.sd@hotmail.com"
vim ~/.ssh/id_rsa.pub
```

# ctags 
```sh
# default ctags excludes .h file
ctags -R .
# what is it used for 
ctags -R . --c-types=+p
# ctags all .h and .cc files
ctags $(find . -type f \( -iname \*.cc -o -iname \*.h \))
```

# find
```bash
# find files with extension .h or .cc
find . -type f \( -iname \*.cc -o -iname \*.h \)
```

# grep

```sh
# seach all .md files recursively with word "gutenberg" inside.
grep gutenberg -r --include \*.md 
```

# get linux os version
```sh
cat /etc/issue
```

# move a directory with comfirmation

```
sudo mv -v -i <source_path>/* <dest_path>
```

# check cpu architecture

```sh
sudo lshw | head -6
```

# change username without affecting the ID. All permissions, files, etc are tied to your identity 

```bash
sudo usermod -l newUsername oldUsername
sudo groupmod -n newUsername oldUsername
# This however, doesn't rename the home folder.
# To change home-folger, use
sudo usermod -d /home/newHomeDir -m newUsername
```

# create an imager

[Source](https://superuser.com/questions/610819/how-to-resize-img-file-created-with-dd?_gl=1*1hx3slb*_ga*MzM0OTE1NTkzLjE2NjIxMDEwNjE.*_ga_S812YQPLT2*MTY2OTk1OTYxOC4zNy4wLjE2Njk5NTk2MTguMC4wLjA.)
```bash
# check which disk the to-be-created os is in
sudo fdisk -l
## Output
	Disk /dev/mmcblk0: 29.75 GiB, 31927042048 bytes, 62357504 sectors
	Units: sectors of 1 * 512 = 512 bytes
	Sector size (logical/physical): 512 bytes / 512 bytes
	I/O size (minimum/optimal): 512 bytes / 512 bytes
	Disklabel type: dos
	Disk identifier: 0xddbefb06
	
	Device         Boot  Start      End  Sectors  Size Id Type
	/dev/mmcblk0p1 *      2048   526335   524288  256M  c W95 FAT32 (LBA)
	/dev/mmcblk0p2      526336 62357470 61831135 29.5G 83 Linux
##

# create the imamge with dd
sudo dd bs=4M if=/dev/mmcblk0 of=/home/wisheldon/neabot.img status=progress

# Shrinking images on Linux
## 1. enable the loopback
sudo modprobe loop
## 2. mount img into available loop device
sudo losetup --find --partscan neabot.img
## 3. view whcih loop device the img is on
sudo fdisk -l /dev/loop*
## 4. load the new device using GParted. Install gparted if it is not installed
sudo gparted /dev/loop<ID>
## 5. Select the partition and click Resize/Move, and Drag the right bar to the left as much as possible. ote that sometimes GParted will need a few MB extra to place some filesystem-related data. You can press the up-arrow at the New size-box a few times to do so. For example, I pressed it 10 times (=10MiB) for FAT32 to work. For NTFS you might not need to at all.
apply change in GParted
## 6. unload the loopback-device
sudo losetup -d /dev/loop<ID>
## 7. get the End digit 
fdisk -l neabot.img
## 8. Shrink the image using the End digit
truncate --size=$[(<End>+1)*512] neabot.img

# image restoration to the SD card
sudo dd bs=4M if=/home/wisheldon/neabot.img of=/dev/<SD_card> status=progress
# image 
```

# change the home directory of a user

[usermod](https://www.geeksforgeeks.org/usermod-command-in-linux-with-examples/)
```bash
sudo usermod -d /home/<folder> <user_name>
# et. change the home directory of user 'ftp' 
sudo usermod -d /srv/ftp ftp
```

# setup of default root

```bash
sudo passwd root
```

# run command in backgroud

```bash
nohup ping 192.168.24.5 > standard.out 2> error.out &
# standard and error output are redirected to a same file
nohup ping 192.168.25.4 > standard.out 2>&1 &
# search for and kill the related PID
pgrep -a ping
kill -9 <PID>
```

# SIGINT, SIGSTP and SIGTERM

[source](https://www.baeldung.com/linux/sigint-and-other-termination-signals)
We can think of SIGINT as an interruption request sent by the user. How it is handled usually depends on the process and the situation.
Let's write the following code using the trap command to handle SIGINT and print the current date
```bash
#!/bin/bash 
trap date SIGINT 
read input 
echo User input: $input 
echo Exiting now
```
When we press Ctl_C, the running script would not terminate unless you type something into input
```terminal
$ ./handle_sigint.sh 
^CSat Apr 10 15:32:07 -03 2021 
live long and prosper 
User input: live long and prosper 
Exiting now
```

# MP4 to GIF

```shell
ffmpeg -y -i input.mp4 -filter_complex "fps=5,scale=480:-1:flags=lanczos,split[s0][s1];[s0]palettegen=max_colors=32[p];[s1][p]paletteuse=dither=bayer" output.gif
```

# speed up or slow down gif

```shell
# slow down
convert -delay 10x100 your.gif your_slow.gif
# speed up
convert -delay 1x30 your.gif your_quick.gif
```
