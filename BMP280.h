#ifndef BMP280_H
#define BMP280_H

#include <cstdint>

class BMP280 {
public:
    BMP280();
    ~BMP280();

    // Initialize the BMP280 sensor
    bool initialize();

    // Read temperature in Celsius
    float readTemperature();

    // Read pressure in hPa
    float readPressure();

private:
    // Write a register value via SPI
    bool writeRegister(uint8_t reg, uint8_t value);

    // Read a register value via SPI
    uint8_t readRegister(uint8_t reg);

    // Read multiple bytes starting from a register
    bool readRegisters(uint8_t reg, uint8_t* buffer, uint8_t length);

    // Configure SPI settings
    bool configureSPI();

    // Compensation parameters for temperature and pressure
    int32_t t_fine;
    uint16_t dig_T1;
    int16_t dig_T2, dig_T3;
    uint16_t dig_P1;
    int16_t dig_P2, dig_P3, dig_P4, dig_P5, dig_P6, dig_P7, dig_P8, dig_P9;

    // Parse compensation parameters from the sensor
    bool readCompensationParameters();
};

#endif // BMP280_H
