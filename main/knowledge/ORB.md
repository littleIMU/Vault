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
Up Level: (parent:: [Slam Framework](Slam%20Framework.md))

### Reference 

[orb_slam.pdf](ORB/orb_slam.pdf)

[orb2_slam.pdf](ORB/orb2_slam.pdf)

[orb3_slam.pdf](ORB/orb3_slam.pdf)

### Demo 


### Question


---

# Installation

the latest version orb is orb_slam3, other two version orb_slam1 and 2 need different dependance, to reduce the complicity, only orb_slam3 is testes. Installation detail is [here](https://github.com/UZ-SLAMLab/ORB_SLAM3)

## Problem and Solution
```sh
# error: ‘slots_reference’ was not declared in this scoperep
# --> local gcc complilor is c++ 14, replace it in CMakeLists.txt
sed -i 's/++11/++14/g' CMakesLists.txt

# no euroc_examples.sh found in code folder
# --> new version of orb_slam3 does not contain example files.
# old version includes them, one of the old version is in  https://github.com/electech6/ORB_SLAM3_detailed_comments
```
