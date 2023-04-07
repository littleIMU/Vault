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
link_knowledge: 
---
Up Level: (parent:: [Point Cloud Processing](Point%20Cloud%20Processing.md))
#ICP
```toc
```
### 📇Reference
[Iterative Closet Point Algorithm (ppt)](ICP/cs685-icp.pdf)

[Efficient variant of the ICP algorithm.pdf](ICP/Efficient_variants_of_the_ICP_algorithm.pdf)

### ❓Question

---

# select points to match
```python
def select_n_points(self, n):
	if self.no_points > n:
	self.sel = np.round(np.linspace(0, self.no_points-1, n)).astype(int)
	else:
	self.sel = np.arange(0, self.no_points, 1)
```

# get normal vector for each selected point
```python
def estimate_normals(self, neighbors):

	self.nx = np.full(self.no_points, np.nan)
	self.ny = np.full(self.no_points, np.nan)
	self.nz = np.full(self.no_points, np.nan)
	self.planarity = np.full(self.no_points, np.nan)
	
	
	kdtree = spatial.cKDTree(np.column_stack((self.x, self.y, self.z)))
	query_points = np.column_stack((self.x[self.sel], self.y[self.sel], self.z[self.sel]))
	
	# p=1:|x1 - x2| + |y1 - y2|, p=2:
	_, idxNN_all_qp = kdtree.query(query_points, k=neighbors, p=2, n_jobs=-1)
	 
	for (i, idxNN) in enumerate(idxNN_all_qp):
	selected_points = np.column_stack((self.x[idxNN], self.y[idxNN], self.z[idxNN]))
	C = np.cov(selected_points.T, bias=False)
	eig_vals, eig_vecs = np.linalg.eig(C)
	idx_sort = eig_vals.argsort()[::-1] # sort from large to small
	eig_vals = eig_vals[idx_sort]
	eig_vecs = eig_vecs[:,idx_sort]
	self.nx[self.sel[i]] = eig_vecs[0,2]
	self.ny[self.sel[i]] = eig_vecs[1,2]
	self.nz[self.sel[i]] = eig_vecs[2,2]
	self.planarity[self.sel[i]] = (eig_vals[1]-eig_vals[2])/eig_vals[0]
```
# rejecting
first get the distance
```python
no_correspondences = len(pcfix.sel)
distances = np.empty(no_correspondences)
for i in range(0, no_correspondences):
distances[i] = dx[i]*nx[i] + dy[i]*ny[i] + dz[i]*nz[i]
```
then using staticstical method to trim the points
```python
def reject(pcfix, pcmov, min_planarity, distances):
	
	planarity = pcfix.planarity[pcfix.sel]
	
	med = np.median(distances)
	sigmad = stats.median_absolute_deviation(distances)
	
	keep_distance = [abs(d-med) <= 3*sigmad for d in distances]
	keep_planarity = [p > min_planarity for p in planarity]
	
	keep = keep_distance and keep_planarity
	
	pcfix.sel = pcfix.sel[keep]
	pcmov.sel = pcmov.sel[keep]
	distances = distances[keep]
	
	return distances
```
# build a least square function
The residual is realted to the projection in normal vector
- [ ] #Ques Why the `A@x`? 🛫 2023-02-22 
```python
def estimate_rigid_body_transformation(x_fix, y_fix, z_fix, nx_fix, ny_fix, nz_fix, x_mov, y_mov, z_mov):

	A = np.column_stack((-z_mov*ny_fix + y_mov*nz_fix,
	z_mov*nx_fix - x_mov*nz_fix,
	-y_mov*nx_fix + x_mov*ny_fix,
	nx_fix,
	ny_fix,
	nz_fix))
	
	l = nx_fix*(x_fix-x_mov) + ny_fix*(y_fix-y_mov) + nz_fix*(z_fix-z_mov)
	
	x, _, _, _ = np.linalg.lstsq(A, l)
	  
	residuals = A @ x - l
	
	R = euler_angles_to_linearized_rotation_matrix(x[0], x[1], x[2])
	
	t = x[3:6]
	
	H = create_homogeneous_transformation_matrix(R, t)
	
	return H, residuals
```









