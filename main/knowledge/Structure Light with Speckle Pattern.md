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
Up Level: (parent:: [Structure Light](Structure%20Light.md))


### Reference

[基于散斑 结构光 - 搜索结果 - 知乎](https://www.zhihu.com/search?type=content&q=%E5%9F%BA%E4%BA%8E%E6%95%A3%E6%96%91%20%E7%BB%93%E6%9E%84%E5%85%89)

---

由激光模组发射[散斑](https://www.zhihu.com/search?q=%E6%95%A3%E6%96%91&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A%222476994962%22%7D)打在物体上（如图中O点），然后由IR模组接收由不同距离物体反射回来的散斑（如图中的成像点K1点），对于激光发出的同一射线[PO](https://www.zhihu.com/search?q=PO&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A%222476994962%22%7D),经过参考平面上的R点，在IR sensor上的成像点为R1 。

因此，对于R1和K1来说，该成像点实际上同一射线在不同距离下的[投影点](https://www.zhihu.com/search?q=%E6%8A%95%E5%BD%B1%E7%82%B9&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A%222476994962%22%7D)，这组匹配点位置的差作为视差d， 而O到相机平面的距离称之为深度z。

所以，z与视差d的相关可以根据[相似三角形](https://www.zhihu.com/search?q=%E7%9B%B8%E4%BC%BC%E4%B8%89%E8%A7%92%E5%BD%A2&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A%222476994962%22%7D)得知：

![https://picx.zhimg.com/80/v2-c01ce5dbc0b4a0401b16c4425a8dd6b7_720w.jpg](https://picx.zhimg.com/80/v2-c01ce5dbc0b4a0401b16c4425a8dd6b7_720w.jpg)

![https://pica.zhimg.com/80/v2-b11640b450523baa457e4eebaccd6b70_720w.jpg](https://pica.zhimg.com/80/v2-b11640b450523baa457e4eebaccd6b70_720w.jpg)

b：基线长度，设备的激光模组和ir模组之间的距离； f：焦距 ；Z0: 参考平面的距离；d : 视差

d, f和z0这三个参数与产品设计有关系，而单目结构光最关键的技术就是计算视差，如何找到当前场景中的散板点和参考图上的散斑点事激光发射的同一点，那么最关键就属匹配算法了。

奥比中光的结构光，匹配算法是由自主研发的深度引擎处理芯片，已经量产的芯片有MX400、MX6000和MX6300等等。

**写在最后：**上述结构光的数学模型是一个比较理想模型，可以自己思考。但是，当IR Sensor平面与基线方向不平行时，上述的相似三角形就需要变化了。