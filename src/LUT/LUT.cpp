#include "LUT.h"

using namespace Function_Gen;

constexpr float PI = 3.141592654f;

LUT::LUT(){
    GenSine();
    GenSaw();
    GenSquare();
    GenTriangle();
}

void LUT::GenSine(){
    for(int i=0; i<LUT_size; i++){
        Sine[i] = sin(2.0f * PI * i / LUT_size);
    }
}

void LUT::GenSquare(){
    for(int i=0; i<LUT_size; i++){
        if(i < LUT_size / 2) Square[i]=1;
        else Square[i]=0;
    }
}

void LUT::GenTriangle(){
    for(int i = 0; i < LUT_size; i++){
        if(i < LUT_size / 2){
            Triangle[i] = 2.0f * i / LUT_size;
        } else{
            Triangle[i] = 2.0f - (2.0f * i / LUT_size);
        }
    }
}

void LUT::GenSaw(){
    for(int i = 0; i < LUT_size; i++){
        Saw[i] = static_cast<float>(i) / (LUT_size - 1);
    }
}

void LUT::FillSine(float *PLUT){
    
}