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

    ros::ServiceClient spawnModel = n.serviceClient<gazebo_msgs::SpawnModel>("gazebo/spawn_sdf_model");
    spawnModel.waitForExistence();
    gazebo_msgs::SpawnModel srv;

    srv.request.model_name = "spawnedCubeCpp";

    // load sdf file
    std::ifstream ifs;
    ifs.open("src/lab08_activity/models/cube/cube.sdf");
    std::stringstream buffer;
    buffer << ifs.rdbuf();

    srv.request.model_xml = buffer.str();

    srv.request.initial_pose = pose;
    srv.request.robot_namespace = "/";
    srv.request.reference_frame = "world";

    spawnModel.call(srv);


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
