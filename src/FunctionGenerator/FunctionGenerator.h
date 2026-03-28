#ifndef FUNCTION_GENERATOR_H
#define FUNCTION_GENERATOR_H

#include <stdint.h>
#include <cmath>

namespace FUNCTION_GENERATOR{
        
    class FunctionGenerator{
    private:
        float _TFreq;
        float _Amp;
        float _Offset;
        float _SFreq;
        float _DutyCycle;

    protected:
        float _Acc;
        float _LUT[512];      

    public:
        FunctionGenerator();
        FunctionGenerator(float tf, float amp, float offset, float duty, float sfreq);
        void SetTFreq(float tf);        //Target frequency
        float TFreq();
        void SetAmp(float amp);         //Amplitude
        float Amp();
        void SetOffset(float offset);   //Offset
        float Offset();
        void SetSFreq(float sf);        //Sample frequency
        float SFreq();
        void SetDutyCycle(float duty);        //Sample frequency
        float DutyCycle();
        virtual float Refresh();
        virtual void LookUpTable();

    };

    class Sine: public FunctionGenerator{
    public:
        float Refresh() override;
        void LookUpTable() override;
    };

    class Square: public FunctionGenerator{
    public:
        float Refresh() override;
        void LookUpTable() override;
    };

    class Triangle: public FunctionGenerator{
    public:
        float Refresh() override;
        void LookUpTable() override;
    };

    class Saw: public FunctionGenerator{
    public:
        float Refresh() override;
        void LookUpTable() override;
    };

};

#endif