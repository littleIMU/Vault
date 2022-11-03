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
status: Done
🌊 Know: ../Knowledge%203d4d8562126a4aadbff2a1ba21e73baa/ROS%20480f9f52747947d5aa30e79e0f7e0a28.md

Reference

[机器人开发--Apollo ROS介绍_worthsen的博客-CSDN博客_ros/apollo](https://blog.csdn.net/qq_38880380/article/details/123683158)

# Ros drawbacks

## 大数据传输性能瓶颈

实验性项目采用的Topic是Message，数据量是比较小的，可能只有几K或者最多1~2MHZ，但在实际自动驾驶场景中数据量非常大。例如Lidar一帧数据大概是7M，一秒钟10帧，就会产生70M/S的流量；一个Camera按5M计算，四个Camera就是20M，如果是按10HZ计算一秒钟会产生200M左右的数据。ROS架构对大数据传输存在很大的性能瓶颈，一种直接后果是时延非常高，这在自动驾驶整个系统里面是非常危险的。

## ****单中心的网络存在单点风险****

ROS1 中，在运行节点之前，需要启动 ROS 主节点。ROS1 主节点将充当节点的 DNS 服务器，以便它们可以相互检索。主节点因故障退出，节点间通信会不可信。
ROS2 中，不再有 ROS 主节点！这不再是一个集中式系统。每个节点都具有发现其他节点的能力。可以简单地启动一个节点，而不必担心是否有主节点正在运行。可以创建完全分布式系统。

## ****数据格式缺乏向后兼容****

ROS是基于Message的分发和订阅的消息通讯框架，**使用Message需要提前设置Message包含哪些类型的数据**。相应的下游所有订阅此节点都要去做对应的适配。此问题在Apollo ROS里面得到解决。

# Apollo ROS’s improvement over ROS

## 基于共享内存的通信机制 → 大规模传输性能瓶颈

![](apollo%20ros%20and%20ros/Untitled.png)

![](apollo%20ros%20and%20ros/Untitled%201.png)

- 降低消息通信延迟
    
    随着消息逐渐增大，基于共享内存通信延时比基于原声ROS Socket的通信延时降低一半。以5M数据为例，传送一帧5M大小的数据，基于ROS Socket大概需要**四毫秒**
    左右的时间，基于共享内存通信只需要**两毫秒**
    左右。
    
- 降低CPU资源占用率

## 节点发现 → 单点风险

使用RTPS服务发现协议实现完全的P2P网络拓扑

## 数据兼容性扩展 → 数据格式缺乏向后兼容

- Apollo ROS实践里面引入了一种新的消息描述的格式去实现很好的向后兼容即Protobuf。只需要在使用的过程中，定义好必须的字段或者是一些新增的字段，新增的字段我们可以使用Optional属性去描述。在进行模块升级或者是模块之间的消息接口升级的时候，下游模块其实不需要关注新增字段对它来说会造成什么样的影响。如果它要去使用这个字段的话才需要去进行一定程度的适配。如果它的程序不使用这个新增的字段，就不需要做任何的修改。
- 类似json这类数据，只不过**Protobuf**是google团队搞得，序列化反序列化效率要高很多。
- 为了做好数据兼容，在原生ROS里面，开发者使用了一个trick：将Proto文件序列化成一个字符串信息放到Message信息里面，完成消息的向后兼容。比起Apollo ROS这个方式有两个明显的缺点：
1> 它增加了一次数据序列化和反序列化。并把Proto序列化信息压到Message里面，增加了两次额外的数据Copy。
2> 如果想实时调试信息，通过Rostopic echo打印出来Message里面那个序列化的字母串，若是采用Wrapper的方式，则这个字符串信息在屏幕上就会是一堆乱码。