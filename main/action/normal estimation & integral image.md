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
link_knowledge: "[pcl](../knowledge/pcl.md)"
---

[使用积分图计算点云法向量_OTZ_2333的博客-CSDN博客](https://blog.csdn.net/OTZ_2333/article/details/107917018)

![Untitled](normal%20estimation%20&%20integral%20image/Untitled.png)

![Untitled](normal%20estimation%20&%20integral%20image/Untitled%201.png)

PCL中的积分图计算法向量方法
-  COVARIANCE_MATRIX：从邻域的协方差矩阵中创建9个积分图去计算一个点的法线
-  AVERAGE_3D_GRADIENT：创建了6个积分图去计算3D梯度里面垂直和水平方向的光滑部分，同时利用两个梯度的叉积来计算法线。
-  AVERAGE_DEPTH_CHANGE：只创建了一个单一的积分图，从平均深度的变化中计算法线。
-  SIMPLE_3D_GRADIENT：无任何介绍