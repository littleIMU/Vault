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

# Reference 

[Overview of CCD Detectors](https://starlink.eao.hawaii.edu/docs/sc5.htx/sc5se4.html)

[SPAD-Camera](http://www.everyphotoncounts.com/instr-imager2d.php)

---

## CCD’s advantage over CMOS

The principal advantages of CCDs are their sensitivity, dynamic range and linearity. The sensitivity, or **quantum efficiency**, is simply the fraction of photons incident on the chip which are detected. It is common for CCDs to achieve a quantum efficiency of about 80%. Compare this figure with only a few percent for even sensitised photographic plates. CCDs are also sensitive to a broad range of wavelengths and are much more sensitive to red light than either photographic plates or the photomultiplier tubes used in photoelectric photometers (see Figure [2](https://starlink.eao.hawaii.edu/docs/sc5.htx/sc5se4.html#x5-90012)). However, they have a poor response to blue and ultra-violet light.

![https://starlink.eao.hawaii.edu/docs/sc5.htx/sc5_sensitivity.png](https://starlink.eao.hawaii.edu/docs/sc5.htx/sc5_sensitivity.png)

**Figure 2:** The sensitivity or quantum efficiency as a function of wavelength for various types of detectors. The quantum efficiency is simply the fraction of incident photons which are detected. Thinned and bulk CCDs are simply different types of CCDs. Photomultiplier tubes are used in photoelectric photometers. Note that the quantum efficiency is plotted on a logarithmic scale. Adapted from McLean[[19](https://starlink.eao.hawaii.edu/docs/sc5.htx/sc5.html#XMCLEAN89), [20](https://starlink.eao.hawaii.edu/docs/sc5.htx/sc5.html#XMCLEAN97)]

CCDs are sensitive to a wide range of light levels: a typical **dynamic range** (that is, the ratio of the brightest accurately detectable signal to the faintest) is about 105105, corresponding to a range of about 14.5 magnitudes. The corresponding figures for a photographic plate are a range of less than about 1000 corresponding to 7.5 magnitudes. Furthermore, within this dynamic range the response is essentially linear: the size of the signal is simply proportional to the number of photons detected, which makes calibration straightforward.

## SPAD’s advantage over CCD and CMOS

The standard CCDs (Charge Coupled Devices) can have many pixels (some millions), but they suffer of a notoriously slow read-out. CMOS Active Pixel Sensors (APS) albeit being fast are limited to poor sensitivity since they do not employ any internal amplification process. Electron-Multiplying EM-CCDs can reach single photon sensitivity, but they are not fast enough for many applications. Instead arrays of Single Photon Avalanche Diodes (SPADs) prove to be ideal candidates when very high sensitivity is required together with high-frame rate. Unlike Photo-Multiplier Tubes (PMTs) and Micro-Channel Plates (MCPs), SPAD arrays are insensitive to magnetic fields, require lower bias voltages, and can be easily integrated with complex electronics using standard CMOS processes.