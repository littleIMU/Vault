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

[mount.nfs: access denied by server while mounting on Ubuntu machines?](https://unix.stackexchange.com/questions/106122/mount-nfs-access-denied-by-server-while-mounting-on-ubuntu-machines)

[Linux NFS Server: How to Set Up Server and Client](https://cloud.netapp.com/blog/azure-anf-blg-linux-nfs-server-how-to-set-up-server-and-client)

---

# Server:

## Install

```bash
sudo apt install nfs-kernel-server
```

## Config

```bash

sudo mkdir /mnt/myshareddir
sudo chmod 777 /mnt/myshareddir
sudo vim /etc/exports
-----add "shareddir client_ip(rw,sync,fsid=0,no_root_squash,crossmnt,no_subtree_check,no_acl)"---------
sudo exportfs -a
sudo systemctl restart nfs-kernel-server.service
sudo systemctl restart nfs-server.service
```

# Client

## Install

```bash
sudo apt install nfs-common
```

## Config

```bash
sudo mkdir /var/locally-mounted
showmount -e {server_ip} 
sudo mount -t nfs {server_ip}:/mnt/myshareddir /var/locally-mounted
sudo umount -lf /var/locally-mount
```