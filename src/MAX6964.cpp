#include <Arduino.h>
#include <TwoWireDevice.h>

#include "MAX6964.h"

bool MAX6964::begin() {
    static bool init = TwoWireDevice::begin();

    // Test read
    read8();

    return (init);
}

void MAX6964::configure() {
    writereg8(MAX6964_CONFIGURATION_REG, 0b0000000);
}

void MAX6964::setPin(const uint8_t nr) {
    uint16_t val = readreg16(MAX6964_PHASE0_O7_O0_REG);
    val |= (1<<nr);

    writereg16(MAX6964_PHASE0_O7_O0_REG, val);
}

void MAX6964::resetPin(const uint8_t nr) {
    uint16_t val = readreg16(MAX6964_PHASE0_O7_O0_REG);
    val &= ~(1<<nr);

    writereg16(MAX6964_PHASE0_O7_O0_REG, val);
}

void MAX6964::setIntensity(const uint8_t intensity) {
    writereg8(MAX6964_MASTER_O16_INTENSITY_REG, intensity);
}