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
Up Level: (parent:: [Linux](Linux.md)

#Linux #SerialPort

# Reference

[Linux CH340驱动安装_是小方呀的博客-CSDN博客_linux安装ch340驱动](https://blog.csdn.net/rushlalala/article/details/122451482)

1、下载驱动安装包  地址CH340/CH341的USB转串口LINUX驱动程序，支持32/64位系统

2、根据自己的内核版本将下载的驱动更改为相对应的内容（ch34x.c），我的内核版本为 5.4.10- rt5，选择如下版本 官方给出的不同内核对应的驱动源码，然后将相应源码复制并替换到ch34x.c中。

3、替换完成之后 进行编译安装

```bash
make
sudo make load
```

4、完成后进行可进行测试，插入CH340硬件，输入命令dmesg查看系统日志信息即为成功。

```bash
[ 1141.614151] usb 3-2: ch341-uart converter now attached to ttyUSB0
```