#ifndef _CONVERSION_H
#define _CONVERSION_H
#define _USE_MATH_DEFINES
#include <math.h>

class Converter{
    public:
        double degrees_to_radians(double degrees);
        double radians_to_degrees(double radians);
        double fahrenheit_to_celsius(double temp);
        double celsius_to_fahrenheit(double temp);
        double celsius_to_kelvin(double temp);
        double kelvin_to_celsius(double temp);
        double fahrenheit_to_kelvin(double temp);
        double kelvin_to_fahrenheit(double temp);
};
#endif
