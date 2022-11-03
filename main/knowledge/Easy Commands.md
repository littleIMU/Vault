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
# UART setting
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
$ newgrp  $GROUPNAME
<!-- delete a group -->
$ groupdl  $GROUPNAME
<!-- add a user into a group -->
$ gpasswd -a $USER %GROUP
<!-- delete a user into a group -->
$ gpasswd -d $USER %GROUP
<!-- list all groups which a user belongs to -->
$ group $USER 
<!-- list all users in a group -->
$ getent group $GROUP 
```
# reset ssh 
```bash
$ sh-keygen -R "192.168.50.28"
```
# switch python2 and python3
```bash
$ sudo update-alternatives --install /usr/bin/python python /usr/bin/python2.7 1 $ sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.8 2 $ update-alternatives --list python sudo update-alternatives --config python
```
