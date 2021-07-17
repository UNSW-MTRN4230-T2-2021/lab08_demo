
# MTRN4230 Lab 8

## Setup

First, create the new catkin workspace for the lab by running the following command:

```bash
mkdir -p ~/lab_workspaces/lab08_ws/src
```

Then clone this repo into the `~/lab_demo_repos/` directory using the following commands:

```bash
cd ~/lab_demo_repos
git clone https://github.com/UNSW-MTRN4230-T2-2021/lab08_demo.git
```

Then, symbolically link the two packages located in the repo to your lab08 workspace using the following command:

```bash
ln -s ~/lab_demo_repos/lab08_demo/lab08_activity ~/lab_workspaces/lab08_ws/src
ln -s ~/lab_demo_repos/lab08_demo/mtrn4230_gazebo ~/lab_workspaces/lab08_ws/src
```

Then, symbolically link the ur_description package to your lab08 workspace using the follow command:

```bash
ln -s ~/ur5e_repos/fmauch_universal_robot/ur_description ~/lab_workspaces/lab08_ws/src
```

Then finally make your workspace and source the setup script using the following commands:
