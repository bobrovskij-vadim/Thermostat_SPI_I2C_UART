/*
 * t_h_controller.c
 *
 * Created: 12.09.2022 17:24:14
 *  Author: vadim
 */ 

#include "T_H_controller.h"

void T_H_controller_port_settings(void)          //Function for port settings to control the temperature and humidity;
{
	//----------Temperature controlling----------
	DDRC |= (1<<HEATING) | (1<<REQUIRED_T) | (1<<COOLING);
	PORTC &= ~((1<<HEATING) | (1<<REQUIRED_T) | (1<<COOLING));
	
	//----------Humidity controlling----------
	DDRB |= (1<<DRYING) | (1<<REQUIRED_H) | (1<<HYDRATION);
	PORTB &= ~((1<<DRYING) | (1<<REQUIRED_H) | (1<<HYDRATION)); 
}

void T_H_maintain(float set_t, float set_h, float cur_t, float cur_h)    // Function control heating and cooling;        
{
	//--------Temperature--------
	if(set_t > cur_t)
	{
		PORTC |= (1<<HEATING);
		PORTC &= ~((1<<REQUIRED_T) | (1<<COOLING));
	}
	else if(set_t < cur_t)
	{
		PORTC |= (1<<COOLING);
		PORTC &= ~((1<<HEATING) | (1<<REQUIRED_T));
	}
	else if(set_t == cur_t)
	{
		PORTC |= (1<<REQUIRED_T);
		PORTC &= ~((1<<HEATING) | (1<<COOLING));
	}
	
	//----------Humidity----------
	if((int)set_h < (int)cur_h)
	{
		PORTB |= (1<<DRYING);
		PORTB &= ~((1<<REQUIRED_H) | (1<<HYDRATION));
	}
	else if((int)set_h > (int)cur_h)
	{
		PORTB |= (1<<HYDRATION);
		PORTB &= ~((1<<DRYING) | (1<<REQUIRED_H));
	}
	else if((int)set_h == (int)cur_h)
	{
		PORTB |= (1<<REQUIRED_H);
		PORTB &= ~((1<<DRYING) | (1<<HYDRATION));
	}
}


void T_H_button_settings(void)           //Ports settings for buttons;
{
	//--------Temperature--------
	DDRC &= ~(1<<PC3);  
	PORTC |= (1<<PC3);
	
	DDRB &= ~(1<<PB7);
	PORTB |= (1<<PB7);
	
	//----------Humidity----------
	DDRD &= ~((1<<PD0) | (1<<PD1));
	PORTD |= (1<<PD0) | (1<<PD1);
}