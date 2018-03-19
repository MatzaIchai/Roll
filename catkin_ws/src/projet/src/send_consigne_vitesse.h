#ifndef send_consigne_vitesse_HPP_
#define send_consigne_vitesse_HPP_

#include "std_msgs/String.h"
#include <stdlib.h>
#include <stdio.h>
#include "geometry_msgs/Twist.h"

#include "ros/ros.h"
#include "projet/Vitesses.h"


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