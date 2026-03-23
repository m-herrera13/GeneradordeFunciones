#ifndef SR_KEYPAD_PISO_H
#define SR_KEYPAD_PISO_H

#include <stdint.h>

namespace SR_KEYPAD{
        
    class PISO{
    private:
        bool(*_DataController)(void);       // Data In
        void(*_ClockController)(void);      // Clock
        void(*_SLController)(void);         // Shift Load

    public:
        PISO();
            
        PISO(bool(&DataController)(void),
            void(&ClockController)(void),
            void(&SLController)(void));

        uint8_t Read(uint8_t bits);
        uint8_t* ReadArray(uint8_t bytes, uint8_t* buffer);
    };

};

#endif