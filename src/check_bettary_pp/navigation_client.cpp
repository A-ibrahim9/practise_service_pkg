#include "ros/ros.h"
#include "service_pkg/check_b.h"
#include "std_msgs/Float32.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "req_blevel_client");
    if (argc != 3)
    {
        ROS_INFO("usage: rosrun service_pkg req_blevel_client <battery_level> <mission_consumption>");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<service_pkg::check_b>("check_battery_level");
    service_pkg::check_b srv;
    srv.request.mission_consumption = atof(argv[2]);
    srv.request.battery_level = atof(argv[1]);
    if (client.call(srv))
    {
        ROS_INFO("Status: %s", srv.response.status.c_str());
        ROS_INFO("Battery Level After Mission: %.2f%%", srv.response.after_battery_level); //%% 
    }
    else
    {
        ROS_ERROR("Failed to call service /check_battery_level"); // بينادي او فشل انه ينادي علي السيرفر بس ملوش علاقة بالرسالة
        return 1;
    }

    return 0;
}