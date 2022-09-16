/*
 * EEPROM.h
 *
 * Created: 15.09.2022 17:37:08
 *  Author: vadim
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "main.h"

void EEPROM_write(unsigned int uiAddress, unsigned char ucData);     //Writing data to EEPROM.

unsigned char EEPROM_read(unsigned int uiAddress);                   //Reading data from EEPROM.

#endif /* EEPROM_H_ */