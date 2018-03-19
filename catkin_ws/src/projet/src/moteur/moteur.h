#ifndef MOTEUR_H_
#define MOTEUR_H_


extern "C"
{
#include "rc_usefulincludes.h"
}
extern "C"
{
#include "roboticscape.h"
}

int setup_output_pin(int pin, int val);
void init_Pins_PWM(int frequence_kHz);

void set_PWM_2(float pwm4);


void set_PWM_1(float pwm3);

void SEND_PWM_1(float pwm3); // Si sens = 1 avant sinon arriere 

void SEND_PWM_2(float pwm4); // Si sens = 1 avant sinon arriere 

void set_PWM(float pwm3, float pwm4);

void SEND_PWM(float pwm3, float pwm4); // Si sens = 1 avant sinon arriere 

void sleep_driver();

#endif