#ifndef MY_SIPO_H
#define MY_SIPO_H

  #include <FunctionGen.h>
  #include <Arduino.h>

  #define SIPO_DATA_PIN  8
  #define SIPO_CLOCK_PIN 9
  #define SIPO_LATCH_PIN 10 

  void initSIPO();

  void SIPO_DataController(bool value);
  void SIPO_ClockController(void);
  void SIPO_LatchController(void);
  extern SR_Keypad::SIPO mySIPO;

#endif