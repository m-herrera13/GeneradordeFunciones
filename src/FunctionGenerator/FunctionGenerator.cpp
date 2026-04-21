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

float FunctionGenerator::TFreq(){ return _TFreq; }

float FunctionGenerator::Amp(){ return _Amp; }

float FunctionGenerator::Offset(){ return _Offset; }

float FunctionGenerator::SFreq(){ return _SFreq; }

float FunctionGenerator::DutyCycle(){ return _DutyCycle; }

void FunctionGenerator::SetTFreq(float tf){

}     

void FunctionGenerator::SetAmp(float amp){

}     

void FunctionGenerator::SetOffset(float offset){
    
}

void FunctionGenerator::SetSFreq(float sf){

}

void FunctionGenerator::SetDutyCycle(float duty){

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