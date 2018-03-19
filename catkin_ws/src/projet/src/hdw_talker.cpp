
#include "hdw_talker.h"


/////////////// Parametre vitesse /////////
float vitesse1;
float vitesse2;


//////////////// Paramètre scheduler //////////////////	
pthread_attr_t attr;
struct sched_param param;

////////////////////////// PID //////////////////////////
DataPID pid_1_info;
DataPID pid_2_info;


float vitesseD_consigne;
float vitesseG_consigne;
bool TestSleep;
pthread_mutex_t mutexG = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t mutexD = PTHREAD_MUTEX_INITIALIZER; 


pthread_mutex_t mutexEnco1 = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t mutexEnco2 = PTHREAD_MUTEX_INITIALIZER; 

ros::Duration d(0.01);
class Listener
{
	
public:


	void getConsigneCallback(const projet::Vitesses::ConstPtr& consigne_vitesses)
	{
	//	ROS_INFO("I heard: [%f]", consigne_vitesses->VitesseLineaire);
	//	ROS_INFO_STREAM("chatter1: [" <<  consigne_vitesses->VitesseDroite << "] ");
		
		
		pthread_mutex_lock(&mutexD);
		vitesseD_consigne = consigne_vitesses->VitesseDroite; //provient de Vitesse angulaire et lineaire
		pthread_mutex_unlock(&mutexD);

		pthread_mutex_lock(&mutexG);
		vitesseG_consigne = consigne_vitesses->VitesseGauche; //provient de Vitesse angulaire et lineaire
		pthread_mutex_unlock(&mutexG);
		
		TestSleep = consigne_vitesses->TestSleep; //provient de Vitesse angulaire et lineaire

		d.sleep();
	}
	
	
	

};




int main(int argc, char **argv)
{

    pthread_t t_vitesse1, t_vitesse2, t_PID_1, t_PID_2, t_send_data;
	int erreur;
	int fd = open("data.csv", O_CREAT|O_WRONLY|O_TRUNC);
	int ret;
	char buf[128];
	float int_erreur = 0;
	projet::Vitesses  VitesseRetournees;
	

		pthread_mutex_lock(&mutexD);
		vitesseD_consigne = 0; //provient de Vitesse angulaire et lineaire
		pthread_mutex_unlock(&mutexD);
		//vitesseD_consigne.mutex.unlock();

		pthread_mutex_lock(&mutexG);
		vitesseG_consigne = 0; //provient de Vitesse angulaire et lineaire
		pthread_mutex_unlock(&mutexG);
		//vitesseG_consigne.mutex.unlock();
	// always initialize cape library 
	
	
	ret = write(fd, buf, strlen(buf));
	if(ret <= 0)
	{
		perror("write\n");
		return -1;
	}
	
	if(rc_initialize()){
		fprintf(stderr,"ERROR: failed to initialize rc_initialize(), are you root?\n");
		return -1;
	}
    INIT();
    ros::init(argc, argv, "hdw_talker_node");
	
	ros::NodeHandle hdw_talker_node;
    SEND_PWM_2(0); //--> envoie PWM
	SEND_PWM_1(0); //--> envoie PWM
    init_scheduler();
	rc_set_state(RUNNING);

    signal(SIGINT,  ros_compatible_shutdown_signal_handler);	
    signal(SIGTERM, ros_compatible_shutdown_signal_handler);
    
   //	SEND_PWM_2(-20); //--> envoie PWM
	//SEND_PWM_1(20);

		//*******************\ THREADS PIDs/****************************/
		
			//**********\ PID 1 /*********************/
	set_priority(1);
	erreur = pthread_create(&t_PID_1, &attr,  PID_1, NULL);
	if(erreur < 0)
	{
		perror("pthread_create PID 1");
		return -1;
	}
	
			//**********\ PID 2 /*******************/
	set_priority(2);
	erreur = pthread_create(&t_PID_2, &attr,  PID_2, NULL);
	if(erreur < 0)
	{
		perror("pthread_create PID 2");
		return -1;
	}
	//*******************\ THREADS ENCODEURS/****************************/
			//*************\ ENCO 1	/*****************/
	
	set_priority(3);
	erreur = pthread_create(&t_vitesse1, &attr, get_vitesse1, NULL);
	if(erreur < 0)
	{
		perror("pthread_create ENCODEUR 1");
		return -1;
	}
	
			//*************\ ENCO 2	/*****************/
	set_priority(4);
	erreur = pthread_create(&t_vitesse2, &attr, get_vitesse2, NULL);
	if(erreur < 0)
	{
		perror("pthread_create ENCODEUR 2");
		return -1;
	}
	
	
	
	

	Listener l;
	ros::Subscriber sub1 = hdw_talker_node.subscribe("consigne_vitesse", 10, &Listener::getConsigneCallback, &l);
	ros::Publisher pub = hdw_talker_node.advertise<projet::Vitesses>("returnVitesse", 1);
	ros::AsyncSpinner s(2);
	s.start();
	ros::Rate r(5);
	sprintf(buf, "Time Vitesse Consigne Erreur Int_erreur PWM\n");

	while (rc_get_state()!=EXITING && ros::ok())
	{
//ROS_INFO_STREAM("Main thread [" << boost::this_thread::get_id() << "].");

	//printf("PWM: %f |vitesse %f | consigne %f | erreur %f\n ", pid_2_info.PWM, pid_2_info.vitesse, vitesseD_consigne, pid_2_info.times);
    int_erreur = int_erreur + pid_2_info.consigne-pid_2_info.vitesse;
    sprintf(buf, "%f %f %f %f %f %f\n", pid_2_info.times, pid_2_info.vitesse, pid_2_info.consigne, pid_2_info.consigne-pid_2_info.vitesse, int_erreur, pid_2_info.PWM);
	ret = write(fd, buf, strlen(buf));
	
	pthread_mutex_lock(&mutexEnco1);   
	VitesseRetournees.VitesseGauche= vitesse1; //provient du capteur
	pthread_mutex_unlock(&mutexEnco1);
	
	pthread_mutex_lock(&mutexEnco2);   
	VitesseRetournees.VitesseDroite = vitesse2; //provient du capteur
	pthread_mutex_unlock(&mutexEnco2);
	
	pub.publish(VitesseRetournees);

    ros::spinOnce();

   // r.sleep();
	usleep(50000);
		
	}
	SEND_PWM_2(0); //--> envoie PWM
	SEND_PWM_1(0); //--> envoie PWM
	sleep_driver();
	// news
	ROS_INFO("Exiting!");


	
	// Stop the ROS node's resources
	
//	pthread_join( t_vitesse1, NULL);
//	pthread_join(t_vitesse2, NULL);
//	pthread_join(t_PID_1, NULL);
//	pthread_join(t_PID_2,NULL);
	
		// shut down the pthreads
	rc_set_state(EXITING);
	ros::shutdown();

	rc_pwm_close(0);

	rc_cleanup(); 
    return 0;
}
