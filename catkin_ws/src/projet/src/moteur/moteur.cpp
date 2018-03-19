#include "moteur.h"

int setup_output_pin(int pin, int val){

	if(rc_gpio_export(pin)){
		fprintf(stderr,"ERROR: Failed to export gpio pin %d\n", pin);
		return -1;
	}
	if(rc_gpio_set_dir(pin, OUTPUT_PIN)){
		fprintf(stderr,"ERROR: Failed to set gpio pin %d as output\n", pin);
		return -1;
	}
	if(rc_gpio_set_value(pin, val)){
		fprintf(stderr, "ERROR: Failed to set gpio pin %d value\n", pin);
		return -1;
	}
	return 0;
}
void init_Pins_PWM(int frequence_kHz)
{
		rc_set_pinmux_mode(GPS_HEADER_PIN_4, PINMUX_PWM);
		rc_set_pinmux_mode(GPS_HEADER_PIN_3, PINMUX_PWM);
		rc_pwm_init(0, frequence_kHz*1000);
		setup_output_pin(BLUE_GP0_PIN_3, 0); //sens de rotation 1
		setup_output_pin(BLUE_GP0_PIN_4, 0); //sens de rotation 2
		setup_output_pin(BLUE_GP0_PIN_5, 0); //inhibiteur
}

void set_PWM_2(float pwm4)
{
		if (pwm4 < 0)
	{
		pwm4 = -pwm4;
	}
	if ( pwm4 > 100 )
		{
			//printf("PWM TROP GRAND \n");
			rc_pwm_set_duty(0, 'A', 1);
		}
	else if ( pwm4 < -100 )
		{
			printf("PWM TROP PETIT \n");
			rc_pwm_set_duty(0, 'A', 0);
		}
	else 
		{
			if (pwm4 < 0)
			{
				pwm4 = -pwm4;
			}
			rc_pwm_set_duty(0, 'A', pwm4*0.01);
		}
}

void set_PWM_1(float pwm3)
{
		if (pwm3 < 0)
	{
		pwm3 = -pwm3;
	}
	if ( pwm3 > 100 )
		{
			//printf("PWM TROP GRAND \n");
			rc_pwm_set_duty(0, 'B', 1);

		}
	else if ( pwm3 < -100 )
		{
			printf("PWM TROP PETIT \n");
			rc_pwm_set_duty(0, 'B', 0);

		}
	else 
		{
			if (pwm3 < 0)
			{
				pwm3 = -pwm3;
			}
			rc_pwm_set_duty(0, 'B', pwm3*0.01);
		}
}

void SEND_PWM_1(float pwm3) // Si sens = 1 avant sinon arriere 
{
	setup_output_pin(BLUE_GP0_PIN_5, 1); //activation des ponts
	set_PWM_1(pwm3);
	
	if (pwm3 > 0)
	{
		setup_output_pin(BLUE_GP0_PIN_3, 1); //on avance  
	}
	else 
	{
		setup_output_pin(BLUE_GP0_PIN_3, 0); //on recule  
	}

}

void SEND_PWM_2(float pwm4) // Si sens = 1 avant sinon arriere 
{
	setup_output_pin(BLUE_GP0_PIN_5, 1); //activation des ponts
	
	set_PWM_2(pwm4);
	if (pwm4 > 0)
	{
		setup_output_pin(BLUE_GP0_PIN_4, 1); //on avance  
	}
	else 
	{
		setup_output_pin(BLUE_GP0_PIN_4, 0); //on recule  
	}

}
void set_PWM(float pwm3, float pwm4)
{
	if (pwm3 < 0)
	{
		pwm3 = -pwm3;
	}
	if (pwm4 < 0)
	{
		pwm4 = -pwm4;
	}
	if ( pwm4 > 100 || pwm3 > 100 )
		{
			printf("PWM TROP GRAND \n");

		}
	else if ( pwm4 < -100 || pwm3 < -100 )
		{
			printf("PWM TROP PETIT \n");
		}
	else 
		{
			if (pwm3 < 0)
			{
				pwm3 = -pwm3;
			}
			if (pwm4 < 0)
			{
				pwm4 = -pwm4;
			}
			rc_pwm_set_duty(0, 'B', pwm3*0.01);
			rc_pwm_set_duty(0, 'A', pwm4*0.01);
		}
}

void SEND_PWM(float pwm3, float pwm4) // Si sens = 1 avant sinon arriere 
{	
	setup_output_pin(BLUE_GP0_PIN_5, 1); //activation des ponts
	
	set_PWM(pwm3, pwm4);
	
	if (pwm3 > 0.5)
	{
		setup_output_pin(BLUE_GP0_PIN_3, 1); //on avance  
	}
	else 
	{
		setup_output_pin(BLUE_GP0_PIN_3, 0); //on recule  
	}
	if (pwm4 > 0.5)
	{
		setup_output_pin(BLUE_GP0_PIN_4, 1); //on avance 
	}
	else  
	{
		setup_output_pin(BLUE_GP0_PIN_4, 0); //on recule
	}
	
}


void sleep_driver()
{
	set_PWM( 0, 0);
	setup_output_pin(BLUE_GP0_PIN_5, 0); //desactivation des ponts

}
