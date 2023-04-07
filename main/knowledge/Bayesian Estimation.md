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
Up Level: (parent:: [Applied Math](Applied%20Math.md))
#U
```toc
```
### 📇Reference

[Example of Coin Toss](https://tinyheero.github.io/2017/03/08/how-to-bayesian-infer-101.html)

[MLE Introduction.pdf](Bayesian%20Estimation/mle_introduction.pdf)

### ❓Question

---

based on Bayesian theorem
    -   conditional Bayesian theorem
	贝叶斯分类的核心依然来自于经典的贝叶斯公式：
	![](Bayesian%20Estimation/image-20230112135005798.png)
	在分类问题中，我们要求的实际上是当样本 x 出现时，它属于分类 c 的概率，即上式的 p(c|x)。等式右边的  表示为 c 之外的其他分类，p(c) 和  可以理解为先验概率，一般情况下你可以把它们设置为均等的，如我们可以把二分类的先验概率都设为 0.5。

-   different from MLE and MAP
    -   MLE (Maximum Likelihood Estimator) \
        -   Maximizing the pdf $P(D|\theta)$.
        -   For mathematical convenience, the natural logarithm of pdf is used.
        -   Find maximum by directly zero-derivative, numerical optimization or negative semi-definite Hessian matrix.
        - its standandard error is related to information matrix. 
    -   MAP (Maximum A Posteriori)
        -   Maximizing the pdf $P(\theta|D) = P(D|\theta)*P(\theta)$.
    -   Bayesian Estimation
        -   First generate the posterior pdf then maximize the pdf
-   recursive Bayesian estimation








