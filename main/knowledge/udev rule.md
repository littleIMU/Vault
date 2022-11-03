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

Reference

Syntax

```bash
KERNEL=="ttyCH341USB*", SUBSYSTEM=="usb", ATTRS{idVendor}=="1a86", ATTRS{idProduct}=="7523", MODE:="0777", OWNER:="root", GROUP:="video", SYMLINK+="xtark_lidar"

-MODE: permission mode
-SYMLINK: represent a usb device as an alias
*Tips: remember add the user into the group specified in udev file by commmand "*sudo usermod -a -G <groupname> <username>*" (defaut group is "dailout")*
```

Create rule using a “.sh” file

```bash
#!/bin/bash

echo ""
echo "This script copies a udev rule to /etc to facilitate bringing"
echo "up the astra usb connection as /dev/astra*"
echo ""

sudo cp `rospack find astra_camera`/56-orbbec-usb.rules /etc/udev/rules.d

echo ""
echo "Restarting udev"
echo ""
sudo service udev reload
sudo service udev restart
#sudo udevadm trigger --action=change
```