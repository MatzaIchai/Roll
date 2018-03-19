#include "../encodeur/encodeur.h"
#include "../moteur/moteur.h"

#include "PID.h"

//#include "../moteur/moteur.cpp"
 



extern DataPID pid_1_info;
extern DataPID pid_2_info;


extern float vitesse1;
extern float vitesse2;
extern pthread_mutex_t mutexEnco1; 
extern pthread_mutex_t mutexEnco2; 

extern bool TestSleep;

extern float vitesseD_consigne;
extern float vitesseG_consigne;
extern pthread_mutex_t mutexG; 
extern pthread_mutex_t mutexD; 


/* POUR L'ASSERV AVEC MUTEX ! */
//Protected_v test;

float erreurVitesseK_1_1 = 0;
float vitessek_1_1 = 0;
float erreurVitesseK_1_2 = 0;
float vitessek_1_2 = 0;
float somme_erreur1 = 0;
float somme_erreur2 = 0;
 



////////////////////////////////////////////////////////////////////////////////
//////////////////////////// ASSER AVEC RAMPE  //////////////////////////
////////////////////////////////////////////////////////////////////////////////


void asser_PID2(float consigne, float PWM, float erreurVitesse, float vitesse)
{
	 PWM =0;
     erreurVitesse = 0;
	 vitesse = 0;
	

	pthread_mutex_lock(&mutexEnco2);   
	vitesse = vitesse2; //provient du capteur
	pthread_mutex_unlock(&mutexEnco2);

	erreurVitesse = (consigne - vitesse);  
	erreurVitesseK_1_2 = (consigne - vitessek_1_2); //0 
	
	somme_erreur2 += erreurVitesse; 
	if (somme_erreur2>160)
		somme_erreur2=160;
		
	if (somme_erreur2<-160)
		somme_erreur2=-160;

	PWM = KI * (somme_erreur2) + KD * (erreurVitesse - erreurVitesseK_1_2) + KP*erreurVitesse;
	

	vitessek_1_2 = vitesse;
	
	if (TestSleep==false)
	{
		SEND_PWM_2(PWM); //--> envoie PWM
	}
	else
	{
		sleep_driver();
	}
	
	pid_2_info.vitesse = vitesse;
	pid_2_info.consigne = consigne; 

	pid_2_info.vitesseK_1 = vitessek_1_2; 
	
	pid_2_info.PWM = PWM;
	
	pid_2_info.vitesseK_1 = pid_1_info.vitesse;
	
	pid_2_info.times += SampledPeriod; //en ms
}


void asser_PID1(float consigne, float PWM, float erreurVitesse, float vitesse)
{
	 PWM =0;
     erreurVitesse = 0;

	 vitesse = 0;
	 
	
	pthread_mutex_lock(&mutexEnco1);   
	vitesse = vitesse1; //provient du capteur
	pthread_mutex_unlock(&mutexEnco1);

	erreurVitesse = (consigne - vitesse);  
	erreurVitesseK_1_1 = (consigne - vitessek_1_1); //0 
	
	somme_erreur1 += erreurVitesse; 
	if (somme_erreur1>160)
		somme_erreur1=160;
	
	if (somme_erreur1<-160)
		somme_erreur1=-160;
	
	
	
	PWM = KI * (somme_erreur1) + KD * (erreurVitesse - erreurVitesseK_1_1) + KP*erreurVitesse;
	

	vitessek_1_1 = vitesse;
	
	if (TestSleep==false)
	{
		SEND_PWM_1(PWM); //--> envoie PWM
	}
	else
	{
		sleep_driver();
	}
	pid_1_info.vitesse = vitesse;
	pid_1_info.consigne = consigne; 

	pid_1_info.vitesseK_1 = vitessek_1_1; 
	
	pid_1_info.PWM = PWM;
	
	pid_1_info.vitesseK_1 = pid_1_info.vitesse;
	
	pid_1_info.times += SampledPeriod; //en ms
}


void *PID_1(void *arg)
{
	struct periodic_info info;
	
	float PWM = 0;
	float erreurVitesse = 0;
	float vitesse = 0;
	
	float consigne = 0;
	float consigne_fixe = 0;
	float consigne_envoi = 0;
	float consigne_pre = 0;
	
	float diff_consigne = 0;
	
	
	pid_1_info.vitesse = 0;
	pid_1_info.vitesseK_1 = 0;

	pid_1_info.times = 0;
	pid_1_info.consigne = 0;
	pid_1_info.PWM =0;
	printf("PID 1 period 20ms\n");
	make_periodic(SampledPeriod*1000, &info);
	
	
		
	while(rc_get_state()!=EXITING && ros::ok())
	{       
		pthread_mutex_lock(&mutexG);
		consigne = vitesseG_consigne;
		pthread_mutex_unlock(&mutexG);
		
		diff_consigne = consigne - consigne_pre;
		
		consigne_envoi = consigne_pre + diff_consigne*PERCENT;
		
		asser_PID1(consigne_envoi, PWM, erreurVitesse, vitesse);
		
		wait_period(&info);	
		consigne_pre = consigne_envoi;
		
	}
	
	pthread_mutex_destroy(&mutexG);
	pthread_exit(NULL);
	
}


void *PID_2(void *arg)
{
	struct periodic_info info;
	float PWM = 0;
	float erreurVitesse = 0;
	float vitesse = 0;

	float consigne = 0;
	float consigne_fixe = 0;
	float consigne_envoi = 0;
	float consigne_pre = 0;
	
	bool test = false;
	float diff_consigne = 0;
	
	
	pid_2_info.vitesse = 0;
	pid_2_info.vitesseK_1 = 0;

	pid_2_info.times = 0;
	pid_2_info.consigne = 0;
	pid_2_info.PWM =0;
	printf("PID 2 period 20ms\n");
	make_periodic(SampledPeriod*1000, &info);
	
	
		
	while(rc_get_state()!=EXITING && ros::ok())
	{   
		pthread_mutex_lock(&mutexD);
		consigne = vitesseD_consigne;
		pthread_mutex_unlock(&mutexD);
		
		diff_consigne = consigne - consigne_pre;
		
		consigne_envoi = consigne_pre + diff_consigne*PERCENT;
		
		asser_PID2(consigne_envoi, PWM, erreurVitesse, vitesse);
		
		wait_period(&info);	
		consigne_pre = consigne_envoi;
		
	}
	
	pthread_mutex_destroy(&mutexD);
	pthread_exit(NULL);

}
