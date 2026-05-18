#ifndef MY_PISO_H
#define MY_PISO_H

  #include <FunctionGen.h>
  #include <Arduino.h>

  #define PISO_DATA_PIN   5
  #define PISO_CLOCK_PIN  6
  #define PISO_SL_PIN     7

  void initPISO();

  bool PISO_DataController();
  void PISO_ClockController(void);
  void PISO_SLController(void);
  extern SR_Keypad::PISO myPISO;

#endif//MY_PISO_H