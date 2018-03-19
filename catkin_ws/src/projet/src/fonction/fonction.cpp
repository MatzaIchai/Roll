#include "fonction.h"
#include "../moteur/moteur.h"

void ros_compatible_shutdown_signal_handler(int signo)
{
  if (signo == SIGINT)
    {
    rc_set_state(EXITING);
    ROS_INFO("\nReceived SIGINT Ctrl-C.");
    ros::shutdown();
    }
  else if (signo == SIGTERM)
    {
      rc_set_state(EXITING);
      ROS_INFO("Received SIGTERM.");
      ros::shutdown();
    }
}



/*******************************************************************************
* void on_pause_released() 
*	
* Make the Pause button toggle between paused and running states.
*******************************************************************************/
void on_pause_released(){
	// toggle betewen paused and running modes
	if(rc_get_state()==RUNNING)		rc_set_state(PAUSED);
	else if(rc_get_state()==PAUSED)	rc_set_state(RUNNING);
	return;
}
/*******************************************************************************
* void on_pause_pressed() 
*
* If the user holds the pause button for 2 seconds, set state to exiting which 
* triggers the rest of the program to exit cleanly.
*******************************************************************************/
void on_pause_pressed(){
	int i=0;
	const int samples = 100;	// check for release 100 times in this period
	const int us_wait = 2000000; // 2 seconds
	
	// now keep checking to see if the button is still held down
	for(i=0;i<samples;i++){
		rc_usleep(us_wait/samples);
		if(rc_get_pause_button() == RELEASED) return;
	}
	printf("long press detected, shutting down\n");
	rc_set_state(EXITING);
	return;
}


void ho()
{
  SEND_PWM_1(50);
     printf("ho \n");
}

void init_scheduler()
{
    
    pthread_attr_init(&attr); 
    pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED); 
    pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM); 
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO); 
    
}

void set_priority(int priority)
{
    param.sched_priority = priority; 
    pthread_attr_setschedparam(&attr, &param);  
}


void INIT()
{
  init_Pins_PWM(20);
  rc_set_pause_pressed_func(&on_pause_pressed);
  rc_set_pause_released_func(&on_pause_released);
  

  
}