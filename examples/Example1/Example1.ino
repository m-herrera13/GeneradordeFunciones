#include <FunctionGen.h>
#include "SIPO.h"
#include "PISO.h"
#include <stdint.h>

uint8_t Map[] = {
    /*
    
    
    
    */
};

namespace Hardware{
    Function_Gen::DAC DAC0(0x60);
    Function_Gen::DAC DAC1(0x61);
}

namespace TopLevel{
    Function_Gen::LUT mainLUT;
    Function_Gen::FunctionGenerator CH1;
    Function_Gen::FunctionGenerator CH2;
}

void Callback(uint8_t id, bool state){
  if(state) Serial.println(Map[id]);
}

namespace Hardware{
    SR_Keypad::Controller KeypadController(Callback);
}

void setup(){
    Serial.begin(115200);
    Serial.println("Init");
    Wire.begin();
    initSIPO();
    initPISO();

    Hardware::KeypadController.AttachSIPO(mySIPO);
    Hardware::KeypadController.AttachPISO(myPISO);

    TopLevel::CH1.AttachLUT(&TopLevel::mainLUT);
    TopLevel::CH2.AttachLUT(&TopLevel::mainLUT);
}

void loop(){
    Hardware::KeypadController.Scan();
    delay(100);
}