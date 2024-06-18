
// RangeSum.cpp

#include <iostream>

using namespace std; // Use the standard namespace to avoid typing  every time

int main() 

{
    cout << "This program calculates the sum of all integers within a specified range (inclusive)." << endl;

    int lowerBound, upperBound;

    cout << "Enter the lower bound: ";
    cin >> lowerBound;

    cout << "Enter the upper bound: ";
    cin >> upperBound;

    long long sum = 0; // Use long long for larger ranges

    if (lowerBound <= upperBound)
    {
        for (int i = lowerBound; i <= upperBound; ++i)
        {
        sum += i;
        }
    } 
    else 
    {
        for (int i = upperBound; i <= lowerBound; ++i)
        {
        sum += i;
        }
    }

    cout << "The sum of all integers in the range is: " << sum << endl;

    cin.ignore(); // Ignore any remaining newline characters
    cin.get(); // Wait for user input to continue

    return 0;
}

