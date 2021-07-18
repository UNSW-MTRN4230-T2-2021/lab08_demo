
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

Then, symbolically link the lab 8 package located in the repo to your lab08 workspace using the following command:

```bash
ln -s ~/lab_demo_repos/lab08_demo/lab08_activity ~/lab_workspaces/lab08_ws/src
```

Then, symbolically link the ur_description package to your lab08 workspace using the follow command:

```bash
ln -s ~/ur5e_repos/fmauch_universal_robot/ur_description ~/lab_workspaces/lab08_ws/src
```

Then finally build the lab08 workspace and source the setup script using the following commands:

```bash
cd ~/lab_workspaces/lab08_ws
catkin_make
source devel/setup.bash
```

You should now be able to run the lab 8 launch file via the following command:

```bash
roslaunch lab08_activity lab08.launch
```

This should launch Gazebo and add a table to the world

## Task 1: Including the UR5e in Gazebo

Currently the lab08 launch file only launches a world containing a table. This is because the included [`lab08_robot_description.urdf.xacro`](lab08_activity/urdf/lab08_robot_description.urdf.xacro) has not been implemented and is empty.

[`lab08.launch`](lab08_activity/launch/lab08.launch) includes this file in the following line:
```xml
  <param  name="robot_description" command="$(find xacro)/xacro '$(find lab08_activity)/urdf/lab08_robot_description.urdf.xacro'"/>
``` 

Your task is to add to `lab08_robot_description.urdf.xacro` so that the UR5e model within the `ur_description` package is included and linked to the `/world` link 

The following pose is recommended for linking the UR5e to the world: `<origin xyz="0.8 0.0 0.675" rpy="0.0 0.0 0.0" />`

Once you have completed this task running the launch command `roslaunch lab08_activity lab08.launch` should launch Gazebo with the UR5e added to the world

Guidance on how include the UR5e model into the `lab08_robot_description.urdf.xacro` file can be found [here](http://wiki.ros.org/xacro#Including_other_xacro_files).

Guidance on how to link the UR5e to the `/world` link can be found [here](http://wiki.ros.org/urdf/XML/joint).

## Task 2: Including a Camera in Gazebo

Now that you have included the UR5e in Gazebo, the second task is to include a camera in Gazebo. To accomplish this you must add to [`lab08_camera_description.urdf.xacro`](lab08_activity/urdf/lab08_camera_description.urdf.xacro). 

[`lab08.launch`](lab08_activity/launch/lab08.launch) includes this file in the following line:

```xml
<param name="camera_description" command="$(find xacro)/xacro '$(find lab08_activity)/urdf/lab08_camera_description.urdf.xacro'" />
``` 

This task is similar to first task. You must include camera_model within the `lab08_activity` package and link it to the `/world` link

The following pose is recommended for linking the camera to the world: `<origin xyz="1.9 0.25 1.675" rpy="0.0 ${pi/2.6} ${pi}" />`

Once this task is completed, running the launch command `roslaunch lab08_activity lab08.launch` should launch Gazebo with the UR5e and a camera added to the world. You can view the camera feed by subscribing to the `/camera/image_raw` topic using RViz.

To view the camera feed in RViz:

1. Launch RViz by typing RViz in the terminal and pressing enter
2. Within RViz, click on Panels -> Add New Panel -> Displays -> OK
3. Click the add button in the bottom left-hand corner of RViz
4. Click on by topic -> Image -> OK

Alternate documentation on how to subscribe to an image topic in RViz can be seen [here](https://answers.ros.org/question/263977/how-to-subscribe-to-image_transport-topic-in-rviz/)

## Task 3: Spawning a Cube in Gazebo using ROS

The `lab_activity` package includes a python script node located at [`lab08_activity/src/scripts/spawn_box_python.py`](lab08_activity/src/scripts/spawn_box_python.py) and a C++ node located at [`lab08_activity/src/nodes/spawn_box_cpp.cpp`](lab08_activity/src/nodes/spawn_box_cpp.cpp). Your task is to pick one of the two programs and add to it so that when the node is run a white cube is spawned into the Gazebo world.

The cube model that should be spawned into Gazebo is located at [`lab08_activity/models/cube/cube.sdf`](lab08_activity/models/cube/cube.sdf).

You should make use of the `/gazebo/spawn_sdf_model` rosservice in completing this task

Documentation on `/gazebo/spawn_sdf_model` can be found [here](http://gazebosim.org/tutorials/?tut=ros_comm#Services:Createanddestroymodelsinsimulation).

The python script can be called via the following command:

```bash
rosrun lab08_activity spawn_box_python.py
```

The C++ node can be called via the following command:

```bash
rosrun lab08_activity spawn_box_cpp
```

Note that you must run `catkin_make` after changing the C++ node for the changes to take affect

## Task 4: Spawning a Textured Cube in Gazebo using ROS

Your final task is to change either the `spawn_box_python.py` script or the `spawn_box_cpp.cpp` node so that it spawns a textured box instead of a white box

The textured cube model that should be spawned into Gazebo is located at [`lab08_activity/models/cube_textured/cube_textured.sdf`](lab08_activity/models/cube_textured/cube_textured.sdf) however you must alter the `cube_textured.sdf` file so that the material is changed from white to a texture of your choice

Documentation on how to add a material texture to a sdf file can be found [here](http://sdformat.org/spec?ver=1.6&elem=material).
