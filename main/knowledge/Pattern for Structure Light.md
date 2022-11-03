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

作者：疯狂学习GIS

链接：https://www.zhihu.com/question/54347759/answer/1869589336

来源：知乎

著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

立体（双目）视觉与结构光三维成像系统光学模型与成像原理较为类似——前者对视差进行三角化，从而计算物体的深度；后者中投影仪光学模型与摄像机光学模型基本一致，仅在方向上具有区别[1]，即可视作将“双目”其中一只“目”更改为[投影仪](https://www.zhihu.com/search?q=%E6%8A%95%E5%BD%B1%E4%BB%AA&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)。

因此，为实现目标物体点位的空间坐标，需要将投影仪所产生光线图案与摄像机所得到投影图像相结合。这一过程即需要对投影仪投影图案加以编码——先将投影仪“编码”，再利用摄像机“解码”，从而将编码视作投影仪与摄像机之间信息沟通的“桥梁”。

# 2 编码结构光编码方式

依据不同角度，可将结构光投影图案所对应多种编码方法加以类别区分。依据文献[3]，由编码策略角度，将结构光的编码方法分为**时间编码、[空间编码](https://www.zhihu.com/search?q=%E7%A9%BA%E9%97%B4%E7%BC%96%E7%A0%81&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)**与**直接编码**。

![https://pica.zhimg.com/80/v2-ecd01a51a09d491466c73b1deba881ac_720w.jpg?source=1940ef5c](https://pica.zhimg.com/80/v2-ecd01a51a09d491466c73b1deba881ac_720w.jpg?source=1940ef5c)

*图3 编码结构光编码方式*

**时间编码**方法依据时间顺序依次产生多种投影图案，并以像元为单位分别对其加以编号；其可进一步分为二值编码、[n值编码](https://www.zhihu.com/search?q=n%E5%80%BC%E7%BC%96%E7%A0%81&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)、时间编码与相移法结合，以及混合编码等四类。其中，二值编码还可继续分为普通二值码（以m个图案编码2m个条纹）与[格雷码](https://www.zhihu.com/search?q=%E6%A0%BC%E9%9B%B7%E7%A0%81&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)（减少普通二值码条纹边界数）；n值编码需建立一张码值表，码值与特定RGB颜色或灰度对应，是对二值编码的泛化；时间编码与[相移法](https://www.zhihu.com/search?q=%E7%9B%B8%E7%A7%BB%E6%B3%95&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)结合可获得较高空间分辨率，且对像元编码准确；混合编码则可在投影图案数量较少时获得较高的精度。时间编码方法整体实现过程简单，空间分辨率较高；但其执行过程中需投影多幅图案，故只适合于静态场景测量。

**空间编码**方法中各点码字由其周围临近点像素值、形状等信息得到；其可进一步分为非正式编码、基于德布鲁因（de Bruijn）[序列编码](https://www.zhihu.com/search?q=%E5%BA%8F%E5%88%97%E7%BC%96%E7%A0%81&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)与基于M-阵列编码三类。其中，非正式编码依据各区域信息（如条纹间隔信息）产生码字；基于德布鲁因序列编码借助欧拉圈或哈密顿圈[6]，生成de Bruijn序列作为编码；基于[M-阵列编码](https://www.zhihu.com/search?q=M-%E9%98%B5%E5%88%97%E7%BC%96%E7%A0%81&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)利用并圈剪接法、代数生成法等获得M-阵列，从而获取各点码值。空间编码方法只需一副投影图案，适用于动态场景的三维信息获取；而其[空间分辨率](https://www.zhihu.com/search?q=%E7%A9%BA%E9%97%B4%E5%88%86%E8%BE%A8%E7%8E%87&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)较之时间编码方法较低，且在解码阶段，可能由于空间邻近点信息丢失而导致误差产生。

**直接编码**方法则对各像元分别加以编码；其可进一步分为灰度直接编码与彩色直接编码两类。其中，[灰度](https://www.zhihu.com/search?q=%E7%81%B0%E5%BA%A6&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)直接编码依据图像中各像元像素值与其在均匀强度光照下像素值之比实现编码；彩色直接编码则利用[彩虹图案](https://www.zhihu.com/search?q=%E5%BD%A9%E8%99%B9%E5%9B%BE%E6%A1%88&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)编码模式对前者加以改进。直接编码方法需利用较多颜色或周期性以得到高分辨率投影图案；而其编码图像各像元间[色差](https://www.zhihu.com/search?q=%E8%89%B2%E5%B7%AE&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)较小，对噪声敏感；且图像颜色易受到测量表面颜色影响，其应用往往局限于中性颜色或灰、白色物体。

编码结构光不同编码方式从属关系如图3所示。

除上述内容外，结构光编码方式还有许多其他分类方法，如依据像元取值可分为二值编码、灰度编码与彩色编码；依据编码周期可分为[周期编码](https://www.zhihu.com/search?q=%E5%91%A8%E6%9C%9F%E7%BC%96%E7%A0%81&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)与绝对编码等[3]。

# 3 编码结构光与侧影轮廓方法比较

通过学习、理解与查阅相关文献，可以感受到编码结构光与[侧影](https://www.zhihu.com/search?q=%E4%BE%A7%E5%BD%B1&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)轮廓方法的异同。

在**三维信息获取方法**层面，编码结构光方法与侧影轮廓方法均属于[非接触式方法](https://www.zhihu.com/search?q=%E9%9D%9E%E6%8E%A5%E8%A7%A6%E5%BC%8F%E6%96%B9%E6%B3%95&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)，即二者在执行时均无需直接与目标物体接触，而是采取利用一定仪器设备拍摄物体图像的方式（或许其亦可以视作一种广义的[遥感](https://www.zhihu.com/search?q=%E9%81%A5%E6%84%9F&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)）获取信息；其中，前者由于需要自身投影仪作为光源，因此属于主动方法；后者由于直接利用目标物体的[多角度](https://www.zhihu.com/search?q=%E5%A4%9A%E8%A7%92%E5%BA%A6&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)图像，即直接运用成像时太阳光或其它外部光源等，因此属于被动方法。

在**模型建立方法原理**层面，如前所述，编码结构光方法利用摄像机获取投影仪所发射出光线在目标物体表面的分布特征，并通过对不同的光线分布方式加以编码，由此建立物体位置、投影仪坐标与摄像机坐标之间的联系，进而利用三角化方法求解目标物体当前位置所处的空间坐标信息；如前所述，这一原理与[双目视觉基本原理](https://www.zhihu.com/search?q=%E5%8F%8C%E7%9B%AE%E8%A7%86%E8%A7%89%E5%9F%BA%E6%9C%AC%E5%8E%9F%E7%90%86&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)（即对视差进行三角化进而求解物体深度）较为近似[1]。而侧影轮廓方法则借助可见外壳（Visual Hull）——即当以透视投影方式由多视角观察目标对象时，各视角对应画面均可得到一条该物体侧影轮廓线，此侧影轮廓线与对应透视投影中心共同确定三维空间中一个一般形状锥体，而所观察对象物体便位于这一[立体锥体](https://www.zhihu.com/search?q=%E7%AB%8B%E4%BD%93%E9%94%A5%E4%BD%93&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)内部。不断由不同方向增加目标物体的观测视角数量，可使得各对应锥体外形不断逼近对象物体表面，从而对目标物体外形特征加以空间三维可视化。

在**所获取物体信息**层面，编码结构光方法依据所拍摄图像，分别获取目标物体外形细节与纹理信息，其中外形细节包括物体表面的[内陷](https://www.zhihu.com/search?q=%E5%86%85%E9%99%B7&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)部分等；外形细节通过光线在物体表面的弯曲、形变等信息获取，纹理信息则直接由普通拍摄方式所得图像中物体纹理获取。侧影轮廓方法则直接依据目标物体多角度图像，分别获取物体表面形状与纹理信息。由于侧影轮廓方法对物体表面形状的获取是依据不同多角度图像的目标区域边缘（即目标物体区域与背景等非目标区域交界处）加以实现，因此其难免会丢失物体表面部分内陷区域信息。

在**操作流程**层面，编码结构光方法与侧影轮廓方法均需要“定标操作”；这是由于两种方法均需依据所拍摄图像对目标物体位置加以确定。而侧影轮廓方法定标操作较为简单，仅需对拍摄多角度图像所用相机加以定标，目前已有基于平面镜的相机内参标定方法、基于[几何](https://www.zhihu.com/search?q=%E5%87%A0%E4%BD%95&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)的成角度平面镜装置相机标定方法等。而对于编码结构光方法，除了需要对相机定标外，还需要对投影仪的亮度、几何等加以定标[1]。这是由于其编码往往与投影仪所辐射出光线的亮度、颜色或位置分布等具有关系。

# 4 编码结构光方法流程

进行编码结构光方法的执行，需要首先搭建一个完整的编码结构光系统，即由摄像机、投影仪与计算机系统三者所组成的整体。编码结构光系统的视觉模型示意图如图2所示。

搭建完成后，需要对系统进行标定，定标的结果直接决定三维系统的重建精度。其中，定标包括相机定标与投影仪定标，投影仪定标又可继续分为投影仪亮度定标与投影仪几何标定[1]。相机定标即建立传感器中点与空间中过光心的直线之间对应关系，如[平板定标算法](https://www.zhihu.com/search?q=%E5%B9%B3%E6%9D%BF%E5%AE%9A%E6%A0%87%E7%AE%97%E6%B3%95&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)[7]；投影仪亮度定标将使得系统实际所得投影图像亮度与投影仪投影图像的亮度值满足线性关系，从而使得[亮度值](https://www.zhihu.com/search?q=%E4%BA%AE%E5%BA%A6%E5%80%BC&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)可被用来恢复该点在投影仪成像平面的坐标；投影仪几何标定用以确定目标物体表面某点空间位置与投影仪平面像素点的对应关系。

定标完成后，依据所选择策略生成编码图像。如前所述，图像具有多种编码方式，如时间编码、空间编码、直接编码等。图像编码后，将其导入投影仪中，并由投影仪将其投射至目标物体表面。同时，由摄像机拍摄投影后的目标物体，通过[解码](https://www.zhihu.com/search?q=%E8%A7%A3%E7%A0%81&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)方式获取原有编码图像在目标物体表面各位置的分布情况，从而获取能够反映目标物体表面特征的[点云文件](https://www.zhihu.com/search?q=%E7%82%B9%E4%BA%91%E6%96%87%E4%BB%B6&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)。以本文所用EinScan-S series_v2.7.0.6软件为例，可以看到其所得到的目标物体模型表面亦为由点云组成的实体，如图4所示。

![https://pic3.zhimg.com/80/v2-cfb5efcea654e484f1953376d76aa948_720w.jpg?source=1940ef5c](https://pic3.zhimg.com/80/v2-cfb5efcea654e484f1953376d76aa948_720w.jpg?source=1940ef5c)

*图4 点云示意图*

获取点云文件后，对其进行相关后处理操作，对所生成目标物体表面进行后续补充、优化等，并最终显示建模结果。

编码结构光方法流程如图5所示。

![https://pica.zhimg.com/80/v2-8762215cf9fec131a722dc28e0ca1540_720w.jpg?source=1940ef5c](https://pica.zhimg.com/80/v2-8762215cf9fec131a722dc28e0ca1540_720w.jpg?source=1940ef5c)

*图5 编码结构光方法流程*

具体的**结构光[三维建模](https://www.zhihu.com/search?q=%E4%B8%89%E7%BB%B4%E5%BB%BA%E6%A8%A1&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra=%7B%22sourceType%22%3A%22answer%22%2C%22sourceId%22%3A1869589336%7D)实现方法**，大家可以查看这边文章：

[基于EinScan-S的编码结构光方法空间三维模型重建](https://zhuanlan.zhihu.com/p/369870047)