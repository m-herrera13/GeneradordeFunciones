#include "SIPO.h"
#include <stdint.h>

using namespace SR_KEYPAD;

SIPO::SIPO(){
    _DataController = nullptr;
    _ClockController = nullptr;
    _LatchController = nullptr;
}
            
SIPO::SIPO(void(&DataController)(bool),
    void(&ClockController)(void),
    void(&LatchController)(void)){
        _DataController = DataController;
        _ClockController = ClockController;
        _LatchController = LatchController;
}

void SIPO::Write(uint8_t Data){
    for(uint8_t i = 0; i<8; i++){
        this->Data((Data>>i)&0b1);
        Clock();
    }
    Latch();
}

void SIPO::Write(uint8_t* Data, uint8_t len){

    for(uint8_t i = 0; i<len*8; i++){
        this->Data((Data[i/8]>>(i%8))&0b1);
        Clock();
    }
    Latch();
}

void SIPO::Data(bool x){
    if(_DataController){_DataController(x);}
}

void SIPO::Clock(){
    if(_ClockController){ _ClockController(); }
}

void SIPO::Latch(){
    if(_LatchController){ _LatchController(); }
}