#include "convert.h"


double Converter::degrees_to_radians(double degrees)
{
    return (degrees * M_PI / 180);
}

double Converter::radians_to_degrees(double radians)
{
    return (radians * 180 / M_PI);
}

double Converter::fahrenheit_to_celsius(double temp)
{
    return (temp - 32) * (5.0/9.0);
}

double Converter::celsius_to_fahrenheit(double temp)
{
    return (temp * (9.0/5.0)) + 32;
}

double Converter::celsius_to_kelvin(double temp)
{
    return (temp + 273.15);
}

double Converter::kelvin_to_celsius(double temp)
{
    return (temp - 273.15);
}

double Converter::fahrenheit_to_kelvin(double temp)
{
    return celsius_to_kelvin(fahrenheit_to_celsius(temp));
}

double Converter::kelvin_to_fahrenheit(double temp)
{
    return celsius_to_fahrenheit(kelvin_to_celsius(temp));
}

