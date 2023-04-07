* Homogenous matrix
    - transition, rotation, similarity
* THe model of SLAM
* Recursive Bayesian Estimation
  $$p(X_{0:k},Z_{1:k}) = p(X_0)\prod_{i=1}^{n}p(Z_i|X_i)p(X_i|X_{i-1})$$
    - prediction step and correction step
___
* KF
  * EKF
  * UKF
    * n and $\lambda$, 
    * matrix square
      * eigenvalue method $VD^{1/2}V^{-1}$
      * Cholesky method $LL^T$
  * EIF
    * generated information matrix, then de-sparse the matrix, i.e. get rid of low-correlation element. 
___
* Grid Map
    * [Bresenham's line algorithm](https://blog.csdn.net/SX2101111/article/details/123722418)
    * using log odd instead of log likelihood
    * scan match
      * Iterative closest point
        * KD-tree
___
* FastSlam 
  standard procedure 
  * particle filter
    * prior possibility function
    * current weigh connected to last one
    * re-sample and switch of re-sample
  * prior distribution and data storage structure
    * in FastSlam 2.0, the prior of distribution of state depends on the current observation. And it updates the date storage structure.
___
* Graph-based SLAM 
	*standard procedure 
  - constraint 
  * least square
    * compare of QR and SVD in solving linear equations
        QR is faster than SVD but SVD is more stable than QR, i.e., SVD gets more accurate value in deficient-rank matrix.
