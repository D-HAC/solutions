#include "convert.h"
#include <iostream>
#include <fstream>
#include <string>

void convertFromFile(std::string fileName, Converter convert);

int main()
{
    Converter conv;
    convertFromFile("Test.txt", conv);
    return 0;
}

void convertFromFile(std::string fileName, Converter convert)
{
    std::ifstream input;
    std::string line;
    input.open(fileName.c_str(), std::fstream::in);
    
    if(!input.is_open())
    {
        std::cout << "Error, could not open file: " << fileName << std::endl;
        return;
    }

    while (std::getline(input, line))
    {

        std::string conversionLetters;
        std::string valueToConvert;
        double value;
        conversionLetters = line.substr(line.length() - 2);
        valueToConvert = line.substr(0, line.length() - 2);
        value = std::stod(valueToConvert);

        if(conversionLetters == "rd")
        {
            std::cout << "Convert: " << value << " to: " << convert.radians_to_degrees(value) << std::endl;
        }
        else if(conversionLetters == "dr")
        {
            std::cout << "Convert: " << value << " to: " << convert.degrees_to_radians(value) << std::endl;
        }
        else if(conversionLetters == "fc")
        {
            std::cout << "Convert: " << value << " to: " << convert.fahrenheit_to_celsius(value) << std::endl;
        }
        else if(conversionLetters == "cf")
        {
            std::cout << "Convert: " << value << " to: " << convert.celsius_to_fahrenheit(value) << std::endl;
        }
        else if(conversionLetters == "fk")
        {
            std::cout << "Convert: " << value << " to: " << convert.fahrenheit_to_kelvin(value) << std::endl;
        }
        else if(conversionLetters == "kf")
        {
            std::cout << "Convert: " << value << " to: " << convert.kelvin_to_fahrenheit(value) << std::endl;
        }
        else if(conversionLetters == "ck")
        {
            std::cout << "Convert: " << value << " to: " << convert.celsius_to_kelvin(value) << std::endl;
        }
        else if(conversionLetters == "kc")
        {
            std::cout << "Convert: " << value << " to: " << convert.kelvin_to_celsius(value) << std::endl;
        }
        else
        {
            std::cout << "Can not convert with the letters: " << conversionLetters << std::endl;
        }
    
    }

    input.close();
}
