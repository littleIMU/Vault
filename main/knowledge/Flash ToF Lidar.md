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
Up Level: (parent:: [3D Depth Camera](3D%20Depth%20Camera.md))

# Structure

In flash lidar, the entire field of view is illuminated with a wide [diverging](https://en.wikipedia.org/wiki/Beam_divergence) [laser](Flash%20ToF%20Lidar/Laser.md) beam in a single pulse based on diffractive optical elements. This is in contrast to conventional scanning lidar, which uses a [collimated laser beam](https://en.wikipedia.org/wiki/Collimated_beam) that illuminates a single point at a time, and the beam is [raster scanned](https://en.wikipedia.org/wiki/Raster_scan) to illuminate the field of view point-by-point.

[Time-of-flight camera](https://en.wikipedia.org/wiki/Time-of-flight_camera) is used to collect information about both the 3-D location and intensity of the light incident on it in every frame. However, in scanning lidar, this camera contains only a point sensor, while in flash lidar, the camera contains either a 1-D or a 2-D [sensor array](https://en.wikipedia.org/wiki/Sensor_array), each pixel of which collects 3-D location and intensity information. The result is a camera that takes pictures of distance, instead of colors.  

More detail in [Time of Flight](Time%20of%20Flight.md)

# Advantages over Scanning Lidar

when the camera, scene, or both are moving, since the entire scene is illuminated at the same time. With scanning lidar, motion can cause "jitter" from the lapse in time as the laser rasters over the scene.

# Supplies

[Supplies](Flash%20ToF%20Lidar/Supplies.csv)
