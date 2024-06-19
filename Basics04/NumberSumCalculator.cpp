
// NumberSumCalculator.cpp

#include <iostream>
#include <limits>

using namespace std;

// Function to clear the input buffer
void clearInputBuffer()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    cout << "Number Sum Calculator. Enter 0 to exit." << endl;

    int number;
    int totalSum = 0;

    cout << "Enter a number: ";
    cin >> number;

    while (number != 0) {
        cout << "Entered number: " << number << endl;
        totalSum += number;
        cout << "Sum of numbers entered so far: " << totalSum << endl;

        cout << "Enter another number (or 0 to exit): ";
        cin >> number;
    }

    clearInputBuffer();  // Clears the input buffer

    cout << "The sum of all entered numbers is: " << totalSum << endl;

	return 0;
}


