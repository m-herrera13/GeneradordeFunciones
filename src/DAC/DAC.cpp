#include "DAC.h"
#include <Wire.h>

using namespace Function_Gen;

void DAC::SetAddress(uint8_t Address){
    Addr=(Address & 0b01111111);
}

void DAC::SetAddress(bool A2, bool A1, bool A0){
    Addr = (0b01100000) | A2 << 2 | A1 << 1 | A0;
}

void DAC::Write(uint16_t x, DAC::Commands CM, DAC::Modes MD){
    uint16_t Data = (x & 0xFFF) | static_cast<uint16_t>(MD) << 12 | static_cast<uint16_t>(CM) << 14;

    uint8_t DataA = (Data >> 8) & 0xFF;
    uint8_t DataB = Data & 0xFF;

    Wire.beginTransmission(Addr);
    Wire.write(DataA);
    Wire.write(DataB);
    Wire.endTransmission();
}