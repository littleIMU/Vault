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
Up Level: (parent:: [Feature detection&descriptor](Feature%20detection&descriptor.md))

### Reference

[Overview | Edge Detection](https://www.youtube.com/watch?v=7AlwDYmjrcs&list=PL2zRqk16wsdqXEMpHrc4Qnb5rA1Cylrhx&index=1)

### Questions

- [ ]  How to calculate the moment of inertia of an object?
- [ ]  In circle detection using gradient, why a and b have two values?
- [ ]  What does the edge direction look like?
- [ ]  In SIFT, why it uses 3d cubic to find extremum?
- [ ]  In SIFT, how does the sigma change value? increase like quantum or with small interval value?
- [ ]  The two undo-es (undo the effect of orientation and scale) is carried out after corresponding point found with histogram. Is it correct?

---

# Edge Detection

## edge detection using 1st gradients

gradient (partial derivatives) in 2d or 3d space represents the direction of most rapid change in intensity: magnitude and orientation.

- implement in discrete image
- can be implemented as convolution

![](Edge&Boundary&SIFT%20detection/Untitled.png)

- gradient operators: from Roberts to Sobel convolution matrix
    
    with small matrix, good localization but with noise sensitive and poor detection
    

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%201.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%202.png)

- standard thred and hysteresis based
    
    ![Untitled](Edge&Boundary&SIFT%20detection/Untitled%203.png)
    

## Edge detection using 2nd derivative

- **detect zero crossing compared with max threshold in gradient operator**

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%204.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%205.png)

 

## Noise effect

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%206.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%207.png)

## Compare between gradient (1st) and laplacian (2nd)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%208.png)

## Canny Edge Detection

one-directional laplacian 

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%209.png)

# Corner detection

## by the distribution of gradient in x and y directions

$I_x = \partial{I}/\partial{x}$

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2010.png)

calculate $\lambda1$ and $\lambda2$, derived from the calculation of moment of inertial of an object with an elliptical shape

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2011.png)

### Harris corner

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2012.png)

### Peak detection

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2013.png)

### Full processing

# Boundary detection

## Fitting lines and curves

### least square method

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2014.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2015.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2016.png)

### homogeneous linear equations

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2017.png)

## Active Contours

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2018.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2019.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2020.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2021.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2022.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2023.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2024.png)

## Hough transform

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2025.png)

### line detection

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2026.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2027.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2028.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2029.png)

### circle detection

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2030.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2031.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2032.png)

## Generalized Hough Transform

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2033.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2034.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2035.png)

# SIFT (Scale Invariant Feature Transform)

## What is interesting points

matching becomes easier if we can remove variations like size and rotation

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2036.png)

### Blob-like Feature

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2037.png)

## Detecting Blobs/turn

### 1D Blob

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2038.png)

increasing sigma a little bit

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2039.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2040.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2041.png)

### 2D Blob

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2042.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2043.png)

## SIFT Detector

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2044.png)

### undo the effect of scale and orientation

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2045.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2046.png)

## SIFT Descriptor

Normalized histogram: invariant to rotation, scale and brightness

three way to make a descriptor

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2047.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2048.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2049.png)

![Untitled](Edge&Boundary&SIFT%20detection/Untitled%2050.png)