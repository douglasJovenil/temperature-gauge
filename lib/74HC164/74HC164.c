#include "74HC164.h"

void numToArray(uint8_t num, uint8_t array[]){
  for (int i = SIZE_BIN_ARRAY - 1; i >= 0; i--){
    array[i] = (num > 0) ? (num % 2) : 0;
    num /= 2;
  }
}

uint8_t to7Seg(uint8_t num){
  switch(num){
    case 0: return 0b00111111;
    case 1: return 0b00000110;
    case 2: return 0b01011011;
    case 3: return 0b01001111;
    case 4: return 0b01100110;
    case 5: return 0b01101101;
    case 6: return 0b01111100;
    case 7: return 0b00000111;
    case 8: return 0b01111111;
    case 9: return 0b01101111;
    default: return 0b01111001;
  }
}

void setLed(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t value){
  uint8_t bin_value[SIZE_BIN_ARRAY];
  numToArray(to7Seg(value), bin_value);

  for (uint8_t i = 0; i < SIZE_BIN_ARRAY; i++){
    *LAT = PIN_REGISTER & bin_value[i];
    *LAT |= pin_clk;
    *LAT = PIN_REGISTER & bin_value[i];
  }
}