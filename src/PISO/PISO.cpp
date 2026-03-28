#include "PISO.h"
#include <stdint.h>

using namespace SR_KEYPAD;

PISO::PISO(){
    _DataController = nullptr;
    _ClockController = nullptr;
    _SLController = nullptr;
}
            
PISO::PISO(bool(&DataController)(void),
    void(&ClockController)(void),
    void(&SLController)(void)){
        _DataController = DataController;
        _ClockController = ClockController;
        _SLController = SLController;
}

uint8_t PISO::Read(uint8_t bits){

    uint8_t output = 0;

    if(_SLController){ _SLController(); }

    for (uint8_t i = 0; i<bits; i++){

        if (_DataController){
            output |= (_DataController() << i);
        }

        if (_ClockController){ _ClockController();}

    }
}

uint8_t* PISO::ReadArray(uint8_t bytes, uint8_t* buffer){

    if(_SLController){ _SLController(); }

    for (uint8_t i = 0; i<bytes*8; i++){

        buffer[i/8] = 0;
        if (_DataController){
            buffer[i/8] |= (_DataController() << i);
        }

        if (_ClockController){ _ClockController();}
    }
}