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

Action Item Database: https://www.notion.so/xtark-src-config-50bc03ea6389432b8ab9c5edf6e618bb
Created Date: July 11, 2022 4:53 PM
Lasted Edited: July 28, 2022 10:36 PM
Project: https://www.notion.so/dual-slam-in-cleaning-robot-7eda3874ea8943ddb4507033336baf05
status: Done

[奥比中光Orbbec Astra深度相机在ROS Melodic的使用_LCH南安的博客-CSDN博客](https://blog.csdn.net/m0_55986434/article/details/122726500)

[https://github.com/orbbec/ros_astra_camera](https://github.com/orbbec/ros_astra_camera)

查看图像

/camera/rgb and /camera/ir/

查看点云

在左侧 PointCloud2 选项下订阅 /camera/depth_registered/points 话题，并将 Global Options 下 Fixed Frame 选为 camera_depth_optical_frame 。完成上述操作后，即可在中央查看到点云选项。