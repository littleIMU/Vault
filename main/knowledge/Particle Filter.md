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
Up Level: (parent:: [Markov chain Monte Carlo](Markov%20chain%20Monte%20Carlo.md))


# Generic Particle filter

A Tutorial on Particle Filters for Online Nonlinear/Non-Gaussian Bayesian Tracking.pdf

# Code Example of Generic PF

code_src/MCMC/particle_filter/code_genetic_pf
 
# Genres

There are variants of particle filtet algorithms. They are different from each other mostly on how to get a efficient sampling point.

# Rao-Blackwellized particle filter

![](Particle%20Filter/image-20230214134355087.png)

[RaoBlackwellized Particle Filters.3853.pdf](Gmapping/RaoBlackwellized%20Particle%20Filters.3853.pdf)

# Improved Rao-Blackwellized particle filter

see details in [Model](Gmapping.md#Model)

# KLD sample

- [ ] #Ques What parameters to set and their meaning? What can you get by looking to the chi-squre distribution table? 🛫 2023-02-15 
      Collecting n particles, each one falls onto a bin representing the possibility of the value ![](Particle%20Filter/image-20230215183708587.png) , the threshold is equal to the value found in chi-square distribution given error (bounds) and delta (_what is it?_). 
      __《 概率机器人 》第八章 有介绍__

[KLD-sampling.pdf](Particle%20Filter/KLD_Sampling_in_Localization.pdf)

[Explanation of KLD sampling](https://blog.csdn.net/weixin_42530239/article/details/96501814)

The main idea is to evaluate the difference between proposal and target distribution using chi-square distribution.
![](Particle%20Filter/image-20230215182301615.png)


