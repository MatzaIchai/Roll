#ifndef IMU_H_
#define IMU_H_



#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/timerfd.h>

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>        
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "ros/ros.h"

extern "C"
{
#include "rc_usefulincludes.h"
}
extern "C"
{
#include "roboticscape.h"
}

typedef struct Angles Angles;
struct Angles
{
    float data_PITCH;
    float data_ROLL;
    float data_YAW;
};

void calibrate();
int init_IMU();
void get_data(); // Printf IMU debug function




#endif