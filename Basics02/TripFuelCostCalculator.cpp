// TripFuelCostCalculator.cpp

#include <iostream>

using namespace std;

class TripFuelCalculator 
{
    private:
        float distance; // Distance traveled in kilometers
        float fuelConsumed; // Fuel consumed in liters
        float fuelEfficiency; // Fuel efficiency in liters per 100 kilometers

    public:
        // Function to get user input for distance
        void setDistance()
        {
            cout << "Enter the distance traveled in kilometers: ";
            cin >> distance;
        }

        // Function to get user input for fuel consumed
        void setFuelConsumed() 
        {
            cout << "Enter the fuel consumed in liters: ";
            cin >> fuelConsumed;
        }

        // Function to calculate and display fuel efficiency
         void calculateAndDisplayEfficiency() 
        {
            fuelEfficiency = fuelConsumed / distance * 100;
            cout << "\nYour fuel efficiency is: " << fuelEfficiency << " liters per 100 kilometers." << endl;
        }
};



int main ( )
{
    TripFuelCalculator tripCalculator;

    tripCalculator.setDistance();
    tripCalculator.setFuelConsumed();
    tripCalculator.calculateAndDisplayEfficiency();

    return 0;
}
