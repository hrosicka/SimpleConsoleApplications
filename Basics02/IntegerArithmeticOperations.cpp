
//IntegerArithmeticOperations.cpp

// Include the necessary header file for input/output operations
#include <iostream>

using namespace std;

// Class for arithmetic operations on integers
class IntegerCalculator 

{
    private:
        // Private member variables to store the two integers
        const int numberA;
        const int numberB;

    public:
        // Constructor to initialize the class with two integers
        IntegerCalculator(const int numberA, const int numberB) : numberA(numberA), numberB(numberB) {}  // Inicializační seznam v konstruktoru

        // Method to add the two integers
        int add() const
        {
            return numberA + numberB;
        }

        // Method to subtract the second integer from the first integer
        int subtract() const
        {
            return numberA - numberB;
        }

        // Method to multiply the two integers
        int multiply() const
        {
            return numberA * numberB;
        }

        // Method to divide the first integer by the second integer
        int divide() const
        {
            if (numberB == 0) 
            {
                throw invalid_argument("Division by zero");
            }
            return numberA / numberB;
        }

        // Method to find the remainder after dividing the first integer by the second integer
        int remainder() const
        {
            return numberA % numberB;
        }
};


    int main ()

    {
        // Declare and initialize two integer variables to get input from the user
        int numberA;
        int numberB;

        cout << "Enter the first integer: ";
        cin >> numberA;
        cout << "Enter the second integer: ";
        cin >> numberB;

        // Create an instance of the IntegerCalculator class using the entered integers
        IntegerCalculator arithmetic(numberA, numberB);

        // Display the results of the arithmetic operations
        std::cout << "\nArithmetic operations results:\n";
        std::cout << numberA << " + " << numberB << " = " << arithmetic.add() << endl;
        std::cout << numberA << " - " << numberB << " = " << arithmetic.subtract() << endl;
        std::cout << numberA << " * " << numberB << " = " << arithmetic.multiply() << endl;
        std::cout << numberA << " / " << numberB << " = " << arithmetic.divide() << std::endl;
        std::cout << "Remainder after division: " << numberA << " % " << numberB << " = " << arithmetic.remainder() << endl;

        return 0;
}
