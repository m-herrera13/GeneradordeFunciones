#ifndef DAC_H
#define DAC_H

  #include <Wire.h>
  #include <stdint.h>

  namespace Function_Gen {
    class DAC {
    private:
      uint8_t Addr;

      static constexpr uint8_t DefaultAddress = 0b01100000;

      enum class Commands : uint8_t {
        FastMode = 0b00,
        WriteDAC = 0b10,
        WriteAll = 0b11,
      };

      enum class Modes : uint8_t {
        Normal = 0b00,
        R1K = 0b01,
        R100K = 0b10,
        R500K = 0b11,
      };

    public:
      DAC(uint8_t Address = DefaultAddress) : Addr(Address) {}

      void SetAddress(uint8_t Address);
      void SetAddress(bool A2, bool A1, bool A0);

      void Write(uint16_t x, Commands CM = Commands::FastMode, Modes MD = Modes::Normal);
    };

  }

#endif