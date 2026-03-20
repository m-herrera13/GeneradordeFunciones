#include "SIPO.h"
#include <stdint.h>

SR_KEYPAD::SIPO::SIPO(){
    _DataController = nullptr;
    _ClockController = nullptr;
    _LatchController = nullptr;
}
            
SR_KEYPAD::SIPO::SIPO(void(&DataController)(bool),
    void(&ClockController)(void),
    void(&LatchController)(void)){
        _DataController = DataController;
        _ClockController = ClockController;
        _LatchController = LatchController;
}

void SR_KEYPAD::SIPO::Write(uint8_t Data){
    for(uint8_t i = 0; i<8; i++){
        if(_DataController){ _DataController((Data>>i)&0b1); }
        if(_ClockController){ _ClockController(); }

    }

    if(_LatchController){ _LatchController(); }
}

void SR_KEYPAD::SIPO::Write(uint8_t* Data, uint8_t len){

    for(uint8_t i = 0; i<len*8; i++){
        if(_DataController){ _DataController((Data[i/8]>>(i%8))&0b1); }
        if(_ClockController){ _ClockController(); }

    }

    if(_LatchController){ _LatchController(); }
}