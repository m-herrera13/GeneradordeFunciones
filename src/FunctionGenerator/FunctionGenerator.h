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
        float _Oversampling;

    protected:
        static constexpr uint16_t LUT_size = 128;

        float _Acc;
        float _LUT[LUT_size];      

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
        float Refresh();
        virtual void LookUpTable() = 0;

    };

    class Sine: public FunctionGenerator{
    public:
        Sine();
        void LookUpTable() override;
    };

    class Square: public FunctionGenerator{
    public:
        Square();
        void LookUpTable() override;
    };

    class Triangle: public FunctionGenerator{
    public:
        Triangle();
        void LookUpTable() override;
    };

    class Saw: public FunctionGenerator{
    public:
        Saw();
        void LookUpTable() override;
    };

};

#endif