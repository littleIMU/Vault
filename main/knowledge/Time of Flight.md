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
Up Level: (parent:: [Flash ToF Lidar](Flash%20ToF%20Lidar.md))

---

Time of Flight

There are three methods to calculated the distance:

- IToF (Indirect-Time-of-Flight) based on continuous modulated wave, the distance is obtained from the phase difference between transmitted and received wave.
- DToF (Direct-Time-of-Flight), the distance is directly calculated by the (light speed * time) formula.
- [Range Gated Imager](Range%20Gated%20Imager.md)
    
    
![](Time%20of%20Flight/Untitled.png)

![](Time%20of%20Flight/Untitled%201.png)

![Histogram analysis to calculate distance in DToF](Time%20of%20Flight/Untitled%202.png)

Histogram analysis to calculate distance in DToF

![Pixel zone calculation  in IToF, the points are sampled in analog signal for phase rebuild.](Time%20of%20Flight/Untitled%203.png)

Pixel zone calculation  in IToF, the points are sampled in analog signal for phase rebuild.

| Indirect ToF |  | Direct ToF |  |
| --- | --- | --- | --- |
| Long integration time | 😡 | Fast acquisition | 🙂 |
| Ambiguity | 😡 | No ambiguity | 🙂 |
| Multiple echoes | 😡 | Multiple echoes | 🙂 |
| Analog dynamic range | 🤢 | Digital dynamic range | 🙂 |
| Large no. of pixels | 🙂 | Reduced no. of pixels  | 😡 |
| Small data volume | 🙂 | Large data volume | 🤢 |
| Best solution today for ‘3d imagine’ |  | Best solution today for ‘Single/Few points ranging’ |  |