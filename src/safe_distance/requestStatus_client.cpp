#include "ros/ros.h"
#include "service_pkg/safe_d.h"
#include "std_msgs/Float32.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "req_distance_client");
    if (argc != 2)
    {
        ROS_INFO("usage: rosrun service_pkg req_distance_client <distance>");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<service_pkg::safe_d>("check_distance_safe");
    service_pkg::safe_d srv;
    srv.request.distance = atof(argv[1]);
    if (client.call(srv))
    {
        ROS_INFO("Status: %s", srv.response.status.c_str());
    }
    else
    {
        ROS_ERROR("danger");
        return 1;
    }

    return 0;
}