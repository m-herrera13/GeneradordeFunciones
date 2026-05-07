#include "DAC.h"
#include <Arduino.h>

using namespace DAC;

void i2c_CTRL::begin(){
    SDA_PORT |= (1 << SDA_PIN);
    SCL_PORT |= (1 << SCL_PIN);

    SDA_HIGH();
    SCL_HIGH();
}

void i2c_CTRL::endTransmission(){
    Stop();
}

MCP4725::MCP4725(i2c_CTRL* controller, uint8_t address){
    i2c = controller;
    Addr = address;
}

void MCP4725::setV(uint16_t x) {
    if(x > 4095) x = 4095;
    
    if(!i2c->beginTransmission(Addr)) return;

    if(!i2c->write(Msg1 | ((x>>8)&0xF))){
        i2c->endTransmission();
        return;
    }

    if(!i2c->write(x & 0xFF)){
        i2c->endTransmission();
        return;
    }

    i2c->endTransmission();
}
