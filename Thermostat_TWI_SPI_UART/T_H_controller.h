/*
 * t_h_controller.h
 *
 * Created: 12.09.2022 17:23:49
 *  Author: vadim
 */ 


#ifndef T_H_CONTROLLER_H_
#define T_H_CONTROLLER_H_

#include "main.h"

#define HEATING     PC0
#define REQUIRED_T  PC1 
#define COOLING     PC2 

#define DRYING      PB0
#define REQUIRED_H  PB1
#define HYDRATION   PB6

void T_H_controller_port_settings(void);     // Function for port settings to control the temperature and humidity; 

void T_H_maintain(float set_t, float set_h, float cur_t, float cur_h);      // Function control heating and cooling;                

void T_H_button_settings(void);              // Ports settings for buttons;

#endif /* T_H_CONTROLLER_H_ */