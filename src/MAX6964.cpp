#include "MAX6964.h"

#include <Arduino.h>
#include <TwoWireDevice.h>

bool MAX6964::begin() {
  static bool init = TwoWireDevice::begin();

  // Test read
  read8();

  return (init);
}

void MAX6964::configure() {
  writereg8(MAX6964_CONFIGURATION_REG, 0b00110101);
  writereg16(MAX6964_PHASE0_O7_O0_REG, 0xFFFF);
  writereg16(MAX6964_PHASE1_O7_O0_REG, 0xFFFF);
}

void MAX6964::setPins() {
  writereg16(MAX6964_PHASE0_O7_O0_REG, 0xFFFF);
  uint8_t val = readreg8(MAX6964_CONFIGURATION_REG);
  val |= 0b00010000;
  writereg8(MAX6964_CONFIGURATION_REG, val);
}

void MAX6964::setPins(const uint16_t pins) {
  writereg16(MAX6964_PHASE0_O7_O0_REG, ~pins);
}

void MAX6964::setPin(const uint8_t nr) {
  if (nr < 16) {
    uint16_t val = readreg16(MAX6964_PHASE0_O7_O0_REG);
    val |= (1UL << nr);

    writereg16(MAX6964_PHASE0_O7_O0_REG, val);
  } else if (nr == 16) {
    uint8_t val = readreg8(MAX6964_CONFIGURATION_REG);
    val |= 0b00010000;
    writereg8(MAX6964_CONFIGURATION_REG, val);
  }
}

void MAX6964::setPinsPhase1() {
  writereg16(MAX6964_PHASE1_O7_O0_REG, 0xFFFF);
}

void MAX6964::setPinsPhase1(const uint16_t pins) {
  writereg16(MAX6964_PHASE1_O7_O0_REG, ~pins);
  uint8_t val = readreg8(MAX6964_CONFIGURATION_REG);
  val |= 0b00100000;
  writereg8(MAX6964_CONFIGURATION_REG, val);
}

void MAX6964::setPinPhase1(const uint8_t nr) {
  if (nr < 16) {
    uint16_t val = readreg16(MAX6964_PHASE1_O7_O0_REG);
    val |= (1UL << nr);

    writereg16(MAX6964_PHASE1_O7_O0_REG, val);
  } else if (nr == 16) {
    uint8_t val = readreg8(MAX6964_CONFIGURATION_REG);
    val |= 0b00100000;
    writereg8(MAX6964_CONFIGURATION_REG, val);
  }
}

void MAX6964::resetPins() {
  writereg16(MAX6964_PHASE0_O7_O0_REG, 0x0);
  uint8_t val = readreg8(MAX6964_CONFIGURATION_REG);
  val |= 0b00010000;
  writereg8(MAX6964_CONFIGURATION_REG, val);
}

void MAX6964::resetPin(const uint8_t nr) {
  if (nr < 16) {
    uint16_t val = readreg16(MAX6964_PHASE0_O7_O0_REG);
    val &= ~(1UL << nr);

    writereg16(MAX6964_PHASE0_O7_O0_REG, val);
  } else if (nr == 16) {
    uint8_t val = readreg8(MAX6964_CONFIGURATION_REG);
    val &= ~(0b00010000);
    writereg8(MAX6964_CONFIGURATION_REG, val);
  }
}

void MAX6964::resetPinsPhase1() {
  writereg16(MAX6964_PHASE1_O7_O0_REG, 0x0);
  uint8_t val = readreg8(MAX6964_CONFIGURATION_REG);
  val |= 0b00100000;
  writereg8(MAX6964_CONFIGURATION_REG, val);
}

void MAX6964::resetPinPhase1(const uint8_t nr) {
  if (nr < 16) {
    uint16_t val = readreg16(MAX6964_PHASE1_O7_O0_REG);
    val &= ~(1UL << nr);

    writereg16(MAX6964_PHASE1_O7_O0_REG, val);
  } else if (nr == 16) {
    uint8_t val = readreg8(MAX6964_CONFIGURATION_REG);
    val &= ~(0b00100000);
    writereg8(MAX6964_CONFIGURATION_REG, val);
  }
}

void MAX6964::setIntensity(const uint8_t intensity) {
  writereg8(MAX6964_MASTER_O16_INTENSITY_REG, intensity);
}