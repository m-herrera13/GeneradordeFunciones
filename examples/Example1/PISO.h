#ifndef MY_PISO_H
#define MY_PISO_H

  #include <FunctionGen.h>

  #define PISO_DATA_PIN   5
  #define PISO_CLOCK_PIN  6
  #define PISO_SL_PIN     7

  pinMode(PISO_DATA_PIN, INPUT);
  pinMode(PISO_CLOCK_PIN, OUTPUT);
  pinMode(PISO_SL_PIN, OUTPUT);

  bool PISO_DataController();
  void PISO_ClockController(void);
  void PISO_SLController(void);
  extern SR_Keypad::PISO myPISO;

#endif//MY_PISO_H