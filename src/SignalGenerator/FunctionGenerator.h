#ifndef FUNCTION_GENERATOR_H
#define FUNCTION_GENERATOR_H

#include <stdint.h>
#include <cmath>

namespace FUNCTION_GENERATOR{
        
    class FunctionGenerator{
    private:
        float _Freq;
        float _Amp;
        float _Offset;
        float _fs;

    protected:
        float dTheta;
        float theta;        

    public:
        FunctionGenerator();
        void SetTFreq(float tf);        //Target frequency
        float TFreq();
        void SetAmp(float amp);         //Amplitude
        float Amp();
        void SetOffset(float offset);   //Offset
        float Offset();
        void SetSFreq(float sf);        //Sample frequency
        float SFreq();
        virtual float Refresh();

    };

};

#endif