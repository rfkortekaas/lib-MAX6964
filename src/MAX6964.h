#ifndef __MAX6964_h
#define __MAX6964_h

#include <Arduino.h>
#include <TwoWireDevice.h>

#define MAX6964_ADDRESS_DEFAULT (0x20)

#define MAX6964_PHASE0_O7_O0_REG (0x02)
#define MAX6964_PHASE0_O15_O8_REG (0x03)
#define MAX6964_USER_RAM0_REG (0x06)
#define MAX6964_USER_RAM1_REG (0x07)
#define MAX6964_PHASE1_O7_O0_REG (0x0A)
#define MAX6964_PHASE1_O15_O8_REG (0x0B)
#define MAX6964_MASTER_O16_INTENSITY_REG (0x0E)
#define MAX6964_CONFIGURATION_REG (0x0F)
#define MAX6964_O1_O0_INTENSITY_REG (0x10)
#define MAX6964_O3_O2_INTENSITY_REG (0x11)
#define MAX6964_O5_O4_INTENSITY_REG (0x12)
#define MAX6964_O7_O6_INTENSITY_REG (0x13)
#define MAX6964_O9_O8_INTENSITY_REG (0x14)
#define MAX6964_O11_O10_INTENSITY_REG (0x15)
#define MAX6964_O13_O12_INTENSITY_REG (0x16)
#define MAX6964_O15_O14_INTENSITY_REG (0x17)

class MAX6964 : public TwoWireDevice {
 public:
  MAX6964(TwoWire& wire, const uint8_t addr = MAX6964_ADDRESS_DEFAULT) : TwoWireDevice(wire, addr){};
  MAX6964(const uint8_t addr = MAX6964_ADDRESS_DEFAULT) : TwoWireDevice(addr){};

  bool begin();
  void configure();

  void setPins();
  void setPins(const uint16_t pins);
  void setPin(const uint8_t nr);

  void setPinsPhase1();
  void setPinsPhase1(const uint16_t pins);
  void setPinPhase1(const uint8_t nr);

  void resetPins();
  void resetPin(const uint8_t nr);

  void resetPinsPhase1();
  void resetPinPhase1(const uint8_t nr);

  void setIntensity(const uint8_t intensity);

 protected:
 private:
  MAX6964(const MAX6964&);
  MAX6964& operator=(const MAX6964&);
};

#endif  // __MAX6964_h