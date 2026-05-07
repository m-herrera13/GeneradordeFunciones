#include "FunctionGenerator.h"

constexpr float PI = 3.141592654f;

using namespace FUNCTION_GENERATOR;

FunctionGenerator::FunctionGenerator(){
    _Oversampling = 4.0;
    SetTFreq(1.0);
    SetAmp(1.0);
    SetOffset(0.0);
    _Acc = 0.0; 
}

FunctionGenerator::FunctionGenerator(float tf, float amp, float offset, float os){
    _Oversampling = os;
    SetTFreq(tf);
    SetAmp(amp);
    SetOffset(offset);
    _Acc = 0.0; 
}

void FunctionGenerator::SetTFreq(float tf){
    _TFreq = tf;
    SetSFreq(_Oversampling);
}

float FunctionGenerator::TFreq() const{
    return _TFreq;
}

void FunctionGenerator::SetAmp(float amp){
    _Amp = amp;
    LookUpTable();
}

float FunctionGenerator::Amp() const{
    return _Amp;
}

void FunctionGenerator::SetOffset(float offset){
    _Offset = offset;
    LookUpTable();
}

float FunctionGenerator::Offset() const{
    return _Offset;
}

void FunctionGenerator::SetSFreq(float oversampling){
    _Oversampling = oversampling;
    _SFreq = _Oversampling * LUT_size * TFreq();
}

float FunctionGenerator::SFreq() const{
    return _SFreq;
}

float FUNCTION_GENERATOR::FunctionGenerator::Refresh(){
    _Acc += (_TFreq * LUT_size) / _SFreq;
    if(_Acc >= LUT_size) _Acc -= LUT_size;
    return _LUT[(uint16_t)_Acc];
}

Sine::Sine(){
    LookUpTable();
}

void Sine::LookUpTable(){
    for(int i=0; i<LUT_size; i++){
        _LUT[i] = Amp()*sin(2*PI*i/LUT_size)+Offset();
    }
}

Square::Square(){
    LookUpTable();
}

void Square::LookUpTable(){
    for(int i=0; i<LUT_size; i++){
        if(i < LUT_size / 2){
            _LUT[i]=Amp()+Offset();
        }else{
            _LUT[i]=Amp()*-1+Offset();
        }
    }
}

Triangle::Triangle(){
    LookUpTable();
}

void Triangle::LookUpTable(){
    for(int i = 0; i < LUT_size; i++){
        if(i < LUT_size / 2){
            _LUT[i] = -Amp() + (4.0*Amp()*i/LUT_size);
        }else{
            _LUT[i] = Amp() - (4.0*Amp()*(i - LUT_size / 2)/LUT_size);
        }
        _LUT[i] += Offset();
    }
}

Saw::Saw(){
    LookUpTable();
}

void Saw::LookUpTable(){
    for(int i = 0; i < LUT_size; i++){
        _LUT[i]=Amp()*(2.0*i/LUT_size-1.0)+Offset();
    }
}