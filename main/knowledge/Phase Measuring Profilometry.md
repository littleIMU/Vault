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

链接：[https://www.zhihu.com/question/54347759/answer/2137427446](https://www.zhihu.com/question/54347759)

来源：知乎

Code

[https://github.com/jakobwilm/slstudio](https://github.com/jakobwilm/slstudio)

以常见的相位轮廓测量术为例，它是通过获取物体相位信息来对物体轮廓进行还原的。

![https://pica.zhimg.com/80/v2-5e1168f01884da4143e25b0cbf2d97b7_720w.jpg?source=1940ef5c](https://pica.zhimg.com/80/v2-5e1168f01884da4143e25b0cbf2d97b7_720w.jpg?source=1940ef5c)

测量系统

窃用一下别人的图哈，看到传感需要的东西不多，只有投影仪和摄像机。投影仪投射[正弦条纹图](https://www.zhihu.com/search?q=%E6%AD%A3%E5%BC%A6%E6%9D%A1%E7%BA%B9%E5%9B%BE&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A2137427446%7D)到需要测量的物体上，因为物体轮廓是起伏的，条纹图发生扭曲变形。**[形光栅像](https://www.zhihu.com/search?q=%E5%BD%A2%E5%85%89%E6%A0%85%E5%83%8F&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A2137427446%7D)虽然是2D图像，但携带有3D信息，这些信息包含在相位里，通过解调相位能得到物体高度信息。**

相当于同一句话到不同人的嘴里说出来有不同的感觉，同样一幅条纹图投射到不同物体上会产生不同的形变，只要产生特定的变化，就隐含了物体的信息。

此处值得一提的是，立体（双目）视觉与结构光三维成像系统光学模型与成像原理较为类似——前者对视差进行三角化，从而计算物体的深度；后者中投影仪光学模型与摄像机光学模型基本一致，仅在方向上具有区别[1]，即可视作将“双目”其中一只“目”更改为[投影仪](https://www.zhihu.com/search?q=%E6%8A%95%E5%BD%B1%E4%BB%AA&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)。

因此，为实现目标物体点位的空间坐标，需要将投影仪所产生光线图案与摄像机所得到投影图像相结合。这一过程即需要对投影仪投影图案加以编码——先将投影仪“编码”，再利用摄像机“解码”，从而将编码视作投影仪与摄像机之间信息沟通的“桥梁”。

[Pattern for Structure Light](Pattern%20for%20Structure%20Light.md)

## 1 原理介绍

那么问题来了，物体高度与相位的关系是什么？

### 1.1 相位与高度的关系

![https://pic2.zhimg.com/80/v2-32b2ae02a8f18277f9f2830e0dd9c312_720w.jpg?source=1940ef5c](https://pic2.zhimg.com/80/v2-32b2ae02a8f18277f9f2830e0dd9c312_720w.jpg?source=1940ef5c)

先来点真实的，（a）是装置示意图，图像从光栅处打出，经过反射被探测器接收，底下的凸起是物体。

假如物体不存在，那么以探测器的视角，它应该看到[平面](https://www.zhihu.com/search?q=%E5%B9%B3%E9%9D%A2&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A2137427446%7D)上的C点，或者说，它应该看到平面上C点处反射的条纹。

而加入了物体后，探测器看到的条纹是原本应该打到平面上A点的，或者说，它看到了平面上A点处反射的条纹。

也就是说，**由于物体的存在，原本探测器应该观察到C点处的条纹，变为了[A点](https://www.zhihu.com/search?q=A%E7%82%B9&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A2137427446%7D)处的条纹**，即物体高度使条纹产生了偏移距离AC。

- 开始上公式，公式都比较简单。设投射到平面（参考面）的条纹周期为T，则由距离偏差AC产生的[相位差](https://www.zhihu.com/search?q=%E7%9B%B8%E4%BD%8D%E5%B7%AE&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A2137427446%7D)为：

[https://www.zhihu.com/equation?tex=%5CDelta+%5Cphi%3D2+%5Cpi+%5Ccdot+%5Cfrac%7BA+C%7D%7BT%7D](https://www.zhihu.com/equation?tex=%5CDelta+%5Cphi%3D2+%5Cpi+%5Ccdot+%5Cfrac%7BA+C%7D%7BT%7D)

- 由几何关系，能得到物体高度h与[距离AC](https://www.zhihu.com/search?q=%E8%B7%9D%E7%A6%BBAC&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A2137427446%7D)的关系。观察几何光路图，根据相似三角形ΔACD和ΔCEI，有：

[https://www.zhihu.com/equation?tex=%5Cfrac%7Bh%7D%7Bl%7D%3D%5Cfrac%7BA+C%7D%7BC+E%7D%3D%5Cfrac%7BA+C%7D%7BA+C%2Bd%7D](https://www.zhihu.com/equation?tex=%5Cfrac%7Bh%7D%7Bl%7D%3D%5Cfrac%7BA+C%7D%7BC+E%7D%3D%5Cfrac%7BA+C%7D%7BA+C%2Bd%7D)

- 当AC<<d，可化简为：

[https://www.zhihu.com/equation?tex=h%3DA+C+%5Ccdot+%5Cfrac%7Bl%7D%7Bd%7D](https://www.zhihu.com/equation?tex=h%3DA+C+%5Ccdot+%5Cfrac%7Bl%7D%7Bd%7D)

- 综上，**相位变化与高度的关系**为：

[https://www.zhihu.com/equation?tex=%5CDelta+%5Cphi%3D%5Cfrac%7B2+%5Cpi%7D%7BT%7D+%5Ccdot+h+%5Ccdot+%5Cfrac%7Bd%7D%7Bl%7D](https://www.zhihu.com/equation?tex=%5CDelta+%5Cphi%3D%5Cfrac%7B2+%5Cpi%7D%7BT%7D+%5Ccdot+h+%5Ccdot+%5Cfrac%7Bd%7D%7Bl%7D)

其中，T为参考面条纹周期，h为物体高度，d为投影仪与探测仪的距离，l为探测仪到参考面的距离

### 1.2 条纹的变化

![https://pic1.zhimg.com/80/v2-0ec209cfbc9af3ea35852ac8c1a5a622_720w.jpg?source=1940ef5c](https://pic1.zhimg.com/80/v2-0ec209cfbc9af3ea35852ac8c1a5a622_720w.jpg?source=1940ef5c)

我们进一步分析条纹图的变化。

- 正弦光栅投影光强为：

[https://www.zhihu.com/equation?tex=I_%7B0%7D%28x%2C+y%29%3DA%28x%2C+y%29%2BB%28x%2C+y%29+%5Ccos+%5Cphi%28x%2C+y%29](https://www.zhihu.com/equation?tex=I_%7B0%7D%28x%2C+y%29%3DA%28x%2C+y%29%2BB%28x%2C+y%29+%5Ccos+%5Cphi%28x%2C+y%29)

其中，光强I是相位φ的函数，A是背景光强，B是调制深度

- 不考虑反射比，物体反射条纹图光强为：

[https://www.zhihu.com/equation?tex=I_%7Br%7D%28x%2C+y%29%3DA%28x%2C+y%29%2BB%28x%2C+y%29+%5Ccos+%5Cphi_%7Br%7D%28x%2C+y%29](https://www.zhihu.com/equation?tex=I_%7Br%7D%28x%2C+y%29%3DA%28x%2C+y%29%2BB%28x%2C+y%29+%5Ccos+%5Cphi_%7Br%7D%28x%2C+y%29)

- 两者的区别就是相位差，根据前面分析，相位差是物体高度h的函数

[https://www.zhihu.com/equation?tex=%5Ccos+%5Cphi_%7Br%7D%28x%2C+y%29-%5Ccos+%5Cphi%28x%2C+y%29%3D%5CDelta+%5Cphi%3Dk+h%28x%2C+y%29](https://www.zhihu.com/equation?tex=%5Ccos+%5Cphi_%7Br%7D%28x%2C+y%29-%5Ccos+%5Cphi%28x%2C+y%29%3D%5CDelta+%5Cphi%3Dk+h%28x%2C+y%29)

其中，系数 k = 2 π / T · d / l

- 故**经物体高度调制后的条纹**为

[https://www.zhihu.com/equation?tex=I_%7Br%7D%3DR%5BA%2BB+%5Ccos+%28%5Cphi%2Bk+%5Ccdot+h%29%5D](https://www.zhihu.com/equation?tex=I_%7Br%7D%3DR%5BA%2BB+%5Ccos+%28%5Cphi%2Bk+%5Ccdot+h%29%5D)

### 1.3 相位的获取

条纹方程中有A、B、φ三个未知变量，求解时至少需要三个方程。我们这里采用四部移项法获取四个方程，对相位φ进行求解，具体作法如下。

![https://pic4.zhimg.com/80/v2-db4cf264fc17bcd5b3bff3b74b4979f2_720w.jpg?source=1940ef5c](https://pic4.zhimg.com/80/v2-db4cf264fc17bcd5b3bff3b74b4979f2_720w.jpg?source=1940ef5c)

投影条纹图时，拍摄4幅图片，每次条纹移动π/2相位，则有

[https://www.zhihu.com/equation?tex=%5Cbegin%7Barray%7D%7Bl%7D+I_%7B1%7D%3DA%2BB+%5Ccos+%28%5Cphi%29+%5C%5C+I_%7B2%7D%3DA%2BB+%5Ccos+%5Cleft%28%5Cphi%2B%5Cfrac%7B%5Cpi%7D%7B2%7D%5Cright%29+%5C%5C+I_%7B3%7D%3DA%2BB+%5Ccos+%28%5Cphi%2B%5Cpi%29+%5C%5C+I_%7B4%7D%3DA%2BB+%5Ccos+%5Cleft%28%5Cphi%2B%5Cfrac%7B3+%5Cpi%7D%7B2%7D%5Cright%29+%5Cend%7Barray%7D](https://www.zhihu.com/equation?tex=%5Cbegin%7Barray%7D%7Bl%7D+I_%7B1%7D%3DA%2BB+%5Ccos+%28%5Cphi%29+%5C%5C+I_%7B2%7D%3DA%2BB+%5Ccos+%5Cleft%28%5Cphi%2B%5Cfrac%7B%5Cpi%7D%7B2%7D%5Cright%29+%5C%5C+I_%7B3%7D%3DA%2BB+%5Ccos+%28%5Cphi%2B%5Cpi%29+%5C%5C+I_%7B4%7D%3DA%2BB+%5Ccos+%5Cleft%28%5Cphi%2B%5Cfrac%7B3+%5Cpi%7D%7B2%7D%5Cright%29+%5Cend%7Barray%7D)

1、3为符号相反的cos函数，2、4为符号相反的sin函数，两两做差可消去常数A，再通过比值消去常数B，解得相位φ为：

[https://www.zhihu.com/equation?tex=%5Cphi%3D%5Carctan+%5Cleft%28%5Cfrac%7BI_%7B4%7D-I_%7B2%7D%7D%7BI_%7B1%7D-I_%7B3%7D%7D%5Cright%29](https://www.zhihu.com/equation?tex=%5Cphi%3D%5Carctan+%5Cleft%28%5Cfrac%7BI_%7B4%7D-I_%7B2%7D%7D%7BI_%7B1%7D-I_%7B3%7D%7D%5Cright%29)

### 1.4 相位解包裹

注意，前面用arctan解出的相位值域只在-0.5π到0.5π间，是不连续的。为了从相位函数计算被测物体的高度分布，必须**将由于反三角运算引起的截断相位恢复成原有的相位分布**，这一过程称为相位展开，或相位解包裹。这一步是结构光三维传感最重要也是最难的一步。

![https://pic4.zhimg.com/80/v2-0c28a0a079d8e51ee04bb2cfff2da073_720w.jpg?source=1940ef5c](https://pic4.zhimg.com/80/v2-0c28a0a079d8e51ee04bb2cfff2da073_720w.jpg?source=1940ef5c)

也就是说，用反三角函数解出来的相位会有断裂点，因为真实情况相位值应该在负无穷到正无穷，而反三角函数的值域不是负无穷到正无穷。

举个例子，如果相位是0.6π，用acrtan解出来就是-0.4π。因为0.6π超出了值域最大值0.5π，多出的0.1π会从值域最小值-0.5π开始重新计算。

这里会有些难理解，我放图简单说明。

![https://pic2.zhimg.com/80/v2-215de97d329ffd385fbfe4c870e364bd_720w.jpg?source=1940ef5c](https://pic2.zhimg.com/80/v2-215de97d329ffd385fbfe4c870e364bd_720w.jpg?source=1940ef5c)

一维解包裹过程

上图为一维解包裹过程。其实实际解出的相位值域是在-π到π之间的，因为arctan函数的原因丢失了一半信息，这里不细谈。

（a）为包裹图，注意到图中超出π后的值从-π出现，同理超出-π后的值从π出现，我们要做的就是将间断处的值“缝补”起来。那么就要判断是否有间断，如果有，根据情况叠加一个相位值。（b）图就是做这样一件事，可以理解为解包裹叠加的相位。

具体的作法如下：

在展开的方向上比较相临两个点的相位值，

如果差值小于-2π·T，则后一点的相位值应该加上2π；

如果差值大于2π·T，则后一点的相位应该减2π。

其中T为阈值，范围在(0,1)，可以取T=0.5。

最后将（a）（b）两图做和运算，即可得到（c）图，即真实相位图。

### 1.5 物体轮廓还原

终于来到最后一步，还原物体轮廓。根据我们前面分析的物体高度与相位关系即可解出物体高度：

[https://www.zhihu.com/equation?tex=h%3D%5Cfrac%7BT%7D%7B2+%5Cpi%7D+%5Ccdot+%5Cfrac%7Bl%7D%7Bd%7D+%5Ccdot+%5CDelta+%5Cphi](https://www.zhihu.com/equation?tex=h%3D%5Cfrac%7BT%7D%7B2+%5Cpi%7D+%5Ccdot+%5Cfrac%7Bl%7D%7Bd%7D+%5Ccdot+%5CDelta+%5Cphi)

## 2 模拟仿真

已经分析完结构光三维传感的基本原理，使用Matlab可以对该过程进行简单的仿真，加深理解。

### 2.1 仿真流程

![https://pic1.zhimg.com/80/v2-bb9bde97126448b55c5c0ff69dbd5586_720w.jpg?source=1940ef5c](https://pic1.zhimg.com/80/v2-bb9bde97126448b55c5c0ff69dbd5586_720w.jpg?source=1940ef5c)

相位轮廓测量术

上图是结构光三维传感的完整流程，需要四幅参考面的条纹光强图与四幅有物体的变形条纹光强图，然后求解相位并解包裹，最后做差换算得到物体轮廓信息。

### 2.2 实验代码

```matlab
%% 结构光三维传感仿真实验

%% **********1.准备工作**********

%1.1参数设置
H = 640; %图像高度
W = 820; %图像宽度
N = 20; %条纹数
T = 2 * H / N;%条纹周期
A = 1; %背景光强
B = 1; %调制深度
d = 20; %投影仪与摄像机距离
l = 100; %摄像机与参考面距离

%1.2初始数据生成
pha = linspace(0,N*2*pi,H); %相位变化
pha = repmat(pha',1,W); %相位面（横向条纹）
I = cell(2,4);%记录光强信息

%% **********2.参考面条纹图**********

%2.1光强图生成
for i=0:3
    I0 = A + B * cos( pha + i*pi/2 ); %光强
    I{1,i+1}=I0;%记录光强
    figure(i+1); %弹出窗口
    imshow(I0,[]); %图像显示
end

%% **********3.物体投影条纹图**********

%3.1创建一个物体(方块)
size_ = 121; %物体尺寸
height = 40; %物体高度
obj = height * ones(size_);%高度矩阵

%3.2设置物体位置(中心)
pos = [H/2,W/2];%物体坐标(行,列)
R = fix(pos(1)-size_/2);
C = fix(pos(2)-size_/2);

%3.3光强图生成
for i=0:3
    Ir = A + B * cos( pha + i*pi/2 ); %光强
    Ir(R:R+size_-1,C:C+size_-1)=A+B*cos(pha(R:R+size_-1,C:C+size_-1)+2*pi/T*obj*d/l+i*pi/2); %加入物体后修正光强
    I{2,i+1}=Ir;%记录光强
    figure(i+5); %弹出窗口
    imshow(Ir,[]); %图像显示
end

%% **********4.未解包裹相位图**********

%4.1相位计算
%参考面
pha0 = atan2(I{1,1}-I{1,3},I{1,4}-I{1,2});
%物体投影
phar = atan2(I{2,1}-I{2,3},I{2,4}-I{2,2});

%4.2三维图绘制
x=linspace(0,N*2*pi,W);
y=linspace(0,N*2*pi,H);
figure(9);
mesh(x,y,pha0);
figure(10);
mesh(x,y,phar);

%% **********5.解包裹相位图**********

%5.1解包裹
for i=1:H
    pha0(i,:)=unwrap(pha0(i,:));
end
for j=1:W
    pha0(:,j)=unwrap(pha0(:,j));
end
for i=1:H
    phar(i,:)=unwrap(phar(i,:));
end
for j=1:W
    phar(:,j)=unwrap(phar(:,j));
end

%5.2三维图绘制
figure(11);
mesh(x,y,pha0);
figure(12);
mesh(x,y,phar);

%% **********6.物体轮廓还原**********

pha = pha0 - phar;
h = T / ( 2 * pi ) * l / d * pha;
figure(13);
mesh(x,y,h);
```

### 2.3 实验结果

**条纹图**

![https://pic3.zhimg.com/80/v2-837515df399fd90215c1395e28b338ae_720w.jpg?source=1940ef5c](https://pic3.zhimg.com/80/v2-837515df399fd90215c1395e28b338ae_720w.jpg?source=1940ef5c)

参考面条纹图

![https://pica.zhimg.com/80/v2-e534bb8b68f46abdd313ea85c135c13a_720w.jpg?source=1940ef5c](https://pica.zhimg.com/80/v2-e534bb8b68f46abdd313ea85c135c13a_720w.jpg?source=1940ef5c)

物体条纹图

**解调相位**

![https://pic1.zhimg.com/80/v2-a112ba092bd644a565fc7fc0d5e4b94d_720w.jpg?source=1940ef5c](https://pic1.zhimg.com/80/v2-a112ba092bd644a565fc7fc0d5e4b94d_720w.jpg?source=1940ef5c)

（左）参考面，（右）物体

**解包裹相位**

![https://pic1.zhimg.com/80/v2-f081f6d5fa03bdb48369ffb0d0b1f6e4_720w.jpg?source=1940ef5c](https://pic1.zhimg.com/80/v2-f081f6d5fa03bdb48369ffb0d0b1f6e4_720w.jpg?source=1940ef5c)

（左）参考面，（右）物体

**物体高度**

![https://pic3.zhimg.com/80/v2-3fea1499725ce90bbad1c376b31783de_720w.jpg?source=1940ef5c](https://pic3.zhimg.com/80/v2-3fea1499725ce90bbad1c376b31783de_720w.jpg?source=1940ef5c)

还原轮廓