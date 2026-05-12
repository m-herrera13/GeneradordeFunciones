#ifndef FUNCTION_GENERATOR_H
#define FUNCTION_GENERATOR_H

#include <stdint.h>
#include <cmath>
#include "../DAC/DAC.h"
#include "../LUT/LUT.h"

namespace Function_Gen{
    
    class FunctionGenerator{
    private:
        float _TFreq;
        float _Amp;
        float _Offset;
        float _SFreq;
        float _Oversampling;

        DAC* OutputDAC;
        float _Acc;

        float* pLUT;
        LUT* LUTfiller;

        enum class Waveform {
            Sine,
            Square,
            Triangle,
            Saw,
            ISaw,
            DC
        };

    public:
        FunctionGenerator();
        FunctionGenerator(float tf, float amp, float offset, float os=4.0);

        void SetTFreq(float tf);        //Target frequency
        float TFreq() const;
        void SetAmp(float amp);         //Amplitude
        float Amp() const;
        void SetOffset(float offset);   //Offset
        float Offset() const;
        void SetSFreq(float os);        //Oversampling for Sample frequency
        float SFreq() const;

        void AttachDAC(DAC* DACx);
        float Refresh();

        void AttachLUT(LUT* mainLUT);
        void SetWaveform(Waveform W);

    };
};

#endif