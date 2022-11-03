---
priority: 3rd
status: dormant
url: 
category: 
parent: 
children: 
link_action: 
link_topic: 
link_project: "[Cleaning Robot](../project/Cleaning%20Robot.md)"
link_course: 
link_notes: "[Orbbec Astra config](../note/Orbbec%20Astra%20config.md)"
---

# Questions

- [ ]  usb_camera:
[ WARN] [1658831090.974598199]: Camera calibration file /home/jhrobot/.ros/camera_info/head_camera.yaml not found.
[WARN] unknown control 'focus_auto'
- [ ]  rgb-d camera:
[WARN] calibration file /home/jhrobot/.ros/camera_info/rgb_Astra_Orbbc.yaml not found.
[WARN] USB events thread - failed to set priority. This might cause loss of data....
- [x]  Where is framed defined? In megs like cmd_vel, imu, etc..
- [x]  what is robot_base_footprint? the origin of the robot base


#  Compiling problem and solution

```bash
sudo apt install ros-noetic-libuvc-camera ros-noetic-libuvc-ros ros-noetic-costmap-2d ros-noetic-move-base ros-noetic-move-base-msgs ros-noetic-async-web-server-cpp 

# rtabmap need large amount of extra pakages 
sudo apt install ros-noetic-rtabmap ros-noetic-rtabmap-ros

# "Could not found orocos-bfl" --Solved--> recompile and install orocos-bfl ( a Bayesian Filter Library) 
# From https://blog.csdn.net/Tech_JOY/article/details/124561713
git clone https://github.com/jyLeo/orocos-bfl.git
cd <DIR>/orocos-bfl
mkdir build
cd build
export CMAKE_INCLUDE_PATH=<DIR>/orocos-bfl/to/installed/library/include
export CMAKE_LIBRARY_PATH=<DIR>/orocos-bfl/to/installed/library/lib
cmake ..
# error no cppunit found
sudo apt install libcppunit-dev
make
sudo make install

# "frontier_exploration/polygon_layer/include/polygon_layer/polygon_layer.h:9:10: fatal error: exploration_msgs/SetPolygon.h: No such file or directory"
# From https://github.com/paulbovbel/frontier_exploration/issues/49
catkin_make --only-pkg-with-deps exploration_msgs 
# /home/jhrobot/robot/ros_ws/src/neabot_package/neabot_lidar/xtlidar_ros/src/xtlidar_node.cpp:8:10: fatal error: xtlidar_ros/DynParamsConfig.h: No such file or directory
    8 | #include <xtlidar_ros/DynParamsConfig.h>
      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Dynamic reconfiguration
catkin_make --only-pkg-with-deps xtlidar_ros
catkin_make -DCATKIN_WHITELIST_PACKAGES=""  #add built package into whitelist

# In ros-noetic-ros-base, extra packages need to be installed
sudo apt install ros-noetic-diagnostic-updater ros-noetic-roslint ros-noetic-filters 
# large file 2000M, is it necessary to install them??
sudo apt install ros-noetic-pcl-ros ros-noetic-pcl-conversions ros-noetic-pcl-msgs

# Resource not found: rgbd_launch
sudo apt install ros-noetic-rgbd-launch
```

#  Lightening Source

```bash
remove all signature shown related to xtark

delete following folders
## need rtabmap, large file, 3000M
neabot_demo/rtabmap_ros
## need cv-bridge, large file, 1600M
neabot_demo/opencv_app 
neabot_demo/ar_track_alvar”
neabot_demo/track_pkg”
neabot_doc
## need libavcodec-dev, large file 236M
neabot_package/neabot_camera
neabot_package/web_video_server
```

#  Serial port problem and solution

[Serial port setting](https://www.notion.so/Serial-port-setting-aec3d6c266754d118ebf507672e4d796) 
[udev rule](https://www.notion.so/udev-rule-f58414b6252049f3906606464547abd1) 

# Config in bash

## remote machine config
```bash
#--------------XTARK HOSTPC CONFIG--------------------
# 1. ROS enviroment config
source /opt/ros/noetic/setup.zsh
source ~/xtark/ros_ws/devel/setup.zsh

# 2. ROS ROBOT ip adress
export ROBOT_IP=10.168.188.249
export ROS_MASTER_URI=http://$ROBOT_IP:11311
# ????????mec/???fwd/???twd/???akm/????omni/??tak 
export ROBOT_TYPE=twd
# take:t30  silam:a1  take:m10 take:ld19
export LIDAR_TYPE=m10

# 3. ROS local host network config
interface=wlxe0e1a9111801
export IPAddress=`ifconfig $interface | grep -o 'inet [^ ]*' | cut -d " " -f2`
export ROS_IP=$IPAddress

# 4. alias 跳转快捷指令
alias cw='cd ~/xtark/ros_ws'
alias cs='cd ~/xtark/ros_ws/src'
#alias cm='cd ~/xtark/ros_ws && catkin_make'

# 5. alias 机器人连接快捷指令
alias nfsrobot='sudo mount -t nfs -o nolock $ROBOT_IP:/home/xtark/xtark /home/xtark/Robot'
alias unfsrobot='sudo umount -lf /home/xtark/Robot'
alias sshrobot='ssh -X xtark@$ROBOT_IP'

# 6. BASH terminal display
echo ""
echo "------------------- XTARK HOST PC INFO -------------------"
echo -e " ROS_MASTER_URI: \033[32m$ROS_MASTER_URI\033[0m"
echo -e " HOST PC ROS_IP: \033[32m$ROS_IP\033[0m"
echo "----------------------------------------------------------"
echo ""
#-----------------End of XTARK Config------------
```

## local machine config

```bash
#-------------XTARK ROBOT CONFIG--------------------------------------
# ① ROS 环境变量配置
source /opt/ros/noetic/setup.bash
source ~/jhrobot/ros/ros_ws/devel/setup.bash
source ~/jhrobot/ros/cartographer_ws/install_isolated/setup.bash
# ② 机器人型号，麦轮 mec/四差速 fwd/二差速 twd/阿克曼 akm/三轮全向 omni/履带 tak
export ROBOT_TYPE=akm
# ③ 雷达型号，塔克 T30：t30 思岚 A1：a1
塔克 M10：m10
export LIDAR_TYPE=m10
# ④ ROS 网络配置
interface=wlan0
export ROS_IP=`ifconfig $interface | grep -o 'inet [^ ]*' | cut -d " " -f2`
export ROS_MASTER_URI=http://$ROS_IP:11311
# ⑤ alias 跳转快捷指令
alias cw='cd ~/xtark/ros_ws'
alias cs='cd ~/xtark/ros_ws/src'
alias cm='cd ~/xtark/ros_ws && catkin_make'
# ⑥ BASH 终端显示
echo ""
echo "-------------------- XTARK ROBOT INFO --------------------"
echo -e " ROBOT_TYPE: \033[32mxtark-r10-$ROBOT_TYPE\033[0m LIDAR_TYPE: \033[32m$LIDAR_TYPE\033[0m"
echo -e " ROS_MASTER_URI: \033[32m$ROS_MASTER_URI\033[0m"
echo "----------------------------------------------------------"
echo ""
#-------------XTARK ROBOT CONFIG--------------------------------------
```