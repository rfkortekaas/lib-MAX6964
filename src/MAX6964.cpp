#include <Arduino.h>
#include <Wire.h>

#include "MAX6964.h"

bool MAX6964::begin() {
    TwoWireDevice::begin();

    // Test read
    read8();

    return (_wire.lastError == 0);
}

bool MAX6964::setPin(const uint8_t nr) {
    uint8_t val = readreg16(MAX6964_PHASE0_O15_O8_REG);
    val |= (1<<nr);

    writereg16(MAX6964_PHASE0_O15_O8_REG, val);
}

bool MAX6964::resetPin(const uint8_t nr) {
    uint8_t val = readreg16(MAX6964_PHASE0_O15_O8_REG);
    val &= ~(1<<nr);

    writereg16(MAX6964_PHASE0_O15_O8_REG, val);
}