#include "ros/ros.h"
#include "service_pkg/safe_d.h"
// #include "std_srvs/Trigger.h"
#include "std_msgs/Float32.h"

bool add(service_pkg::safe_d::Request &req,
         service_pkg::safe_d::Response &res)
{
    if (req.distance >= 30.0)
    {
        res.status = "safe";
    }
    else
    {
        res.status = "danger";
    }
    ROS_INFO("request: distance=%.2f", req.distance);
    ROS_INFO("sending back response: [%s]", res.status.c_str());
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "safe_distance_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("check_distance_safe", add);
    ros::spin();

    return 0;
}