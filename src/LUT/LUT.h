#ifndef LUT_H
#define LUT_H

#include <stdint.h>
#include <math.h>

namespace Function_Gen{

    constexpr uint16_t LUT_size = 128;
        
    class LUT{
    private:
        float Sine[LUT_size];
        float Square[LUT_size];
        float Triangle[LUT_size];
        float Saw[LUT_size];
        float ISaw[LUT_size];
        float DC[LUT_size];

    public:
        LUT();
        void GenSine();
        void GenSquare();
        void GenSaw();
        void GenTriangle();
        void GenDC();
        void GenISaw();

        void FillSine(float* pLUT);
        void FillSquare(float* pLUT);
        void FillSaw(float* pLUT);
        void FillTriangle(float* pLUT);
        void FillDC(float* pLUT);
        void FillISaw(float* pLUT);
    };

    class SineLUT : public LUT{

    };
};

#endif