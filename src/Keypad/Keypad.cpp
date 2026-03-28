#include "Keypad.h"
#include <stdint.h>

using namespace SR_KEYPAD;

Controller::Controller(){
    ClearCallback();
    _out_controller = nullptr;
    _in_controller = nullptr;

    for(uint8_t i=0; i<8; i++){
        _prev_states[i]=0;
    }
};

Controller::Controller(void(&Callback)(uint8_t ID, bool State)){
    AttachCallback(Callback);
    _out_controller = nullptr;
    _in_controller = nullptr;

    for(uint8_t i=0; i<8; i++){
        _prev_states[i]=0;
    }
}

void Controller::AttachCallback(void(&Callback)(uint8_t ID, bool State)){
    _Callback = Callback;
}

void Controller::ClearCallback(){
    _Callback = nullptr;
}

void Controller::AttachSIPO(SIPO& SIPO_Controller){
    _out_controller = &SIPO_Controller;
}
void Controller::DetachSIPO(){
    _out_controller = nullptr;
}
void Controller::AttachPISO(PISO& PISO_Controller){
    _in_controller = &PISO_Controller;
}
void Controller::DetachPISO(){
    _in_controller = nullptr;
}

void Controller::Scan(){
    if(!_out_controller || !_in_controller || !_Callback) return;

    uint8_t NewStates[8] = {0,0,0,0,0,0,0,0};

    _out_controller->Data(0);

    for (uint8_t i = 0; i < 7; i++){
        _out_controller->Clock();
    }

    _out_controller->Data(1);

    for (uint8_t i = 0; i < 7; i++){

        if(i==1){
            _out_controller->Data(0);
        }

        _out_controller->Clock();
        _out_controller->Latch();

        NewStates[i] = _in_controller->Read(8);
    }

    for (uint8_t i = 0; i < 64; i++){
        bool prevState = (_prev_states[i/8]>>(i%8))&0b1;
        bool newState = (NewStates[i/8]>>(i%8))&0b1;

        if(prevState != newState) _Callback(i,newState);
    }
      
};