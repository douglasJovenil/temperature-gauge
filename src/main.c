#include "main.h"

void main(){
  definitions();
  
  while(TRUE){
    if (getValueADC(ADC_CH2, FULL_NUMBER) < 100){
      setLed(&LATC, CLK1, getValueADC(ADC_CH2, DECIMAL));
      setLed(&LATC, CLK2, getValueADC(ADC_CH2, UNITARY));
      LED = LOW;
    } else {
      setLed(&LATC, CLK1, 9);
      setLed(&LATC, CLK2, 9);
      delay(100);
      LED = ~LED;
    }
    delay(100);
  }
}

int8_t getValueADC(int8_t PIN, uint8_t number_part){
  SetChanADC(PIN); 
  ConvertADC();          
  while(BusyADC());
  switch (number_part){
    case DECIMAL: return (int)(ReadADC()*0.49) / 10;
    case UNITARY: return (int)(ReadADC()*0.49) % 10;
    case FULL_NUMBER: return (int)(ReadADC()*0.49);
    default: return -1;
  }
}

void definitions() {
    CMCON=0b00000101;
    TRISA = 0b00001111;
    TRISC = OUT;
    OpenADC(ADC_FOSC_16 & ADC_RIGHT_JUST & ADC_4_TAD, ADC_CH0 & ADC_INT_OFF & ADC_REF_VDD_VSS, ADC_6ANA); 
}

void delay(uint32_t time){
    for (uint32_t i = 0; i < time; i++) __delay_ms(1);
}