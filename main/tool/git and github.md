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

### Reference

[Git Tutorial](https://www.w3schools.com/git/)
[git-push-pull](https://www.datacamp.com/tutorial/git-push-pull)

# common commands
```bash
git init

git add -a

git status

git commit -a -m “say something”

git remote add origin <git path>
git push -u origin master

git pull origin master

git log —oneline

git branch -m <old_name> <new_name>
```

# git ssh

[Generating a new SSH key and adding it to the ssh-agent - GitHub Docs](https://docs.github.com/en/authentication/connecting-to-github-with-ssh/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent)
```bash
ssh-keygen -t rsa -b 4096 -C "zhan.sd@hotmail.com"
The generated key by default is in ~/.sshd/id_rsa.pub
```

# external repository

```shell
cd <catkin_ws>
vcs import src < src/<main_repository>/dependencies.repos
```

The content in `dependencies.repos` is shown as below
```txt
 repositories:                                                               
   create3_sim:
     type: git
     url: https://github.com/iRobotEducation/create3_sim.git
     version: main
   irobot_create_msgs:
     type: git
     url: https://github.com/iRobotEducation/irobot_create_msgs.git
     version: main                      
```
