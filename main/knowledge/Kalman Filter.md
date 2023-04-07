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
Up Level: (parent:: [Recursive Bayesian Estimation](Recursive%20Bayesian%20Estimation.md))

### Reference 

[Kalman filter and smoother.pdf](Kalman%20Filter/Kalman%20filter%20and%20smoother.pdf)

# Intuitive 
![](Kalman%20Filter/image-20230130135633655.png)

[Understanding Kalman Filters, Parts 3: An Optimal State Estimator](https://ww2.mathworks.cn/en/videos/understanding-kalman-filters-part-3-optimal-state-estimator--1490710645421.html)
[一元，多元和混合高斯模型的区别, gaussian distribution](https://zhuanlan.zhihu.com/p/93547138)
[用EM求解混合高斯模型的参数，gaussian distribution](https://www.cnblogs.com/jiangxinyang/p/9278608.html)

# Mathematical Derivation

![](Kalman%20Filter/Untitled.png)
❕ More detail in P46 of “Probabilistic Robotics.pdf”
you can also find an easy understanding in [Kalman filter and smoother](Kalman%20Filter/Kalman%20filter%20and%20smoother.pdf) with the base knowledge of the properties of multimodal normal distribution


# Algorithm

Prerequisites: Linear function and Gaussian Noise

![](Kalman%20Filter/Untitled%201.png)

covariance matrix

correlation

![](Kalman%20Filter/Untitled%202.png)

![](Kalman%20Filter/Untitled%203.png)

# kalman smoother

RST is a backward type of kalman filter, more detai is in [here](Kalman%20Filter/Kalman%20filter%20and%20smoother.pdf)