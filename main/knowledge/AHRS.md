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
[zhihu-exlanation of mahoney algorithm](https://zhuanlan.zhihu.com/p/438724546)
[Mahony Filter code](https://github.com/PaulStoffregen/MotionCal/blob/master/mahony.c)
[AHRS in readthedocs.io](https://ahrs.readthedocs.io/en/latest/filters/angular.html)
[(video) sensor fusion provided by matlab](https://www.youtube.com/watch?v=0rlvvYgmTvI&list=PLn8PRpmsu08ryYoBpEKzoMOveSTyS-h4a&index=2)

### ❓Question

---

# Gravitation Estimation


The orientation estimate described above (calculated from accelerometer and magnetometer measurements) suffers from errors whenever the sensors are moved; averaged over time the accelerometer signal accurately measures the acceleration vector due to gravity, but over short time scales may be completely thrown off by accelerations from sensor movement. Considered in the frequency domain, our estimate will be accurate at low frequencies, but noisy at higher frequencies. We could smooth it efficiently by using an exponential moving average:

accel_mag_ema = a * accel_mag + (1 - a) * accel_mag_ema;







