---
priority: 1st
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

# Why

Find out whether there is low-cost falsh liar which can be used in home cleaning robot.

Question


1.  //?u How itof make sure that each pixel is the point? Can the adjacent pixels get the light that received by the pixel? If they can, how to reduce the influence of the light that reflected by other point?
2.  //?u In DToF, several pixels are combined to receive the light reflected from the same spot. Why IToF does not need this?
3.  //?u Are IR image and point could generated in the same time?
4.  //?u Why FoV is reciprocal to max distance in IToF?
5.  //?u What frequency can a itof sensor output at?
6.  //?u What is biomimetic vision?   锐思智芯
7.  //?u What is the format of output, is there timestamp for each pixel?


MR813 by 全志，240 x 180, 10 frames, 1.5G 带宽

A53

|                  | Indirect ToF          |     | Direct ToF                  |     | SL-spot                   |     |
| ---------------- | --------------------- | --- | --------------------------- | --- | ------------------------- | --- |
| acquisition      | Long integration time | 😡  | Fast acquisition            | 🙂  | depend on computing power |     |
| ambiguity        | Ambiguity             | 😡  | ambiguity                   | 🤢  | No                        | 🙂  |
| multiple echoes  | Multiple echoes       | 😡  | Multiple echoes             | 🙂  | No                        | 🙂  |
| dynamic range    | Analog dynamic range  | 🤢  | Digital dynamic range       | 🙂  | \                         |     |
| no. of pixels    | Large                 | 🙂  | Reduced                     | 😡  | Very large                | 🙂  |
| data volume      | Small data volume     | 🙂  | Large data volume           | 🤢  | Large                     | 🤢  |
| best application | ‘3d imagine’          |     | ‘Single/Few points ranging’ |     | Face recognition          |     |
| distance         | ≤ 4m                  |     | ≤ 5m                        |     | ≤ ?                       |     |
| std error        | Stable                | 🙂  | Stable                      | 🙂  | Exponential               | 😡  |
| price < 500      |                       |     |                             |     |                           |     |
| data distortion  |                       |     |                             |     |                           |     |
| FoV              |                       |     |                             |     |                           |     |
|                  |                       |     |                             |     |                           |     |