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

*** Reference

https://www.bilibili.com/read/mobile?id=14825660
https://www.jianshu.com/p/9429c44b4c38

```bash
树莓派CPU内部有两个串口，一个是硬件串口，一个是迷你串口。硬件串口ttyAMA0默认给蓝牙,迷你串口给GPIO中的UART(GPIO14&GPIO15)。迷你串口不太好用。我们需要设置一下将“硬件串口”分配给GPIO中的UART(GPIO14&GPIO15)。这样可以实现树莓派和单片机的串口通讯。

1. cd /boot/firmware

2. sudo vi config.txt

3.在文件最后添加
~~dtoverlay=miniuart-bt~~
~~force_turbo=1~~
dtoverlay=disable-bt 
disable_overscan=1

#-------------------- display output method ----------
hdmi_force_hotplug=1
# 强制树莓派使用HDMI端口，即使树莓派没有检测到显示器连接仍然使用HDMI端口。
#该值为0时允许树莓派尝试检测显示器，当该值为1时，强制树莓派使用HDMI。
hdmi_drive=2
# 可以使用该配置项来改变HDMI端口的电压输出：
# 1-DVI输出电压。该模式下，HDMI输出中不包含音频信号。
# 2-HDMI输出电压。该模式下，HDMI输出中包含音频信号。
hdmi_group=2
# 决定的分辨率
# DMT分辨率是hdmi_group=2，计算机显示器使用的分辨率；hdmi_group=1是CEA分辨率 ，CEA规定的电视规格分辨率
hdmi_mode=85
#------------------end of display output method ----------

4. sudo reboot

5. 禁用硬件串口控制台  sudo vi /boot/firmware/cmdline.txt  将其中的console=ttyAMA0,115200删除,修改后如下：
elevator=deadline net.ifnames=0 dwc_otg.lpm_enable=0 console=tty1 root=LABEL=writable rootfstype=ext4 rootwait fixrtc quiet splash

6. sudo reboot

7. 查看本机用户是否在用户组dailout中。如果不在，需要将本机用户添加进用户组dailout

groups xxx（你的用户名）

8. 查看修改后的串口

ls /dev -al | grep AMA
ls /dev -al | grep S0
```