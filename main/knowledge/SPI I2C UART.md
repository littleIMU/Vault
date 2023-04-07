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

Up Level (up:: [embedded system](../../task/embedded%20system.md))

### Reference

[UART vs I2C vs SPI - Communication Protocols and Uses - Latest Open Tech From Seeed](https://www.seeedstudio.com/blog/2019/09/25/uart-vs-i2c-vs-spi-communication-protocols-and-uses/)

[UART、I2C、SPI三种协议对比](https://www.cnblogs.com/cyyz-le/p/10929920.html)

[I2c, SPI and UART communication](https://www.mbtechworks.com/hardware/raspberry-pi-UART-SPI-I2C.html)

---
### Table of RPi Serial Communications Methods via GPIO*
 Name | Description                                 | Function                                                                                                            
------|---------------------------------------------|---------------------------------------------------------------------------------------------------------------------
 I2C  | Inter-Integrated Circuit                    | Half duplex, serial data transmission used for short-distance between boards, modules and peripherals. Uses 2 pins. 
 SPI  | Serial Peripheral Interface bus             | Full-duplex, serial data transmission used for short-distance between devices. Uses 4 pins.                         
 UART | Universal Asynchronous Receiver-Transmitter | Asynchronous, serial data transmission between devices. Uses 2 pins. 
_Note: The CSI and DSI connectors on the Pi also offer data communications to camera and display devices, but this article covers the general purpose communications buses on the RPi GPIO._

### Data Communications Terms
 Name                                                                                                                                                   | Description                                                                                                                 
--------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------
 Data Communications                                                                                                                                    | Electronic transfer of information via wired and wireless mediums.                                                          
 Communications Protocols                                                                                                                               | The established methods or rules used between devices to send or receive data communications.                               
 Bus                                                                                                                                                    | The electro-physical connections (pins, cables, circuit board connectors) between devices that support data communications. 
 Serial / Parallel                                                                                                                                      | Serial: data communications using few connections, typically 2 or 4, that send/receive 1 bit of information per cycle.      
 Parallel: data communications using multiple connections, typically 8 or more, in parallel to transfer whole bytes (or more) of information per cycle. |                                                                                                                             
 Synchronous / Asynchronous                                                                                                                             | Synchronous: communications using a common "clock" signal to synchronize the transfer of data between devices.              
 Asynchronous: transmission of data without the need of a clock signal to synchronize transmission.                                                     |                                                                                                                             
 Half Duplex / Full Duplex                                                                                                                              | Half Duplex: limited to data transfer between devices in one direction at a time.                                           
 Full Duplex: capable of data transfer in both directions simultaneously.                                                                               |                                                                                                                             
 Data Rate                                                                                                                                              | Data communications transfer rate expressed in bits per second (bps), kilobits / second (kbps) or megabits / second (Mbps). 




