#ifndef DAC_H
#define DAC_H

  #include <Arduino.h>
  
  #define SDA_PORT PORTB
  #define SDA_DDR  DDRB
  #define SDA_PINREG PINB
  #define SDA_PIN PB0

  #define SCL_PORT PORTB
  #define SCL_DDR  DDRB
  #define SCL_PINREG PINB
  #define SCL_PIN PB1

  namespace DAC {
    class i2c_CTRL{
    private:
      inline void SCL_HIGH(){
        SCL_DDR &= ~(1 << SCL_PIN);
      }

      inline void SCL_LOW(){
          SCL_DDR |= (1 << SCL_PIN);
          SCL_PORT &= ~(1 << SCL_PIN);
      }

      inline void SDA_HIGH(){
        SDA_DDR &= ~(1 << SDA_PIN);
      }

      inline void SDA_LOW(){
        SDA_DDR |= (1 << SDA_PIN);
        SDA_PORT &= ~(1 << SDA_PIN);
      }

      inline void I2C_DELAY(){
        __builtin_avr_delay_cycles(80);
      }

    public:
      i2c_CTRL(){}

      void begin();

      inline void Start(){
        SDA_HIGH();
        SCL_HIGH();
        I2C_DELAY();

        SDA_LOW();
        I2C_DELAY();

        SCL_LOW();
        I2C_DELAY();
      }

      inline void Stop(){
        SDA_LOW();
        I2C_DELAY();

        SCL_HIGH();
        I2C_DELAY();

        SDA_HIGH();
        I2C_DELAY();

      }

      inline bool beginTransmission(uint8_t address){
        Start();

        return write(address << 1);
      }

      inline bool write(uint8_t data){
        for(uint8_t i = 0; i < 8; i++){
          if((data >> (7 - i)) & 0x01) SDA_HIGH();
          else SDA_LOW();

          I2C_DELAY();

          SCL_HIGH();
          I2C_DELAY();

          SCL_LOW();
          I2C_DELAY();
        }

        SDA_HIGH();
        I2C_DELAY();

        SCL_HIGH();
        I2C_DELAY();

        bool ack = !(SDA_PINREG & (1 << SDA_PIN));

        SCL_LOW();
        I2C_DELAY();

        SDA_HIGH();
        I2C_DELAY();

        return ack;
      }

      void endTransmission();

    };

    class MCP4725 {
    private:
      uint8_t Addr;
      i2c_CTRL* i2c;
      const uint8_t Msg1 = 0b0000;

    public:
      MCP4725(i2c_CTRL* controller, uint8_t address);

      void setV(uint16_t x);
    };

  }

#endif