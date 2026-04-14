#include "FunctionGenerator.h"

const double PI = 3.141592654;

using namespace FUNCTION_GENERATOR;

FunctionGenerator::FunctionGenerator(){
    SetTFreq(1.0);
    SetAmp(1.0);
    SetOffset(0.0);
    SetSFreq(100);
    LookUpTable();
}

FunctionGenerator::FunctionGenerator(float tf, float amp, float offset, float duty, float sfreq){
    SetTFreq(tf);
    SetAmp(amp);
    SetOffset(offset);
    SetSFreq(sfreq);
    SetDutyCycle(duty);
    LookUpTable(); 
}

void FunctionGenerator::SetTFreq(float tf){
    _TFreq = tf;
}

float FunctionGenerator::TFreq(){
    return _TFreq;
}

void FunctionGenerator::SetAmp(float amp){
    _Amp = amp;
}

float FunctionGenerator::Amp(){
    return _Amp;
}

void FunctionGenerator::SetOffset(float offset){
    _Offset = offset;
}

float FunctionGenerator::Offset(){
    return _Offset;
}

void FunctionGenerator::SetSFreq(float sf){
    _SFreq = sf;
}

float FunctionGenerator::SFreq(){
    return _SFreq;
}

void FunctionGenerator::SetDutyCycle(float duty){
    _DutyCycle = duty;
}     

float FunctionGenerator::DutyCycle(){
    return _DutyCycle;
}

float FUNCTION_GENERATOR::FunctionGenerator::Refresh(){
    _Acc += 2*PI*_TFreq/_SFreq;
    if(_Acc > 2*PI)_Acc -= 2*PI;
    return _Amp*sin(_Acc)+_Offset;
    return 0.0;
}   

void Sine::LookUpTable(){
    
}


void Square::LookUpTable(){
    float duty = DutyCycle();
    for (uint16_t i = 0; i < 512; i++){
        if (i<(512*duty)) _LUT[i] = Amp() + Offset();
        else _LUT[i] = Offset();
    }
}



void Triangle::LookUpTable(){

}


void Saw::LookUpTable(){

}