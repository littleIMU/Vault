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
link_knowledge: 
---
Up Level: (parent:: [algorithm](algorithm.md))
#U
```toc
```
### 📇Reference
[IMU Sensor Fusion with exponentional filter](https://josephmalloch.wordpress.com/portfolio/imu-sensor-fusion/)
[Mahony Filter](https://github.com/PaulStoffregen/MotionCal/blob/master/mahony.c)

### ❓Question

---

# Gravitation Estimation


The orientation estimate described above (calculated from accelerometer and magnetometer measurements) suffers from errors whenever the sensors are moved; averaged over time the accelerometer signal accurately measures the acceleration vector due to gravity, but over short time scales may be completely thrown off by accelerations from sensor movement. Considered in the frequency domain, our estimate will be accurate at low frequencies, but noisy at higher frequencies. We could smooth it efficiently by using an exponential moving average:

accel_mag_ema = a * accel_mag + (1 - a) * accel_mag_ema;

# Mahony Filter

1.  pi compensation (related to PID control) It has two gains Ki and Kp compared to one gain K in standard Kalman filter.
2.  predicted orientation is calculated with quaternion or quaternion and magnetic field
3.  orientation error is the cross matrix between Acceleration and predicted orientation.
4.  orientation increment from updated gyro





