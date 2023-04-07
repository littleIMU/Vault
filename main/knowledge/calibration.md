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
Up Level: (parent:: [SLAM](SLAM.md))

### Reference
https://blog.csdn.net/weixin_37835423/article/details/110672571
https://blog.csdn.net/tfb760/article/details/108532974
https://blog.csdn.net/u012700322/article/details/117021836

[A robost and esay to implement method for IMU calibration without external equipment.pdf](calibration/A_robust_and_easy_to_implement_method_for_IMU_calibration_without_external_equipments.pdf)
[Targetless Calibration of LIDAR-IMU System Based on Continuous-time Batch Estimation.pdf](calibration/Targetless%20Calibration%20of%20LiDAR-IMU%20System%20Based%20on%20Continuous-time%20Batch%20Estimation.pdf)

# IMU inner calibration

## error source
Low cost IMUs are affected by scaling factor, bias, [misalignment](https://www.analog.com/en/analog-dialogue/articles/mems-imu-gyroscope-alignment.html), etc..

## Gyroscope

[Inertial Sensor Noise Analysis Using Allan Variance](https://ww2.mathworks.cn/help/fusion/ug/inertial-sensor-noise-analysis-using-allan-variance.html) 
This example shows how to use the Allan variance to determine noise parameters of a MEMS gyroscope. These parameters can be used to model the gyroscope in simulation. The gyroscope measurement is modeled as:
$$\Omega(t) = \Omega_{Ideal}(t) + Bias_N(t) + Bias_B(t) + Bias_K(t)$$
The three noise parameters _N_ (angle random walk), _K_ (rate random walk), and _B_ (bias instability) are estimated using data logged from a stationary gyroscope.

[Here](https://github.com/nmayorov/allan-variance) demonstrates Simple Python functions to compute Allan variance and **estimate noise parameters** from it. The application in mind was analysis of random noise in inertial sensors. 

## example

[source](https://zhuanlan.zhihu.com/p/523610221?utm_id=0) 

