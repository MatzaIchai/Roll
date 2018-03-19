#include "IMU.h"



extern rc_imu_data_t data; 

extern Angles angles_calibrate;



void get_data() // Printf IMU debug function
{   
	printf("\r");
	printf(" ");
	

		// print TaitBryan angles
		printf("%6.1f %6.1f %6.1f |",	data.dmp_TaitBryan[TB_PITCH_X]*RAD_TO_DEG,\
										data.dmp_TaitBryan[TB_ROLL_Y]*RAD_TO_DEG,\
										data.dmp_TaitBryan[TB_YAW_Z]*RAD_TO_DEG);
	fflush(stdout); //vide le cache de l'affichage
	return;
}

int init_IMU()
{
		
	rc_imu_config_t conf = rc_default_imu_config();
	
	if(rc_initialize_imu_dmp(&data, conf))
	{
		printf("rc_initialize_imu_failed\n");
		return -1;
	}
	//	rc_set_imu_interrupt_func(&get_data); //genere interrupt intervalle regulier
	return 1;
}

void calibrate()
{
	rc_set_led(GREEN, OFF);
	rc_set_led(RED, ON);
	
	int i=0;
	for (i=0; i<3000; i++)
	{
		angles_calibrate.data_PITCH = 	angles_calibrate.data_PITCH + data.dmp_TaitBryan[TB_PITCH_X]; //*RAD_TO_DEG
		angles_calibrate.data_ROLL = angles_calibrate.data_ROLL + data.dmp_TaitBryan[TB_ROLL_Y];
		angles_calibrate.data_YAW = angles_calibrate.data_YAW + data.dmp_TaitBryan[TB_YAW_Z];
		usleep(100);
	}
	
	angles_calibrate.data_PITCH = angles_calibrate.data_PITCH / 3000;
	angles_calibrate.data_ROLL	= angles_calibrate.data_ROLL / 3000;
	angles_calibrate.data_YAW = angles_calibrate.data_YAW / 3000;
	
	rc_set_led(RED, OFF);
}