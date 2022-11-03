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
### Question

- [ ]  How to calculate the incident angle?
- [ ]  How to make sure 5 nearest points in a line or a plane? By eigenvalue
- [ ]  what is “remove the first 20% largest residuals”

# Structure

## point selection

![Untitled](LOAM-Livox%206a0fbff4179e48bca1c18f7efc392600/Untitled.png)

the point e and f in Fig. 6 are removed because point f has pi or zero incident angle and point e is behind an object.

## iterative pose optimization

why: the extracted features can not be constantly matched between consecutive frames because of non-repetitive scanning. 

![Untitled](LOAM-Livox%206a0fbff4179e48bca1c18f7efc392600/Untitled%201.png)

key features: map features, paralleled thread for iteration, dynamic objects filtering by removing 20% residuals in the first small number of iterations

Result:

![the desktop PC (with i7-9700K) vs onboard-computer (DJI manifold2 5 with i7-8550U)](LOAM-Livox%206a0fbff4179e48bca1c18f7efc392600/Untitled%202.png)

the desktop PC (with i7-9700K) vs onboard-computer (DJI manifold2 5 with i7-8550U)