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
    //SetDutyCycle(duty);
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

float FUNCTION_GENERATOR::FunctionGenerator::Refresh(){
    _Acc += 2*PI*_TFreq/_SFreq;
    if(_Acc > 2*PI)_Acc -= 2*PI;
    return _Amp*sin(_Acc)+_Offset;
    return 0.0;
}   

void Sine::LookUpTable(){
    for(int i=0; i<128; i++){
        _LUT[i] = Amp()*sin(2*PI*i/128)+Offset();
    }
}


void Square::LookUpTable(){
    for(int i=0; i<128; i++){
        if(i<64){
            _LUT[i]=Amp()+Offset();
        }else{
            _LUT[i]=Amp()*-1+Offset();
        }
    }
}

void Triangle::LookUpTable(){
    for(int i=0; i<128; i++){
        if(i<64){
            _LUT[i]=Amp()*(2.0*i/128.0-1.0)+Offset();
        }else{
            _LUT[i]=Amp()*(1.0-2.0*(i-64)/128.0)+Offset();
        }
    }
}

void Saw::LookUpTable(){

}