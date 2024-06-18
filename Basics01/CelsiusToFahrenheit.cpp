
// CelsiusToFahrenheit.cpp

#include <iostream>

class TemperatureConverter
{
    public:
        // Function to convert Celsius to Fahrenheit.
        // Takes a float representing the temperature in Celsius as input.
        // Returns the converted temperature in Fahrenheit as a float.
        float celsiusToFahrenheit(float celsius) 
        {
            return 1.8f * celsius + 32.0f;
        }
};

int main() 
{
    // Create an object of the TemperatureConverter class.
    TemperatureConverter converter;
    
    // Declare a float variable to store the Celsius temperature.
    float celsius;

    // Prompt the user to enter the temperature in Celsius.
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    // Convert the Celsius temperature to Fahrenheit using the converter object.
    float fahrenheit = converter.celsiusToFahrenheit(celsius);

    // Display the converted temperature in Fahrenheit.
    std::cout << "In Fahrenheit it is: " << fahrenheit << std::endl;

    return 0;
}
