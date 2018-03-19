#ifndef CONVERSION_HPP_
#define CONVERSION_HPP_

#include "std_msgs/String.h"
#include <stdlib.h>
#include <stdio.h>
#include "geometry_msgs/Twist.h"

#include "geometry_msgs/Vector3.h" // ajout

#include "ros/ros.h"
#include "projet/IMU.h"


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