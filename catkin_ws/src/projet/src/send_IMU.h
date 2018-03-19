#ifndef send_IMU_HPP_
#define send_IMU_HPP_

#include "std_msgs/String.h"
#include <stdlib.h>
#include <stdio.h>
#include "geometry_msgs/Vector3.h"
#include "ros/ros.h"
#include "../IMU/IMU.h"


using namespace std;

extern "C"
{
#include "rc_usefulincludes.h"
}
extern "C"
{
#include "roboticscape.h"
}

#endif 