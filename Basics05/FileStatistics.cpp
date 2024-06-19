// FileStatistics.cpp

#include <iostream>     // Program components must include the iostream header file
#include <fstream>      // Analogy for working with files, for I/O operations to/from files
#include <cstdlib>      // Support for the exit() object

using namespace std;    // The program must include the namespace

const int SIZE = 60;

int main()

{
    char filename[SIZE];

    // Object definition
    ifstream infile;                // ifstream object
    ofstream outfile;               // ofstream object

    // Assign objects to files
    cout << "Enter the name of the file you want to read from" << endl;
    cin.getline(filename, SIZE);
    infile.open(filename);          // Read from a file using infile1

    if (!infile.is_open())          // Check if the file is open
    {
        cout << "Failed to open file" << endl;
        cout << "Program will be terminated." << endl;
        exit(EXIT_FAILURE);         // Terminate the program
    }


    double number;
    double sum_number = 0.0;
    int count_number = 0;

    infile >> number;              // Read the first number
    while (infile.good())          // As long as the input is good and not EOF
    {
        ++ count_number;
        sum_number += number;
        infile >> number;
    }

    if (infile.eof())
        cout << "End of file." << endl;
    else if (infile.fail())
        cout << "Reading stopped, bad data." << endl;
    else
        cout << "Reading failed." << endl;

    if (count_number == 0)
        cout << "No data was read." << endl;

    else
    {
        cout << "Total count of numbers: " << count_number << endl;
        cout << "Their sum is: " << sum_number << endl;
        cout << "Their average is: " << sum_number/count_number << endl;
        outfile.open("output.txt");
        outfile << "Total count of numbers: " << count_number << endl;
        outfile << "Their sum is: " << sum_number << endl;
        outfile << "Their average is: " << sum_number/count_number << endl;
        outfile.close();
    }

    infile.close();

    return 0;
}