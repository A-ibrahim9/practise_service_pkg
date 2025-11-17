#include "ros/ros.h"
#include "service_pkg/check_b.h"
#include "std_msgs/Float32.h"

bool add(service_pkg::check_b::Request &req,
         service_pkg::check_b::Response &res)
{
    res.after_battery_level = req.battery_level - req.mission_consumption;

    if (res.after_battery_level < 0)
    {
        res.after_battery_level = 0;
    }
    else if (res.after_battery_level > 20.0)
    {
        res.status = "Start your mission";
    }
    else
    {
        res.status = "Battery low, please recharge";
    }
    ROS_INFO("request: battery level before start = %.2f%%, and mission consumption = %.2f%%", req.battery_level, req.mission_consumption);
    ROS_INFO("sending back response: [%s], Battery level after mission: %.2f%%", res.status.c_str(), res.after_battery_level);
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "power_manager_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("check_battery_level", add);
    ros::spin();

    return 0;
}