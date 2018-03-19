

#ifndef HDW_TALKER_HPP_
#define HDW_TALKER_HPP_


#include "ros/ros.h"
#include "std_msgs/String.h"

#include "../fonction/fonction.h"
#include "../encodeur/encodeur.h"
#include "../moteur/moteur.h"
#include "../PID/PID.h"
#include "projet/Vitesses.h"
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

