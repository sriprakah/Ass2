#include "BMP280.h"
#include <iostream>
#include <unistd.h> // For usleep (microseconds)

// Constructor
BMP280::BMP280() : t_fine(0) {}

// Destructor
BMP280::~BMP280() {}

// Initialize the BMP280 sensor
bool BMP280::initialize() {
    if (!configureSPI()) {
        return false;
    }

    // Check the chip ID
    uint8_t chip_id = readRegister(0xD0);
    if (chip_id != 0x58) { // BMP280 chip ID is 0x58
        std::cerr << "BMP280 not detected. Chip ID: " << static_cast<int>(chip_id) << std::endl;
        return false;
    }

    // Reset the sensor
    writeRegister(0xE0, 0xB6); // Soft reset command
    usleep(2000);              // Wait 2ms after reset

    // Read compensation parameters
    if (!readCompensationParameters()) {
        return false;
    }

    // Configure the sensor (normal mode, oversampling settings)
    writeRegister(0xF4, 0x27); // Normal mode, temperature and pressure oversampling x1
    writeRegister(0xF5, 0xA
