#include "ros/ros.h"

#include "tf2/LinearMath/Quaternion.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"


#include "std_msgs/String.h"
#include <std_msgs/Float64.h>

#include "gazebo_msgs/SpawnModel.h" 
#include "geometry_msgs/Pose.h" 
#include "geometry_msgs/Point.h" 
#include "geometry_msgs/Quaternion.h" 

#include <sstream>
#include <fstream>
#include <math.h>

#include <chrono>
#include <thread>


void spawn_box(ros::NodeHandle n, geometry_msgs::Pose pose) {

    //INSERT CODE HERE (HINT: look into the gazebo/spawn_sdf_model)

}


int main(int argc, char **argv) {

    ros::init(argc, argv, "lab08_cpp");
    ros::NodeHandle n;

    geometry_msgs::Pose pose;
    pose.position.x = 1.71;
    pose.position.y = 0.1348;
    pose.position.z = 0.775;

    tf2::Quaternion myQuaternion;
    myQuaternion.setRPY( 0, 0, 0 );

    pose.orientation = tf2::toMsg(myQuaternion);

    std::cout << "generating box (students to do)" << std::endl;

    spawn_box(n,pose);
   
    return 0;
}
