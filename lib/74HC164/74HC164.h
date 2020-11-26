#ifndef __74HC164__H__
#define __74HC164__H__

#include "pic18f4550_config.h"
#include "defines.h"

#define PIN_REGISTER 0b00000001
#define SIZE_BIN_ARRAY 8
#define TRUE 1
#define FALSE 0

void numToArray(uint8_t num, uint8_t array[]);
uint8_t to7Seg(uint8_t num);
void setLed(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t value);

#endif