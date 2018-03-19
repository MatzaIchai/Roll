#include "encodeur.h"




extern float vitesse1;

extern float vitesse2;

extern pthread_mutex_t mutexEnco1; 
extern pthread_mutex_t mutexEnco2; 

int make_periodic(unsigned int period, struct periodic_info *info)
{
	int ret;
	unsigned int ns;
	unsigned int sec;
	int fd;
	struct itimerspec itval;

	/* Create the timer */
//	fd = timerfd_create(CLOCK_MONOTONIC, 0);
	fd = timerfd_create(CLOCK_REALTIME, 0);

	info->wakeups_missed = 0;
	info->timer_fd = fd;
	if (fd == -1)
		return fd;

	/* Make the timer periodic */
	sec = period / 1000000;
	ns = (period - (sec * 1000000)) * 1000;
	itval.it_interval.tv_sec = sec;
	itval.it_interval.tv_nsec = ns;
	itval.it_value.tv_sec = sec;
	itval.it_value.tv_nsec = ns;
	ret = timerfd_settime(fd, 0, &itval, NULL);
	return ret;
}

void wait_period(struct periodic_info *info)
{
	unsigned long long missed;
	int ret;

	/* Wait for the next timer event. If we have missed any the
	   number is written to "missed" */
	ret = read(info->timer_fd, &missed, sizeof(missed));
	if (ret == -1)
	{
		perror("read timer");
		return;
	}

	info->wakeups_missed += missed;
	
}

// ********************Change les variables global de vitesse*********/                

void *get_vitesse1(void *arg) //mettre dans PID
{	
	int i=0;
	float vitesse=0;
	struct periodic_info info;
	long int  nb_tick_previous = 0;
	long int  nb_tick = 0;
	vitesse1 = 0;
	printf("Thread 1 period 10ms\n");
	make_periodic(10000, &info);
	while(rc_get_state()!=EXITING && ros::ok())
	{

		if(rc_get_state()==RUNNING)
		{
			nb_tick_previous = rc_get_encoder_pos(1);
			wait_period(&info);
			nb_tick = rc_get_encoder_pos(1);
			//vitesse = ((nb_tick -nb_tick_previous)*0.000151875) /(0.01/60); //* 6000
			vitesse = (nb_tick -nb_tick_previous)*0.91125;

			pthread_mutex_lock(&mutexEnco1);   
			vitesse1=vitesse;
			pthread_mutex_unlock(&mutexEnco1);

		}
		
	}
	pthread_exit(NULL);

}

void *get_vitesse2(void *arg)
{
	int i=0;
	float vitesse=0;
	struct periodic_info info;
	long int  nb_tick_previous = 0;
	long int  nb_tick = 0;
	vitesse2 = 0;
	printf("Thread 2 period 10ms\n");
	make_periodic(10000, &info);	
	while(rc_get_state()!=EXITING && ros::ok())
	{

		if(rc_get_state()==RUNNING)
		{
		nb_tick_previous = rc_get_encoder_pos(2);
		wait_period(&info);
		nb_tick = rc_get_encoder_pos(2);
		//vitesse = ((nb_tick -nb_tick_previous)*0.000151875) /(0.01/60); //* 6000
		vitesse = (nb_tick -nb_tick_previous)*0.91125; //* 6000
			

		pthread_mutex_lock(&mutexEnco2);   
		vitesse2=vitesse;	
		pthread_mutex_unlock(&mutexEnco2);
		}	
	}
	pthread_exit(NULL);
}