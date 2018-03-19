#ifndef FONCTION_H_
#define FONCTION_H_



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

extern pthread_attr_t attr;

extern struct sched_param param;

void ros_compatible_shutdown_signal_handler(int signo);


void on_pause_released();
void on_pause_pressed();

void ho();
void init_scheduler();
void set_priority(int priority);
void INIT();




#endif