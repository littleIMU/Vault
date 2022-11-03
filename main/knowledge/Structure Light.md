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
Up Level: (parent:: [3D Depth Camera](3D%20Depth%20Camera.md))

结构光三维重建方法

- Fourier Transform Profilometry
    
    [傅里叶变换轮廓术Fourier Transform Profilometry（FTP）_明天的阵雨的博客-CSDN博客_傅里叶变换轮廓术](https://blog.csdn.net/u010430651/article/details/95212540)
    
    [傅里叶变换轮廓术（FTP）matlab模拟_明天的阵雨的博客-CSDN博客_傅里叶变换轮廓术原理](https://blog.csdn.net/u010430651/article/details/96484972)
    
- Phase Measuring Profilometry
    
    [Phase Measuring Profilometry](Phase%20Measuring%20Profilometry%2040478c0c220c4c2fa3f507861dcea427.md) 
    
- Profilometry based on speckle pattern
    
    [Structure Light with Speckle Pattern](Structure%20Light%20with%20Speckle%20Pattern%2040a3afeb96e14789b44f819b2a02b5b4.md) 
    

# 单次投影成像

单次投影结构光主要采用空间复用编码和频率复用编码形式实现 ,常用的编码形式有:彩色编码 、灰度索引、 几何形状编码和随机斑点. 目前在机器人手眼系统应用中,对于三维测量精度要求不高的场合,如码垛、拆垛、三维抓取等,比较受欢迎的是投射伪随机斑点获得目标三维信息 。

1. One-shot pattern projection for dense and accurate 3D acquisition in structured light
2. A single-shot structured light means by encoding both color and geometrical features
3. Dynamic 3D surface profilometry using a novel colour pattern encoded with a multiple triangular mode
4. Review of single-shot 3D shape measurement by phase calculation-based fringe projection techniques
5. Robust pattern decoding in shape-coded structured light

# 多次投影成像

多次投影3D方法主要采用时间复用编码方式实现,常用的图案编码形式有:二进制编码、多频相移编码和混合编码法(如格雷码＋相移条纹)等.但是格雷码方法仅能在投射空间内进行离散的划分,空间分辨率受到成像器件的限制. 为了提高空间分辨率,需要增加投影条纹幅数,投射条纹宽度更小的格雷码条纹图,但条纹宽度过小会导致格雷码条纹的边缘效应,从而引 起解码误差.正弦光栅条纹投影克服了格雷码空间离散划分的缺点,成为使用率最高的结构光类型之一. 众所周知,对于复杂外形,如有空洞、阶梯、遮挡等,采用正弦单频相移法条纹投影时,存在相位解包裹难题.另外为了能够从系列条纹图中求出相位绝对值,需要在条纹中插入特征点,比如一个点、一条线作为参考相位点,但是这些点或线特征标志有可能投影在物体的遮挡或阴影区域,或受到环境光等干扰等,发生丢失,影响测量结果的准确性. 因此,对于复杂轮廓的物体,常采用多频相移技术.

1. 三维重建的格雷码-相移光编码技术研究
2. Pattern codification strategies in structured light systems
3. Binary coded linear fringes for three-dimensional shape profiling
4. 3D shape measurement based on complementary Gray-code light
5. Phase shifting algorithms for fringe projection profilometry: a review
6. Overview of the 3D profilometry of phase shifting fringe projection
7. Temporal phase unwrapping algorithms for fringe projection profilometry:a comparative review
8. A multi-frequency inverse-phase error compensation method for projectornon linear in3D shape measurement

# 偏折法成像

对于粗糙表面,结构光可以直接投射到物体表面进行视觉成像测量;但对于大反射率光滑表面和镜面物体3D 测量,结构光投影不能直接投射到被测表面,3D测量还需要借助镜面偏折技术 .

1. Principles of shape from specular reflection
2. Deflectometry: 3D-metrology from nanometer to meter
3. Three-dimensional shape measurement of a highly reflected specular surface with structured light method
4. Three-dimensional shape measurements of specular objects using phase-measuring deflectometry

由于单次投影曝光和测量时间短,抗振动性能好,适合运动物体的3D测量,如机器人实时运动引导,手眼机器人对生产线上连续运动产品进行抓取等操作. 但深度垂直方向上的空间分辨率受到目标视场、镜头倍率和相机像素等因素的影响,大视场情况下不容易提升。多次投影方法(如多频条纹方法)具有较高空间分辨率,能有效地解决表面斜率阶跃变化和空洞等难题. 不足之处在于:

1. 对于连续相移投影方法,3D重构的精度容易受到投影仪、相机的非线性和环境变化的影响;
2. 抗振动性能差,不合适测量连续运动的物体;
3. 在Eye-in-Hand视觉导引系统中,机械臂不易在连续运动时进行3D成像和引导;
4. 实时性差,不过随着投影仪投射频率和CCD/CMOS图像传感器采集速度的提高,多次投影方法实时3D 成像的性能也在逐步改进；

偏折法对于复杂面型的测量,通常需要借助多次投影方法,因此具有多次投影方法相同的缺点.另外偏折法对曲率变化大的表面测量有一定的难度,因为条纹偏折后的反射角的变化率是被测表面曲率变化率的２倍,因此对被测物体表面的曲率变化比较敏感,很容易产生遮挡难题.

# Other Papers

1. 基于面结构光的三维重建阴影补偿算法
2. [Enhanced phase measurement profilometry for industrial 3D inspection automation](https://link.zhihu.com/?target=https%3A//www.researchgate.net/publication/273481900_Enhanced_phase_measurement_profilometry_for_industrial_3D_inspection_automation)
3. [Profilometry of three-dimensional discontinuous solids by combining two-steps temporal phase unwrapping, co-phased profilometry and phase-shifting interferometry](https://link.zhihu.com/?target=http%3A//xueshu.baidu.com/usercenter/paper/show%3Fpaperid%3D3056d2277236112a708e4746a73e1e1d%26site%3Dxueshu_se)
4. [360-Degree Profilometry of Discontinuous Solids Co-Phasing ２-Projectors and１-Camera](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
5. [Coherent digital demodulation of single-camera N-projections for 3D-object shape measurement Co-phased profilometr](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
6. [High-speed 3D image acquisition using coded structured light projection](https://link.zhihu.com/?target=https%3A//www.researchgate.net/publication/224296439_High-speed_3D_image_acquisition_using_coded_structured_light_projection)
7. [Accurate 3D measurement using a Structured Light System](https://link.zhihu.com/?target=https%3A//www.researchgate.net/publication/222500455_Accurate_3D_measurement_using_a_Structured_Light_System)
8. [Structured light stereoscopic imaging with dynamic pseudo-random patterns](https://link.zhihu.com/?target=https%3A//static.aminer.org/pdf/PDF/000/311/975/a_high_precision_d_object_reconstruction_method_using_a_color.pdf)
9. [Robust one-shot 3D scanning using loopy belief propagation](https://link.zhihu.com/?target=https%3A//www.researchgate.net/publication/224165371_Robust_one-shot_3D_scanning_using_loopy_belief_propagation)
10. [Robust Segmentation and Decoding of a Grid Pattern for Structured Light](https://link.zhihu.com/?target=https%3A//www.semanticscholar.org/paper/Robust-Segmentation-and-Decoding-of-a-Grid-Pattern-Pag%25C3%25A8s-Salvi/dcbdd608dcdf03b0d0eba662c68915dcfa90e5a5)
11. [Rapid shape acquisition using color structured light and multi-pass dynamic programming](https://link.zhihu.com/?target=http%3A//ieeexplore.ieee.org/iel5/7966/22019/01024035.pdf%3Farnumber%3D1024035)
12. [Improved stripe matching for colour encoded structured light](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
13. [Absolute phase mapping for one-shot dense pattern projection](https://link.zhihu.com/?target=https%3A//www.researchgate.net/profile/Joaquim_Salvi/publication/224165341_Absolute_phase_mapping_for_one-shot_dense_pattern_projection/links/56ffaee708ae650a64f805dd.pdf)
14. [3D digital stereophotogrammetry: a practical guide to facial image acquisition](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
15. [Method and apparatus for 3D imaging using light pattern having multiple sub-patterns](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
16. [High speed laser three-dimensional imager](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
17. [Three-dimensional dental imaging method and apparatus having a reflective member](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
18. [3D surface profile imaging method and apparatus using single spectral light condition](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
19. [Three-dimensional surface profile imaging method and apparatus using single spectral light condition](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
20. [High speed three dimensional imaging method](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
21. [A hand-held photometric stereo camera for 3-D modeling](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
22. [High-resolution, real-time 3D absolute coordinate measurement based on a phase-shifting method](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)
23. [A fast three-step phase shifting algorithm](https://link.zhihu.com/?target=https%3A//github.com/Tom-Hardy-3D-Vision-Workshop/awesome-3D-vision/blob/master)

# Code

1. [https://github.com/jakobwilm/slstudio](https://link.zhihu.com/?target=https%3A//github.com/jakobwilm/slstudio)
2. [https://github.com/phreax/structured_light](https://link.zhihu.com/?target=https%3A//github.com/phreax/structured_light)
3. [https://github.com/nikolaseu/neuvision](https://link.zhihu.com/?target=https%3A//github.com/nikolaseu/neuvision)
4. [https://github.com/pranavkantgaur/3dscan](https://link.zhihu.com/?target=https%3A//github.com/pranavkantgaur/3dscan)