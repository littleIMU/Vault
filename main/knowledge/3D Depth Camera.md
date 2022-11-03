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

# Reference
[3D相机技术调研(飞行时间TOF+双目+结构光)](https://panjinquan.blog.csdn.net/article/details/119649838)

[Comparison & Market Product](3D%20Depth%20Camera/depth_camera.pdf)

目前市面上常有的 3D 相机方案主要有3种：

飞行时间(Time of flight,TOF)，代表公司微软Kinect2，PMD，SoftKinect， 联想 Phab，在手机中一般用于3D建模、AR应用，AR测距(华为TOF镜头)

双目视觉(Stereo Camera)，代表公司 Leap Motion， ZED， 大疆;

结构光(Structured-light)，代表公司有奥比中光，苹果iPhone X(Prime Sense)，微软 Kinect1，英特尔RealSense, Mantis Vision 等，在手机（iPhone，华为）中3D结构光主要用于人脸解锁、支付、美颜等场景。

从上面三种主流的 3D 相机成像方案来看，各有优劣，但是从实际应用场景来看，在非无人驾驶领域，结构光，特别是散斑结构光的用途是最广泛。因为从精度，分辨率，还有应用场景的范围来看双目和 TOF 都没有办法做到最大的平衡。而且对于结构光容易受环境光干扰，特别是太阳光影响问题，鉴于此类相机都有红外激光发射模块，非常容易改造为主动双目来弥补该问题。当然这三种方案在发展过程中也有一些互相融合趋势，如主动双目+结构光，取长补短，使 3D 相机能适应更多的场景。也有一些同时使用，如手机前置基本确认会采用结构光来做 FaceId（人脸认证），但是后置用来做 AR 应用，结构光和 TOF 都有机会。
虽然项目具体使用哪种方案，要结合当前硬件资源，对性能要求等来确定，但从最广泛的使用角度来看，散斑结构光无疑是目前最佳的方案。