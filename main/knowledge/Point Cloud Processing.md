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

### Reference

1. [Planar segmentation](https://pcl.readthedocs.io/projects/tutorials/en/latest/planar_segmentation.html#the-explanation)
2. [pcd files for tutorials]((https://github.com/PointCloudLibrary/data)) 
- [Semantic 3D Object Maps for Every day Mani - Radu Bogdan Rusu](../../bookshelf/Radu%20Bogdan%20Rusu/Semantic%203D%20Object%20Maps%20for%20Every%20day%20Manipulation%20in%20Human%20Living%20Environments%20(25)/Semantic%203D%20Object%20Maps%20for%20Every%20day%20Mani%20-%20Radu%20Bogdan%20Rusu.pdf)

###  Question

- [ ]  what is the unit for “setLeafSize()”
- [ ]  how to get the surface in “the underlying neighboring surface given in **setSearchSurface()** will be used to obtain nearest neighbors for the input points”
- [ ]  What is an organized dataset for normal estimation using integral images?
- [x]  the relation between pca and point normal? [PCA & Normal Vector](PCA%20&%20Normal%20Vector%20eec420b78906442db0a573de6c071e65.md)
- [x]  Is PFH applied for every point? No, but every point calculates the feature.
- [ ]  What does the histogram mean? put four features  into histogram
- [ ]  How to match after you get these histogram?
- [x]  How to section the points(how to decide the query point)? for each point. `pfh.setRadiusSearch (0.05);` //*`the radius used here has to be larger than the radius used to estimate the surface normals!!!`*
- [x]  In PFH, why the number is “”create a histogram with b^4 bins in a fully correlated space?  each feature out of four features has its own histogram.
- [ ]  In NARF, why s(right) need to be updated depending on the score of shadow?
- [ ]  In NARF, how to “perform non-maximum suppression to find the exact
border position”?
- [ ]  In NARF, what is the average object size in “We found in our experiments, that 25% of the average object size is a reasonable value”
- [ ]  In NARF, what is the descriptor? why use beam pattern?

---

# Input passing

[How 3D Features work in PCL](https://pcl.readthedocs.io/projects/tutorials/en/latest/how_features_work.html#how-3d-features-work)

Three inputs to estimate surface normals

```cpp
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>

{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

  ... read, pass in or create a point cloud ...

  // Create the normal estimation class, and pass the input dataset to it
  pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
	// this will estimate a set of surface normals for all points
  ne.setInputCloud (cloud);
	
	// this will estimate a set of surface normals for point in indices
	std::vector<int> indices (std::floor (cloud->size () / 10));
  for (std::size_t i = 0; i < indices.size (); ++i) indices[i] = i;
	ne.setInputCloud (cloud);
	ne.setIndices (indicesptr);

	// this will estimate a set of surface normals for points which in the surface of original cloudpoint.
	ne.setInputCloud (cloud_downsampled);
  ne.setSearchSurface (cloud);

  // Create an empty kdtree representation, and pass it to the normal estimation object.
  // Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
  pcl::search::KdTree<pcl::PointXYZ>::Ptr tree (new pcl::search::KdTree<pcl::PointXYZ> ());
  ne.setSearchMethod (tree);

  // Output datasets
  pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);

  // Use all neighbors in a sphere of radius 3cm
  ne.setRadiusSearch (0.03);

  // Compute the features
  ne.compute (*cloud_normals);

  // cloud_normals->size () should have the same size as the input cloud->size ()
}
```

The most useful example when **setSearchSurface()** should be used, is when we have a very dense input dataset, but we do not want to estimate features at all the points in it, but rather at keypoints discovered using the methods in pcl_keypoints, or at a downsampled version of the cloud (e.g., obtained using a `pcl::VoxelGrid<T>` filter). In this case, we pass the downsampled/keypoints input via **setInputCloud()**, and the original data as **setSearchSurface()**.

# Feature

## Surface Normal Estimation

![](Point%20Cloud%20Processing/Untitled.png)

Where $k$ is the number of point neighbors considered *in the neighborhood of $p_i$, $\bar{p}$* represents the 3D centroid of the nearest neighbors, $\lambda_j$ is the $j$-th eigenvalue of the covariance matrix, and  $\vec{V_j}$ the $j$-th eigenvector.

The right part of the figure presents the Extended Gaussian Image (EGI), also known as the normal sphere, which describes the orientation of all normals from the point cloud. Since the datasets are 2.5D and have thus been acquired from a single viewpoint, normals should be present only on half of the sphere in the EGI. However, due to the orientation inconsistency, they are spread across the entire sphere.

![https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/unflipped_scene1.jpg](https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/unflipped_scene1.jpg)

![https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/unflipped_scene2.jpg](https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/unflipped_scene2.jpg)

![https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/unflipped_sphere.jpg](https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/unflipped_sphere.jpg)

The solution to this problem is trivial if the viewpoint $V_{p}$ is in fact known. To orient all normals $\vec{n}$ consistently towards the viewpoint, they need to satisfy the equation:

![https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/math/c7a372118ca0d394b306ebbf1da06cc2c9c16080.png](https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/math/c7a372118ca0d394b306ebbf1da06cc2c9c16080.png)

The figure below presents the results after all normals in the datasets from the above figure have been consistently oriented towards the viewpoint.

![https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/flipped_scene1.jpg](https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/flipped_scene1.jpg)

![https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/flipped_scene2.jpg](https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/flipped_scene2.jpg)

![https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/flipped_sphere.jpg](https://pcl.readthedocs.io/projects/tutorials/en/latest/_images/flipped_sphere.jpg)

To re-orient a given point normal manually in PCL, you can use:

```python
flipNormalTowardsViewpoint (const PointT &point, float vp_x, float vp_y, float vp_z, Eigen::Vector4f &normal);
```

The specifics of the nearest-neighbor estimation problem raise the question of the *right scale factor*
: given a sampled point cloud dataset, what are the correct **k** (given via **pcl::Feature::setKSearch**) or **r** (given via **pcl::Feature::setRadiusSearch**) values that should be used in determining the set of nearest neighbors of a point?

the scale for the determination of a point’s neighborhood has to be selected based on the level of detail required by the application. Simply put, if the curvature at the edge between the handle of a mug and the cylindrical part is important, the scale factor needs to be small enough to capture those details, and large otherwise.

![Untitled](Point%20Cloud%20Processing/Untitled%201.png)

### ****Speeding Normal Estimation with OpenMP****

On a system with 8 cores, you should get anything between 6-8 times faster computation times.

### Normal Estimation Using Integral Images

If your dataset is organized (e.g., acquired using a TOF camera, stereo camera, etc – that is, it has a width and a height), for even faster results see the [Normal Estimation Using Integral Images](https://pcl.readthedocs.io/projects/tutorials/en/latest/normal_estimation_using_integral_images.html#normal-estimation-using-integral-images).

## ****Point Feature Histograms (PFH) descriptors****

```cpp
computePairFeatures (const Eigen::Vector4f &p1, const Eigen::Vector4f &n1,
                     const Eigen::Vector4f &p2, const Eigen::Vector4f &n2,
                     float &f1, float &f2, float &f3, float &f4);
// three out of the four features f1, f2 and f3 presented above are measures of the angles between normals, f4 is te measure of distance between p1 and p2. 
// In some cases, the fourth feature, d, does not present an extreme significance for 2.5D datasets, usually acquired in robotics, as the distance between neighboring points increases from the viewpoint. Therefore, omitting d for scans where the local point density influences this feature dimension has proved to be beneficial.
```

![Untitled](Point%20Cloud%20Processing/Untitled%202.png)

![Untitled](Point%20Cloud%20Processing/Untitled%203.png)

![Untitled](Point%20Cloud%20Processing/Untitled%204.png)

The binning process divides each feature’s value range into **b**  subdivisions, and counts the number of occurrences in each subinterval. Since three out of the four features presented above are measures of the angles between normals, their values can easily be normalized to the same interval on the trigonometric circle.

```
for each point pin cloud P

  1. get the nearest neighbors of p

  2. for each pair of neighbors, compute the three angular values

  3. bin all the results in an output histogram
```

### compare with FPFH (Fast Point Feature Histogram)

```
for each point p in cloud P

  1. pass 1:

     1. get the nearest neighbors of :math:`p`

     2. for each pair of :math:`p, p_i` (where :math:`p_i` is a neighbor of :math:`p`, compute the three angular values

     3. bin all the results in an output SPFH histogram

  2. pass 2:

     1. get the nearest neighbors of :math:`p`

     3. use each SPFH of :math:`p` with a weighting scheme to assemble the FPFH of :math:`p`:
```

### Viewpoint Feature Histogram (or VFH)

the normal vector of point $p_i$ is change to $V_p-P_i$

![Untitled](Point%20Cloud%20Processing/Untitled%205.png)

## Narf (Normal Aligned Radial Feature)

```
'NARF: 3D Range Image Features for Object Recognition.pdf'
'Point Feature Extraction on 3D Range Scans Taking into Account Object Boundaries.pdf'
```

[](https://blog.csdn.net/weixin_38498629/article/details/123844244)

[3D点云--NARF特征_mysticalwing的博客-CSDN博客_narf特征](https://blog.csdn.net/anderson_y/article/details/85678484)

Requirements for our interest point extraction :

- take information about borders and the surface structure into account
- must select positions that can be reliably detected even if the object is observed form another perspective
- the points must be on positions that provide stable areas for normal estimation or the descriptor calculation in general

## Moment of inertia and eccentricity based descriptors

❓ Question

- [ ]  How to calculate axis moment of inertia?
- [ ]  How to calculate the eccentricity after all point projected onto the current vector?

The idea of the feature extraction method is as follows. First of all the covariance matrix of the point cloud is calculated and its eigen values and vectors are extracted. You can consider that the resultant eigen vectors are normalized and always form the right-handed coordinate system (major eigen vector represents X-axis and the minor vector represents Z-axis). On the next step the iteration process takes place. On each iteration major eigen vector is rotated. Rotation order is always the same and is performed around the other eigen vectors, this provides the invariance to rotation of the point cloud. Henceforth, we will refer to this rotated major vector as current axis.

![Untitled](Point%20Cloud%20Processing/Untitled%206.png)

For every current axis moment of inertia is calculated. Moreover, current axis is also used for eccentricity calculation. For this reason current vector is treated as normal vector of the plane and the input cloud is projected onto it. After that eccentricity is calculated for the obtained projection.

![Untitled](Point%20Cloud%20Processing/Untitled%207.png)

## ****RoPs (Rotational Projection Statistics) feature****

## ****Globally Aligned Spatial Distribution (GASD) descriptors****

# Filtering

## PassThrough filter

```cpp
// The filter field name is set to the z coordinate, and the accepted interval values are set to (0.0;1.0).
pass.setFilterFieldName ("z");
pass.setFilterLimits (0.0, 1.0);
```

## VoxelGrid filter

```cpp
// all the points present will be approximated (i.e., downsampled) with their centroid. This approach is a bit slower than approximating them with the center of the voxel, but it represents the underlying surface more accurately.
sor.setLeafSize (0.01f, 0.01f, 0.01f); // a leaf size of 1cm
```

## StatisticalOutlierRemoval

```cpp
// all points who have a distance larger than 1 standard deviation of the mean distance to the query point will be marked as outliers and removed.
sor.setMeanK (50);
sor.setStddevMulThresh (1.0);
```

## ****Projecting points using a parametric model****

```cpp
// use a plane model, with ax+by+cz+d=0, where a=b=d=0, and c=1, or said differently, the X-Y plane.
pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients ());
coefficients->values.resize (4);
coefficients->values[0] = coefficients->values[1] = 0;
coefficients->values[2] = 1.0;
coefficients->values[3] = 0;

// create the ProjectInliers object and use the ModelCoefficients defined above as the model to project onto.
pcl::ProjectInliers<pcl::PointXYZ> proj;
proj.setModelType (pcl::SACMODEL_PLANE);
proj.setInputCloud (cloud);
proj.setModelCoefficients (coefficients);
proj.filter (*cloud_projected);
```

![Untitled](Point%20Cloud%20Processing/Untitled%208.png)

Note that the coordinate axes are represented as red (x), green (y), and blue (z). The five points are represented with red as the points before projection and green as the points after projection. Note that their z now lies on the X-Y plane.

## ****RadiusOutlierRemoval****

The user specifies a number of neighbors which every index must have within a specified radius to remain in the PointCloud. For example if 1 neighbor is specified, only the yellow point will be removed from the PointCloud. If 2 neighbors are specified then both the yellow and green points will be removed from the PointCloud.

![Untitled](Point%20Cloud%20Processing/Untitled%209.png)

```cpp
outrem.setRadiusSearch(0.8);
outrem.setMinNeighborsInRadius (2);
```

# Compression

```
Encoding Frame: Prediction frame
Number of encoded points: 192721
XYZ compression percentage: 3.79962%
XYZ bytes per point: 0.455954 bytes
Color compression percentage: 15.2121%
Color bytes per point: 0.608486 bytes
Size of uncompressed point cloud: 3011.27 kBytes
Size of compressed point cloud: 200 kBytes
Total bytes per point: 1.06444 bytes
Total compression percentage: 6.65275%
Compression ratio: 15.0314
```

[pointcloud compression based on octree](https://www.notion.so/pointcloud-compression-based-on-octree-78d285317f164b6caad38fb8237e863a) 

# Recognition

## ****3D Object Recognition based on Correspondence Grouping****

![Untitled](Point%20Cloud%20Processing/Untitled%2010.png)

## ****Implicit Shape Model****

related to machine learning

[Implicit Shape Model](https://pcl.readthedocs.io/projects/tutorials/en/latest/implicit_shape_model.html#implicit-shape-model)

# Register

![Untitled](Point%20Cloud%20Processing/Untitled%2011.png)

![Untitled](Point%20Cloud%20Processing/Untitled%2012.png)

![Untitled](Point%20Cloud%20Processing/Untitled%2013.png)

# ****Smoothing and normal estimation based on polynomial reconstruction****

![Untitled](Point%20Cloud%20Processing/Untitled%2014.png)

# Application

# GPU speedup

# Appendix

PoinCloud2 message by Velodune LIDAR:

```
header: 
  seq: 1071
  stamp: 
    secs: 1521699326
    nsecs: 676390000
  frame_id: "velodyne"
height: 1
width: 66811
fields: 
  - 
    name: "x"    
    offset: 0           // the number of bytes from the start of the point to the byte
    datatype: 7
    count: 1
  - 
    name: "y"
    offset: 4
    datatype: 7
    count: 1
  - 
    name: "z"
    offset: 8
    datatype: 7
    count: 1
  - 
    name: "intensity"
    offset: 16
    datatype: 7
    count: 1
  - 
    name: "ring"
    offset: 20
    datatype: 4
    count: 1
is_bigendian: False
point_step: 32       // the number of bytes of one point entry offset 
row_step: 2137952
data: [235, 171, 54, 190, 53, 107, 250, ...      // actual data
--> data: [ .......................................................... ]
```