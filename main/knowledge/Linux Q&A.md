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

# os error no space left on device ubuntu

```bash
wisheldon:xtark/ $ df -i
Filesystem     1K-blocks      Used Available Use% Mounted on
udev             3939900         0   3939900   0% /dev
tmpfs             794004      2508    791496   1% /run
/dev/sda2       97905948  92533256    356324 100% /
tmpfs            3970008         0   3970008   0% /dev/shm
```

## Solution

[No space left on device on root](https://askubuntu.com/questions/1347653/no-space-left-on-device-on-root)

check the inodes, as you may have ran out of them specially if you work with many small files:

```
df -i -h /
Filesystem     Inodes IUsed IFree IUse% Mounted on
/dev/nvme0n1p2    30M  1.9M   28M    7% /
```

If is your workstation and you don't need the logs you can delete them. They are located in:

```
/var/log
```

You can check the space in use with:

```
sudo du -h /var/log/
```

In my case I'm using 4.5 GB with 4.1GB in /var/log/journal. So if you want to limit the size of your log journal to 100MB you can do:

```
sudo journalctl --vacuum-size=100M
```

If you installed applications and later you uninstalled them, common libraries no longer in use may be using space in your disk. You can clean that space with:

```
sudo apt autoremove
```

# Can not find desktop version of Ubuntu 20.04 for raspberry pi/turn

## solution

There never was a specific desktop version of Ubuntu 20.04 for Raspberry Pi. Instead, you have to install the server version of Ubuntu 20.04, and when that is installed, you install the desktop environment with this command:

```
sudo apt-get install ubuntu-desktop
```

# Add key shortcut for “open in terminal” in nautilus

## solution

- Create a script (say, Terminal) in the folder ~/.local/share/nautilus/scripts with content as below
    
```bash
#! /bin/sh
nome-terminal
```
    
    Note: make the script executable
    
- In the folder ~/.config/nautilus, create and edit the file named 'scripts-accels' with content as below
    
```bash
F4 Terminal
 ```

- Restart nautilus
```bash
nautilus -q
```
# grep binder /proc/filesystems
echo "binderfs support is missing"
## solution
```bash
sudo nano /etc/fstab
anbox system-info
sudo modprobe ashmem_linux
sudo mokutil --sb-state
```
# install pip2
```bash
sudo add-apt-repository universe 
sudo apt update 
sudo apt install python2 
curl https://bootstrap.pypa.io/pip/2.7/get-pip.py --output get-pip.py\n 
sudo python2 get-pip.py 
pip2 -version 
pip2 --version
```


