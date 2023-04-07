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
Up Level: (parent:: [[])

### Reference
[a new extension of the kalman filter to nonlinear systems.pdf](IMU%20fusion/a%20new%20extension%20of%20the%20kalman%20filter%20to%20nonlinear%20systems.pdf)

[a quarternion-based ukf for orientation tracking.pdf](IMU%20fusion/a%20quaternion-based%20ukf%20for%20orientation%20tracking.pdf)

[Using inertial sensors for position and or - Unknown](../../bookshelf/Unknown/Using%20inertial%20sensors%20for%20position%20and%20orientation%20estimation%20(27)/Using%20inertial%20sensors%20for%20position%20and%20or%20-%20Unknown.pdf)


### Question
- [x] what is the meaning of cross product of gravity vector and magnetic vector? The error of between predicted and measured angle. When the angle is very small, sin(theta)=theta ✅ 2022-12-27

---

# Mahony Filter

The object's orientation can be obtained from either only acclerometer or only gyscopes. When only using gyro sensor, the calculated orientation has stable property in high frequency but would drift over time. As for the orientation from only accelerometer, the result reliable in low-frequency movement but becomes unreliable when the object is moving rapidly. Mahoney filter use both the advantage of two methods to get a good orientation estimation based on PI compensation. 
![](AHRS/image-20221227164753828.png)

1.  pi compensation (related to PID control) It has two gains Ki and Kp compared to one gain K in standard Kalman filter.
2.  orientation error is the cross product between predicted acceleration and measured one. The reason is given below![](AHRS/image-20221227165009050.png)That is also why you need to normalize the acceleration vector.
3.  orientation increment from updated gyro
# KF

simple introduction of KF
https://ww2.mathworks.cn/en/videos/series/understanding-kalman-filters.html?s_eid=PSM_15028

# EKF

EKF example
"Multiple sensor fusion for mobile robot localization and navigation using the Extended Kalman Filter"
[07373480](IMU%20fusion/07373480.pdf)
- [x] #Ques How to combine measurement data fro different sensors into fomular. Is it simple addition？ 🛫 2022-12-27 ✅ 2022-12-29
 ![](IMU%20fusion/image-20221229150850791.png)
	observation transfomation matrix: H = [H1 H2], measurement vectot y = [y1 y2]T

# ESKF
simple introduction of ESFK
https://www.guyuehome.com/12615
https://zhuanlan.zhihu.com/p/152662055
https://notanymike.github.io/Error-State-Extended-Kalman-Filter/

[Quaternion kinematics for the error-state - Joan Sola](../../bookshelf/Joan%20Sola/Quaternion%20kinematics%20for%20the%20error-state%20Kalman%20filter%20(26)/Quaternion%20kinematics%20for%20the%20error-state%20-%20Joan%20Sola.pdf)
- [ ] #Ques  Why quarternion is used in eskf instead of other rotation vector? Can quarternion get applied in kf and ekf? 🛫 2023-01-10 | possible reason from [here](https://www.jianshu.com/p/20ca0a1d0b29) 一般优化用李代数  正常的旋转表示用四元数比较多。对于优化问题，最终要求H，也就是要求雅克比J，在李代数下，J的扰动求导是很方便的，而四元数的求导比较麻烦（或许）；而在滤波问题下，首先KF肯定不能用四元数，因为四元数非线性，用EKF的话四元数的状态变量也需要雅克比比较复杂。而用ESKF的话，一方面es是零均值的高斯分布，KF工作在原点附近，保证了线性化的合理性和有效性，而且**es总是很小，所以高阶项可以忽略，雅克比矩阵的计算非常简单迅速**

# UKF
[UKF](IMU%20fusion/UKF.pdf)

# Autonomous multiple model
[An Overview on Target Tracking Using Multiple Model Methods](IMU%20fusion/thesis.pdf)

![](IMU%20fusion/image-20221229172256550.png)

each model maintain its own kalman process, then the model probability is updated by procedure 2 shown in above table