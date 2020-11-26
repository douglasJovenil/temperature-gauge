#ifndef __MAIN__H__
#define __MAIN__H__

#include "pic18f4550_config.h"
#include "defines.h"
#include "ADC_config.h"
#include "74HC164.h"

int8_t getValueADC(int8_t PIN, uint8_t number_part);
void definitions();
void delay(uint32_t time);

#endif