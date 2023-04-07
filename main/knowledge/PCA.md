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
Up Level: (parent:: [Statistics](Statistics.md))



### Reference

[PCA and SVD Explained with Numpy](https://towardsdatascience.com/pca-and-svd-explained-with-numpy-5d13b0d2a4d8)

[Principal Component Analysis with Python - GeeksforGeeks](https://www.geeksforgeeks.org/principal-component-analysis-with-python/)

[Principal component analysis - Wikipedia](https://en.wikipedia.org/wiki/Principal_component_analysis)

### ❓ Question

- [x]  What is n? the number of row vectors in the data set.
- [x] #Ques How to calculate data's convariance matrix? Fast way [Surface Normal Estimation](Point%20Cloud%20Processing.md#Surface%20Normal%20Estimation) ✅ 2022-11-14
- [ ] #Ques  Why the denominator in covariance matrix is n - 1. In pcl, it is n?
- [x]  What is the size of the covariance matrix. p by p where p is the element number of one data.
- [x]  Dimension transform: X (p x n) → C (p x p) → W (p x p) → $X_k=X\times W_k$
- [x] 为啥需要转换成特征向量和特征值: 可以清楚地看到特征值表示沿特征向量方向数据的方差，而协方差矩阵的方差分量表示沿轴的传播 ✅ 2022-11-14
- [ ] #Ques Is it true? 协方差矩阵的最大特征向量总是指向数据最大方差的方向，并且该向量的幅度等于相应的特征值。第二大特征向量总是正交于最大特征向量，并指向第二大数据的传播方向。

---

# PCA

PCA aims to find linearly uncorrelated orthogonal axes, which are also known as principal components (PCs) in the *m* dimensional space to project the data points onto those PCs. The first PC captures the largest variance in the data. Let’s intuitively understand PCA by fitting it on a 2-D data matrix, which can be conveniently represented by a 2-D scatter plot:

![https://miro.medium.com/max/875/1*XGaA7KWUlhWZLIezYEBIHA.gif](https://miro.medium.com/max/875/1*XGaA7KWUlhWZLIezYEBIHA.gif)

Making sense of PCA by fitting on a 2-D dataset ([source](https://stats.stackexchange.com/questions/2691/making-sense-of-principal-component-analysis-eigenvectors-eigenvalues)), the directions of the arrows correspond to the eigenvector of this covariance matrix and their lengths to the square roots of the eigenvalue. 

Since all the PCs are orthogonal to each other, we can use a pair of perpendicular lines in the 2-D space as the two PCs. To make the first PC capture the largest variance, we rotate our pair of PCs to make one of them optimally align with the spread of the data points. Next, all the data points can be projected onto the PCs, and their projections (red dots on PC1) are essentially the resultant dimensionality-reduced representation of the dataset. Viola, we just reduced the matrix from 2-D to 1-D while retaining the largest variance!

The PCs can be determined via eigen decomposition of the covariance matrix ***C***. After all, the geometrical meaning of eigen decomposition is to find a new coordinate system of the eigenvectors for ***C*** through rotations.

![https://miro.medium.com/max/163/1*c1S0_26A8RxEQQUVyMp5Vw.png | 100](https://miro.medium.com/max/163/1*c1S0_26A8RxEQQUVyMp5Vw.png)

Eigendecomposition of the covariance matrix **C** In the equation above, the covariance matrix *C*(p×p) is decomposed to a matrix of eigenvectors **W**(p×p) and a diagonal matrix of p eigenvalues ***Λ***. The eigenvectors, which are the column vectors in ***W***, are in fact the PCs we are seeking. We can then use matrix multiplication to project the data onto the PC space. For the purpose of dimensionality reduction, we can project the data points onto the first *k* PCs as the representation of the data:

![https://miro.medium.com/max/134/1*jnj2YMpWIApnCzxRU_zjfg.png | 100](https://miro.medium.com/max/134/1*jnj2YMpWIApnCzxRU_zjfg.png)

Project data onto the first k PCs

PCA can be very easily implemented with numpy as the key function performing eigen decomposition ([np.linalg.eig](https://docs.scipy.org/doc/numpy/reference/generated/numpy.linalg.eig.html)) is already built-in:

```python
def pca(X):
  # Data matrix X, assumes 0-centered
  n, m = X.shape
  assert np.allclose(X.mean(axis=0), np.zeros(m))
  # Compute covariance matrix
  C = np.dot(X.T, X) / (n-1)
  # Eigen decomposition
  eigen_vals, eigen_vecs = np.linalg.eig(C)
  # Project X onto PC space
  X_pca = np.dot(X, eigen_vecs)
  return X_pca
```

# Relationship between PCA and SVD

PCA and SVD are closely related approaches and can be both applied to decompose any rectangular matrices. We can look into their relationship by performing SVD on the covariance matrix ***C***:

![https://miro.medium.com/max/540/1*KDHJvxd-HuY0WfWqj42otw.png | 500](https://miro.medium.com/max/540/1*KDHJvxd-HuY0WfWqj42otw.png)

From the above derivation, we notice that the result is in the same form with eigen decomposition of ***C***, we can easily see the relationship between singular values (***Σ***) and eigenvalues (***Λ***):

Relationship between eigenvalue and singular values

![100](PCA/Untitled.png)

To confirm that with numpy:

```python
# Compute covariance matrix
C = np.dot(X.T, X) / (n-1)
# Eigen decomposition
eigen_vals, eigen_vecs = np.linalg.eig(C)
# SVD
U, Sigma, Vh = np.linalg.svd(X, 
    full_matrices=False, 
    compute_uv=True)
# Relationship between singular values and eigen values:
print(np.allclose(np.square(Sigma) / (n - 1), eigen_vals)) # True
```

So what does this imply? It suggests that we can actually perform PCA using SVD, or vice versa. In fact, most implementations of PCA actually use performs SVD under the hood rather than doing eigen decomposition on the covariance matrix because SVD can be much more efficient and is able to handle sparse matrices. In addition, there are reduced forms of SVD which are even more economic to compute.

# Covariance-free computation

In practical implementations, especially with [high dimensional data](https://en.wikipedia.org/wiki/High_dimensional_data) (large *p*), the naive covariance method is rarely used because it is not efficient due to high computational and memory costs of explicitly determining the covariance matrix. The covariance-free approach avoids the *np*2 operations of explicitly calculating and storing the covariance matrix **XTX**, instead utilizing one of [matrix-free methods](https://en.wikipedia.org/wiki/Matrix-free_methods), for example, based on the function evaluating the product **XT(X r)** at the cost of 2*np* operations.

### **Iterative computation[[edit](https://en.wikipedia.org/w/index.php?title=Principal_component_analysis&action=edit&section=18)]**

One way to compute the first principal component efficiently[[37]](https://en.wikipedia.org/wiki/Principal_component_analysis#cite_note-roweis-37) is shown in the following pseudo-code, for a data matrix **X** with zero mean, without ever computing its covariance matrix.

```python
r = a random vector of length p
r = r / norm(r)
do c times:
      s = 0 (a vector of length p)
      for each row x in X
            s = s + (x ⋅ r) x
      λ = rTs // λ is the eigenvalue
      error = |λ ⋅ r − s|
      r = s / norm(s)
      exit if error < tolerance
return λ, r
```

# Preprocessing beforce PCL



# PCL & Machine Learning (with code)

[PCA: Principal Component Analysis using Python | JC Chouinard](https://www.jcchouinard.com/pca-with-python/)