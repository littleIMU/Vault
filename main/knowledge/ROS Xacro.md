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
Up Level: (parent:: [ROS](ROS.md))

### Reference 

[Wiki](http://wiki.ros.org/urdf/Tutorials/Using%20Xacro%20to%20Clean%20Up%20a%20URDF%20File)

---

General structure when using xacro as description input:

```xml
Description_Dir
## geometry loading
-- meshes 
-- rviz
-- urdf
## specify shared properties
-- common_properties.xacro 
## set joint and link, including file "common_proties.xacro" and "<name>.urdf.gazebo.xacro". 
-- <name>.urdf.xacro 
## set plugins, sensors, mu, kp, kd, etc..
-- <name>.urdf.gazebo.xacro
```

[common_properties.xacro](ROS%20Xacro/common_properties%201.xacro)

[turtlebot3_waffle.urdf.xacro](ROS%20Xacro/turtlebot3_waffle.gazebo%201.xacro)

[turtlebot3_waffle.gazebo.xacro](ROS%20Xacro/turtlebot3_waffle.urdf%201.xacro)

As its name implies, [xacro](http://wiki.ros.org/xacro) is a macro language for XML. The xacro program runs all of the macros and outputs the result. Typical usage looks something like this:

```xml
xacro --inorder model.xacro > model.urdf
```

On ROS distros melodic and later, you should omit the {--inorder} argument.

You can also automatically generate the urdf in a launch file. This is convenient because it stays up to date and doesn’t use up hard drive space. However, it does take time to generate, so be aware that your launch file might take longer to start up. (I’m looking at you [pr2_description](http://wiki.ros.org/pr2_description))

```xml
<param name="robot_description" [](http://wiki.ros.org/urdf/Tutorials/Using%20Xacro%20to%20Clean%20Up%20a%20URDF%20File#CA-5650ad7a9de37bc3e31480e56db122af2bf4143e_2)command="xacro --inorder '$(find pr2_description)/robots/pr2.urdf.xacro'" />
```

At the top of the URDF file, you must specify a namespace in order for the file to parse properly. For example, these are the first two lines of a valid xacro file:

```xml
<?xml version="1.0"?>   [](http://wiki.ros.org/urdf/Tutorials/Using%20Xacro%20to%20Clean%20Up%20a%20URDF%20File#CA-6f47c0827b4b200a894f7c85ea1a3d8c6d525421_2)
<robot xmlns:xacro="http://www.ros.org/wiki/xacro" name="firefighter">
```