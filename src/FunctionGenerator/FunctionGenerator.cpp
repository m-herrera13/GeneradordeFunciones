#include "FunctionGenerator.h"

constexpr float PI = 3.141592654f;

using namespace Function_Gen;

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
}

float FunctionGenerator::Amp() const{
    return _Amp;
}

void FunctionGenerator::SetOffset(float offset){
    _Offset = offset;
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

void AttachDAC(DAC* DACx){ OutputDAC = DACx; }

float Function_Gen::FunctionGenerator::Refresh(){
    _Acc += (_TFreq * LUT_size) / _SFreq;
    if(_Acc >= LUT_size) _Acc -= LUT_size;
    return Amp()*pLUT[(uint16_t)_Acc]+Offset();
}

void FunctionGenerator::AttachLUT(LUT* mainLUT){ LUTfiller = mainLUT; }

void FunctionGenerator::SetWaveform(Waveform W){
    switch(W){
        case Waveform::Sine:
            LUTfiller->FillSine(pLUT);
            break;

        case Waveform::Square:
            LUTfiller->FillSquare(pLUT);
            break;

        case Waveform::Triangle:
            LUTfiller->FillTriangle(pLUT);
            break;

        case Waveform::Saw:
            LUTfiller->FillSaw(pLUT);
            break;

        case Waveform::ISaw:
            LUTfiller->FillISaw(pLUT);
            break;

        case Waveform::DC:
            LUTfiller->FillDC(pLUT);
            break;
    }
}