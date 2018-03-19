#ifndef PID_H_
#define PID_H_


extern "C"
{
#include "rc_usefulincludes.h"
}
extern "C"
{
#include "roboticscape.h"
}
#include "ros/ros.h"

#define SampledPeriod 20 //en ms 20000
#define KI 0.4//0.5			//KI 0.0162
#define KD 0.008
#define KP 0.4 //0.68	

#define PERCENT 0.025

typedef struct
{
	float consigne;
	float times;
	
	float vitesse;
	float vitesseK_1;
	float PWM;
	
}DataPID;


typedef struct
{
	DataPID info1;
	DataPID info2;
	
	
}InfoSocket;


typedef struct
{
    bool test;
    pthread_mutex_t mutex;
    
}Protected_v;

void *PID_2(void *arg);
void *PID_1(void *arg);

void asser_PID2(float consigne, float PWM, float erreurVitesse, float vitesse);
void asser_PID1(float consigne, float PWM, float erreurVitesse, float vitesse);


#endif