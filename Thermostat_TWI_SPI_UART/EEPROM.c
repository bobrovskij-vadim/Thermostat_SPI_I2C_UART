/*
 * EEPROM.c
 *
 * Created: 15.09.2022 17:37:43
 *  Author: vadim
 */ 

#include "EEPROM.h"

void EEPROM_write(unsigned int uiAddress, unsigned char ucData)  //Writing data to EEPROM.
{
	while(EECR & (1<<EEWE))         //Wait for completion of previous write
	;
	EEAR = uiAddress;               //Set up address
	EEDR = ucData;                  //and data registers.
	EECR |= (1<<EEMWE);             //Write logical one to EEMWE.
	EECR |= (1<<EEWE);              //Start EEPROM write by setting EEWE.
}

unsigned char EEPROM_read(unsigned int uiAddress)             //Reading data to EEPROM.
{
	while(EECR & (1<<EEWE))          //Wait for completion of previous write.
	;
	EEAR = uiAddress;                //Set up address register.
	EECR |= (1<<EERE);               //Start EEPROM read by writing EERE.
	return EEDR;                     //Return data from data register.
}