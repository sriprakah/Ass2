#include "BMP280.h"
#include <iostream>

int main() {
    BMP280 sensor;

    // Initialize the BMP280 sensor
    if (!sensor.initialize()) {
        std::cerr << "Failed to initialize BMP280 sensor!" << std::endl;
        return -1;
    }

    // Read temperature and pressure data
    float temperature = sensor.readTemperature();
    float pressure = sensor.readPressure();

    if (temperature == -1 || pressure == -1) {
        std::cerr << "Failed to read data from the BMP280 sensor!" << std::endl;
        return -1;
    }

    std::cout << "Temperature: " << temperature << " °C" << std::endl;
    std::cout << "Pressure: " << pressure << " hPa" << std::endl;

    return 0;
}
