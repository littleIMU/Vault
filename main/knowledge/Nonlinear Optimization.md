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
Up Level: (parent:: [Applied Math](Applied%20Math.md))

### Reference

[Solving Non-linear Least Squares - Ceres Solver](http://ceres-solver.org/nnls_solving.html)

### ❓ Questions

- [ ]  why D(x) become identical matrix in simplified LM?


# Line Search

## Gaussian-Newton

Derived from least square method

[Least squares - Wikipedia](https://en.wikipedia.org/wiki/Least_squares##Non_linear_least_squares)

![](Nonlinear%20Optimization/image-20230222161411130.png)

Derivation of matrix form

![Untitled](Nonlinear%20Optimization/Untitled%201.png)

![Untitled](Nonlinear%20Optimization/Untitled%202.png)

![Untitled](Nonlinear%20Optimization/Untitled%203.png)

## Gradient Descend

![](Nonlinear%20Optimization/image-20230109154224738.png)
https://www.youtube.com/watch?v=1tPNJTLjMWw

![Untitled](Nonlinear%20Optimization/Untitled%204.png)
[Gradient descent - Wikipedia](https://en.wikipedia.org/wiki/Gradient_descent#Solution_of_a_non-linear_system)

![](Nonlinear%20Optimization/image-20230109154715888.png)
[example](https://machinelearningmastery.com/a-gentle-introduction-to-gradient-descent-procedure/)
# Trust Region Methods

## Levenberg Marquardt

- [ ] #Ques the derivative of gradient g(x) from least square formula?🛫 2023-01-09 
- [x] #Ques why the step is close to the gradient-descent direction when lamda increases? 🛫 2023-01-09 ✅ 2023-01-09 | see the derivation process in [Gradient Descend](Nonlinear%20Optimization.md#Gradient%20Descend)
- [ ] #Ques the relation between trust region and D(x)?🛫 2023-01-09 

Levenberg;s contribution is to replace the least square function by a "samped version ":
![](Nonlinear%20Optimization/image-20230109153306099.png)

![Untitled](Nonlinear%20Optimization/Untitled%205.png)

![Untitled](Nonlinear%20Optimization/Untitled%206.png)

## Dogleg