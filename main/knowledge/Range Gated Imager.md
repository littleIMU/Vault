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
Up Level: (parent:: [Time of Flight](Time%20of%20Flight.md))

### Reference

[Time-of-flight camera - Wikipedia](https://en.wikipedia.org/wiki/Time-of-flight_camera#:~:text=Range%20gated%20imagers)

[Range-gated-technology](https://www.optoprecision.de/en/security-systems/products/multi-sensor-systems/range-gated-technology.html)

[Range-Gated Imaging System for Underwater Monitoring in Ocean Environment](https://www.mdpi.com/2071-1050/11/1/162)

[LED三维成像雷达及其在自动物流车上的应用](http://www.doc88.com/p-3465234160035.html)

[Gated Sensor in ADAS: Improved Vehicle Safety - FutureBridge](https://www.futurebridge.com/industry/perspectives-mobility/gated-sensor-in-adas-improved-vehicle-safety/)

[Long-range depth imaging using a single-photon detector array and non-local data fusion - Scientific Reports](https://www.nature.com/articles/s41598-019-44316-x)

---

![](Range%20Gated%20Imager/Untitled.png)

![Untitled](Range%20Gated%20Imager/Untitled%201.png)

![Untitled](Range%20Gated%20Imager/Untitled%202.png)

These devices have a built-in shutter in the image sensor that opens and closes at the same rate as the light pulses are sent out. Most time-of-flight 3D sensors are based on this principle invented by Medina.[[6]](https://en.wikipedia.org/wiki/Time-of-flight_camera#cite_note-Medina,_Antonio-6) Because part of every returning pulse is blocked by the shutter according to its time of arrival, the amount of light received relates to the distance the pulse has traveled. The distance can be calculated using the equation, *z* = *R* (*S2*− *S1*) / 2(*S1* + *S2)* + *R*/ 2 for an ideal camera. *R* is the camera range, determined by the round trip of the light pulse, *S1* the amount of the light pulse that is received, and *S2* the amount of the light pulse that is blocked.[[6]](https://en.wikipedia.org/wiki/Time-of-flight_camera#cite_note-Medina,_Antonio-6)[[7]](https://en.wikipedia.org/wiki/Time-of-flight_camera#cite_note-Medina_A,_Gay%C3%A1_F,_and_Pozo_F-7)

Shuttering of the CCD camera is achieved by dumping the photosite charge to the CCD substrate while the pulse has not fully arrived to the CCD and then transferring the photoelectrons from their photosites to the vertical transport registers. 

N1 is therefore the collected portion of the received light pulse and N2 is the portion of the light pulse rejected by the shutter. The time needed to transfer the charge is very short, of the order of 30 ns. The 3D camera reads out a regular (non shuttered) image N = N1 + N2 as the subsequent frame. In this way, the charge corresponding to portions N1 and N are read as successive frames. It is also possible to obtain N1 and N2 with a single pulse, but with a commercial CCD the laser pulses would have to operate at the CCD’s frame rate instead of the horizontal line rate.

![When gate is open](Range%20Gated%20Imager/Screenshot_from_2022-06-29_18-07-18.png)

When gate is open

![When gate is closed](Range%20Gated%20Imager/Screenshot_from_2022-06-29_18-06-45.png)

When gate is closed

![](Range%20Gated%20Imager/Untitled%203.png)

_A laser pulse (green areas) illuminates underwater objects at different times, and hence different distances. Suspended particles (yellow dots) will contribute to backscatter (arrows) with the largest energy signal on the camera coming from close range particles (black line). In range‐gated systems, the shutter on the camera is only open for a narrow time window away from the backscatter region. In this example, the camera is closed for about 45 ns, thus only objects farther than about 5 m are detected (e.g., such as the tuna at about 8 m distance). This improves the signal‐to‐noise ratio as, in general, the intensity of particle scattering in the detection region is less than the total energy reflected by the object of interest_

Currently, most depth cameras based on this technology use InGaAs which is called InGaAs cameras.  They bridge the gap between NIR wavelengths in the 950-1700 nm range, where silicon detectors are no longer sensitive.

## STEP 1

The device sends a short laser pulse.The camera shutter remains closed while the light between the device and the target object is scattered and reflected by atmospheric particles.

![https://www.optoprecision.de/fileadmin/_processed_/5/6/csm_RG1_41a7eed721.png](https://www.optoprecision.de/fileadmin/_processed_/5/6/csm_RG1_41a7eed721.png)

## STEP 2

The laser light contacts the target object and is reflected.The camera shutter remains closed and does not capture any interference light.

![https://www.optoprecision.de/fileadmin/_processed_/0/3/csm_RG2_0a8226b192.png](https://www.optoprecision.de/fileadmin/_processed_/0/3/csm_RG2_0a8226b192.png)

## STEP 3

The light reflected by the target object arrives at the camera and the camera opens the camera shutter for this brief moment. The shutter is then closed again,so that no interference light behind the object is captured.

![https://www.optoprecision.de/fileadmin/_processed_/7/4/csm_RG3_e34522e20e.png](https://www.optoprecision.de/fileadmin/_processed_/7/4/csm_RG3_e34522e20e.png)