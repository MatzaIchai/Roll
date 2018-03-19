#ifndef ENCODEUR_H_
#define ENCODEUR_H_

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
#include "ros/ros.h"

#include <unistd.h>
#include <errno.h>
#include <sys/types.h>        
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

extern "C"
{
#include "rc_usefulincludes.h"
}
extern "C"
{
#include "roboticscape.h"
}


   
// ********************* Info pour créer la Période *********************/
struct periodic_info
{
	int timer_fd;
	unsigned long long wakeups_missed;
};


int make_periodic(unsigned int period, struct periodic_info *info);
void wait_period(struct periodic_info *info);



void *get_vitesse1(void *arg);
void *get_vitesse2(void *arg);


#endif
