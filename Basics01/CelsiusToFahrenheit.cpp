
// CelsiusToFahrenheit.cpp

#include <iostream>

using namespace std;


class TemperatureConverter

{
    public:
        // Function to convert Celsius to Fahrenheit.
        // Takes a float representing the temperature in Celsius as input.
        // Returns the converted temperature in Fahrenheit as a float.
        float celsiusToFahrenheit(float celsius)
        {
            // Check if the input value is within the valid range
            if (celsius < -273.15 || celsius > 572.65) 
            {
                throw invalid_argument("Invalid Celsius temperature input. Value must be between -273.15 and 572.65 degrees Celsius.");
            }
            return 1.8f * celsius + 32.0f;
        }
};


int main() 

{
    // Create an object of the TemperatureConverter class.
    TemperatureConverter converter;
    
    // Declare a float variable to store the Celsius temperature.
    float celsius = 0.0f;

    // Prompt the user to enter the temperature in Celsius.
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // Convert the Celsius temperature to Fahrenheit using the converter object.
    float fahrenheit = converter.celsiusToFahrenheit(celsius);

    // Display the converted temperature in Fahrenheit.
    cout << "In Fahrenheit it is: " << fahrenheit << endl;

    return 0;
}
