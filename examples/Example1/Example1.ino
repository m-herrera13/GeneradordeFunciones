#include <FunctionGen.h>
#include "SIPO.h"
#include "PISO.h"
#include <stdint.h>

uint8_t Map[] = {
    /*
    
    
    
    */
};

void Callback(uint8_t id, bool state){
  if(state) Serial.println(Map[id]);
}

SR_Keypad::Controller KeypadController(Callback);

namespace Function_Gen{
    LUT mainLUT;
    DAC DAC0(0x60);
    DAC DAC1(0x61);
    FunctionGenerator CH1;
    FunctionGenerator CH2;
}

void setup(){
    Serial.begin(115200);
    Serial.println("Init");
    Wire.begin();

    KeypadController.AttachSIPO(mySIPO);
    KeypadController.AttachPISO(myPISO);

    CH1.AttachLUT(mainLut);
    CH2.AttachLUT(mainLut);
}

void loop(){
    myController.Scan();
    delay(100);
}