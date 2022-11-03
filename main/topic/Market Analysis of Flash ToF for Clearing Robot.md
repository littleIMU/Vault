---
priority: 3rd
status: completed
url: 
category: 
parent: 
children: 
link_action: 
link_topic: "[Cleaning Robot](../project/Cleaning%20Robot.md)"
link_project: 
link_course: 
link_notes: 
---

# Structure

![300](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Screenshot_from_2022-06-30_15-56-47.png)




Components:

Laser Source + DOE + Receiving Sensor + Processing Unit

# Principle

[Time of Flight](../knowledge/Time%20of%20Flight.md)

# Market

> Is there any  electronic product using flash LIDAR as fundamental sensor?
> Which sensor we can use in our product?
> Is Range Gated Imager good enough for mapping and localization?

[科沃斯](https://detail.tmall.com/item.htm?spm=a220o.1000855.w5001-22145441734.10.7166177fvj8Lni&id=674350830332&scene=taobao_shop) Yeedi YDTX11 

![Screenshot from 2022-06-30 16-00-51.png](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Screenshot_from_2022-06-30_16-00-51.png)

**Apple**, Iphone max 12 or higher, Flash DToF imager 

![Untitled | 300](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Untitled.png)   ![Apart image sensor from Sony, the Lidar is equipped with a VSCEL from Lumentum  | 300](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Untitled%201.png)

Apart image sensor from Sony, the Lidar is equipped with a VSCEL from Lumentum

> More detail about Apple Lidar structure can be found in [Here](https://4sense.medium.com/apple-lidar-demystified-spad-vcsel-and-fusion-aa9c3519d4cb).
> 

**Microsoft Azure Kinect, Flash ITOF imager**

![Equipped with [ADSD3100](https://www.analog.com/en/products/adsd3100.html#product-overview) CMOS imager](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Untitled%202.png)

Equipped with [ADSD3100](https://www.analog.com/en/products/adsd3100.html#product-overview) CMOS imager

![Untitled](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Untitled%203.png)

> More detail about Azure Kinect Depth sensor can be found in [Here](https://devblogs.microsoft.com/azure-depth-platform/time-of-flight-camera-system-overview/).
> 

## Analysis of Yeedi YDTX11

→Which sensor we can use in our product?

![Screenshot from 2022-06-29 18-23-09.png | 300](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Screenshot_from_2022-06-29_18-23-09.png)

Prediction within 5 meters, different FoV, scanning frequency 

![Screenshot from 2022-06-30 13-39-44.png | 300](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Screenshot_from_2022-06-30_13-39-44.png)

(likely sensor) CCD-based range gated imager

(likely sensor) flash dtof lidar

![TMF8820 Structure](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Screenshot_from_2022-06-30_12-34-53.png)

TMF8820 Structure

![Sparkfun package](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/PSX_20220630_235716.jpg)
[LINK](https://www.sparkfun.com/products/19036)

![Multiple-sensor scenery](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Screenshot_from_2022-06-30_12-52-24.png)

Multiple-sensor scenery

![Screenshot from 2022-06-30 12-55-33.png](Market%20Analysis%20of%20Flash%20ToF%20for%20Clearing%20Robot/Screenshot_from_2022-06-30_12-55-33.png)

**Demo: [hand detecting](https://www.youtube.com/watch?v=2sek1tvX6mg), [multiple-sensors](https://www.youtube.com/watch?v=J_4giQJt7WI).**

## Comparison between LSD and Flash Lidar

→Is Range Gated Imager good enough for mapping and localization?

| Product Model | LD06p |  | VL53L5CX |  | CE30 |  |
| --- | --- | --- | --- | --- | --- | --- |
| Producer | 乐动 |  | STM |  | 光珀智能 |  |
| Principle | LSD |  | Flash DTOF |  | Range gated  |  |
| Range | 0.02 - 12 | 😃 | 0.02 - 4 | 😡 | 0.02 - 4 | 😡 |
| Frequency (Hz) | 10 | 🤢 | 0 - 30 | 🤢 | 25 | 😃 |
| Resolution | 500 x 1 |  | 8 x 8 |  | 320 x 24 |  |
| Range Ac. (mm) | 10 | 🤢 | 15 | 🤢 | 10 | 🤢 |
| Angle ac. (degree) | 0.72 | 😡 | \ | 😃 | \ | 😃 |
| Size (mm) | 38 x 38 x 33 | 😡 | 6.4 x 3.0 x 1.5 | 😃 | 47 x 79 x 50 | 😡 |
| Moving part | Yes | 😡 | No | 😃 | No | 😃 |
| Immunity to Cover Glass Crosstalk | Yes | 😡 | 60 cm | 😃 | / | 😡 |
| Programmable | No |  | Yes |  | Yes |  |
| Communication | UART |  | I2C |  | Ethernet |  |
| FoV (A x E) | 360 x 1 |  | 63 x 63 |  | 132 x 9 |  |
| Cost |  |  | $ 4 |  | ￥ 1700 |  |

FoV size and range accuracy is related to zone number and is not uniformly distributed..

## Product in market

Main producer locally and overseas, the performance and cost of each product;

---

# Appendix

- [**Glass Crosstalk**](https://www2.renesas.cn/br/en/document/apn/an1983-best-practices-tof-crosstalk-calibration)

Cosstalk in an ISL29501 application can simply be defined as a signal that reaches the detector that was not reflected from a target. This can be from parasitic electric and magnetic fields on the circuit board, decoupling and internal paths within the chip. Optical crosstalk can come from a direct path, bouncing within a glass cover or window or from reflections in the cavity surrounding the optical components.