/*
 * main.h
 *
 * Created: 05.09.2022 11:59:14
 *  Author: vadim
 *
 *	Thermostat
 *
 *	Application area:
 *		Apartments;
 *		House;
 *		Greenhouse;
 *		Growbox;
 *		Other places where distantionaly temperature controlling could be useful;
 *
 *	Used technologies:
 *		C, Proteus;
 *
 *	Used interfaces:
 *		I2C / TWI;
 *	   	SPI;
 *		UART
 *
 *	Used equipment:
 *		Microcontroller - microchip AVR ATMEGA8 DIP-28 pins - 2 units;
 *		Temperature sensor SENSIRION SHT21 - 1 unit;
 *		LCD LM016L - 1 unit;
 *		Led-GREEN - 2 unit;
 *		Led-YELLOW - 1 unit;
 *		Led-BLUE - 1 unit;
 *		Led-RED - 1 unit;
 * 		Button - 4 units;
 *		Resistor 300 Om - 6 units;
 *		Resistor 4k7 Om - 2 units;
 *
 */


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <avr/interrupt.h>


#include "LCD.h"
#include "I2C.h"
#include "SPI.h"
#include "EEPROM.h"
#include "T_H_controller.h"
#include "secondary_functions.h"


#endif /* MAIN_H_ */