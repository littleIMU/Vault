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
Up Level: (parent:: [PCA](PCA.md))

### reference

[使用PCA拟合平面(Plane Fitting using PCA)](https://blog.csdn.net/xiaocainiaodeboke/article/details/77150884)

---

![](PCA%20&%20Normal%20Vector/Untitled.png)

协方差矩阵的最大特征向量总是指向数据最大方差的方向，并且该向量的幅度等于相应的特征值。第二大特征向量总是正交于最大特征向量，并指向第二大数据的传播方向。

为啥需要转换成特征向量和特征值: 可以清楚地看到特征值表示沿特征向量方向数据的方差，而协方差矩阵的方差分量表示沿轴的传播