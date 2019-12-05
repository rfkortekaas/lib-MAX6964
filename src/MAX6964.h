#ifndef __MAX6964_h
#define __MAX6964_h

#include <Arduino.h>
#include <TwoWireDevice.h>

#define MAX6964_ADDRESS_DEFAULT     (0x20)

#define MAX6964_PHASE0_O7_O0_REG    (0x02)
#define MAX6964_PHASE0_O15_O8_REG   (0x03)

#define MAX6964_PHASE1_O7_O0_REG    (0x0A)
#define MAX6964_PHASE1_O15_O8_REG   (0x0B)

class MAX6964: public TwoWireDevice {
    public:
        MAX6964(TwoWire& wire, const uint8_t addr = MAX6964_ADDRESS_DEFAULT) : TwoWireDevice(wire, addr) {};
        MAX6964(const uint8_t addr = MAX6964_ADDRESS_DEFAULT) : TwoWireDevice(addr) {};

        bool begin();
        void setPin(const uint8_t nr);
        void resetPin(const uint8_t nr);
    
    protected:

    private:
        MAX6964(const MAX6964&);
         MAX6964& operator=(const MAX6964&);
};

#endif // __MAX6964_h