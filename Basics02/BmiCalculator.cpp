// BmiCalculator.cpp

#include <iostream>
#include <iomanip>

using namespace std;

class BmiCalculator 
{
    public:
        // Function to calculate and display BMI
        void calculateBmi() 
        {
            int heightInCentimeters, weightInKilograms;

            cout << "Enter your height in centimeters: ";
            cin >> heightInCentimeters;

            cout << "Enter your weight in kilograms: ";
            cin >> weightInKilograms;

            float heightInMeters = static_cast<float>(heightInCentimeters) / 100;
            float bmi = weightInKilograms / (heightInMeters * heightInMeters);

            // Round output to 3 decimal places
            cout << fixed << setprecision(3) << "Your BMI is: " << bmi << endl;
        }
};

int main() 
{
  BmiCalculator bmiCalculator;
  bmiCalculator.calculateBmi();

  return 0;
}
