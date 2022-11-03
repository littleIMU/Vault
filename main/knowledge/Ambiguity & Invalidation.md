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

 #ITOF

# [Invalidation](https://docs.microsoft.com/en-us/azure/kinect-dk/depth-camera#operating-principles)

In certain situations, the depth camera may not provide correct values for some pixels. In these situations depth pixels are invalidated. Invalid pixels are indicated by the depth value equals to 0. Reasons for the depth engine being unable to produce correct values include:

- Outside of active IR illumination mask
- Saturated IR signal
- Low IR signal
- Filter outlier
- Multi-path interference

##  llumination Mask

Pixels are invalidated when they're outside of the active IR illumination mask. We don't recommend using the signal of such pixels to compute depth. The figure below, shows the example of invalidation by illumination mask. The invalidated pixels are the black-color pixels outside the circle in the wide FoV modes (left), and the hexagon in the narrow FoV modes (right).

![https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-illumination-mask.png](https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-illumination-mask.png)

##  Signal strength

Pixels are invalidated when they contain a saturated IR signal. When pixels are saturated, phase information is lost. The image below, shows the example of invalidation by a saturated IR signal. See arrows pointed to the example pixels in both the depth and IR images.

![https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-saturation.png](https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-saturation.png)

Invalidation can also occur when the IR signal isn't strong enough to generate depth. The below figure, shows the example of invalidation by a low IR signal. See the arrows pointed to example pixels in both the depth and IR images.

![https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-low-signal.png](https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-low-signal.png)

##  Ambiguous depth

Pixels can also be invalidated if they received signals from more than one object in the scene. A common case where this sort of invalidation can be seen is in corners. Because of the scene geometry, the IR light from the camera reflected off one wall and onto the other. This reflected light causes ambiguity in the measured depth of the pixel. Filters in the depth algorithm detect these ambiguous signals and invalidate the pixels.

The figures below show examples of invalidation by multi-path detection. You also can see how the same surface area that was invalidated from one camera view (top row) may appear again from a different camera view (bottom row). This image demonstrates that surfaces invalidated from one perspective may be visible from another.

![https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-multipath.png](https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-multipath.png)

Another common case of multipath is pixels that contain the mixed signal from foreground and background (such as around object edges). During fast motion, you may see more invalidated pixels around the edges. The additional invalidated pixels are because of the exposure interval of the raw depth capture,

![https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-edge.png](https://docs.microsoft.com/en-us/azure/kinect-dk/media/concepts/depth-camera-invalidation-edge.png)