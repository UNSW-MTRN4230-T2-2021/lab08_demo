#!/usr/bin/python
#

from trajectory_msgs.msg import JointTrajectory
from sensor_msgs.msg import JointState
from std_msgs.msg import Header
from trajectory_msgs.msg import JointTrajectoryPoint

import os

import rospy
import tf
import math
import time 

from std_srvs.srv import Empty 
from gazebo_msgs.srv import SpawnModel

from geometry_msgs.msg import *

def spawn_box(pose):

    #INSERT CODE HERE (HINT: look into the gazebo/spawn_sdf_model)
    pass
    



def main():

    rospy.init_node('lab08_python')

    print("generating box (students to do)")

    ot = tf.transformations.quaternion_from_euler(0,0,0)
    pose = Pose(position = Point(x=1.71, y=0.1348, z=0.775), orientation = Quaternion(x=ot[0], y=ot[1], z=ot[2], w=ot[3]))

    spawn_box(pose)



if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        print ("Program interrupted before completion")
