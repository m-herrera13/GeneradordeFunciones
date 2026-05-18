#include "SIPO.h"
#include <Arduino.h>

void initSIPO(){
  pinMode(SIPO_DATA_PIN, OUTPUT);
  pinMode(SIPO_CLOCK_PIN, OUTPUT);
  pinMode(SIPO_LATCH_PIN, OUTPUT);
}

void SIPO_DataController(bool value){
  digitalWrite(SIPO_DATA_PIN, value);
}

void SIPO_ClockController(void){
  digitalWrite(SIPO_CLOCK_PIN,1);
  digitalWrite(SIPO_CLOCK_PIN,0);
}

void SIPO_LatchController(void){
  digitalWrite(SIPO_LATCH_PIN,1);
  digitalWrite(SIPO_LATCH_PIN,0);
}

SR_Keypad::SIPO mySIPO(
  SIPO_DataController,
  SIPO_ClockController,
  SIPO_LatchController
);