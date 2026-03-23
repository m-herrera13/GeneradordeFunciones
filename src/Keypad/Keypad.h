#ifndef SR_KEYPAD_CONTROLLER_H
#define SR_KEYPAD_CONTROLLER_H

#include <stdint.h>
#include "../SIPO/SIPO.h"
#include "../PISO/PISO.h"

namespace SR_KEYPAD{
    
    class Controller{
    public:
        enum StstusKeys : uint8_t{
            Raising = 0b00,
            Falling = 0b01,
            IdleHigh = 0b10,
            IdleLow = 0b11,
        };

    private:
        SIPO* _out_controller;
        PISO* _in_controller;

        uint8_t _prev_states[8];

        void(*_Callback)(uint8_t ID, bool State);

    public:
        Controller();
        Controller(void(&_Callback)(uint8_t ID, bool State));

        void AttachCallback(void(&_Callback)(uint8_t ID, bool State));
        void ClearCallback();

        void AttachSIPO(SIPO& SIPO_Controller);
        void DetachSIPO();
        void AttachPISO(PISO& PISO_Controller);
        void DetachPISO();

        void Scan();
    };
}

#endif