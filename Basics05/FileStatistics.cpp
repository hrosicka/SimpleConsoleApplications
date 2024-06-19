// FileStatistics.cpp

#include <iostream>     // This line includes the iostream library, which allows us to get input from the user and display output on the console.
#include <fstream>      // This line includes the fstream library, which allows us to work with files (reading and writing).
#include <vector>       // This line includes the vector library, which allows us to store a collection of numbers in a resizable array.
#include <stdexcept>    // This line includes the stdexcept library, which allows us to handle runtime errors (exceptions).

using namespace std;    // This line tells the compiler to use the standard namespace (std) for all the functions and objects we'll use in the code.

// Function to get the filename from the user
string getFilename()
{
    // This function prompts the user to enter the name of the file they want to read from.
    string filename;
    cout << "Enter the name of the file you want to read from: ";
    getline(cin, filename);
    return filename;
}

// Function to open the file and handle errors
ifstream openFile(const string& filename)
{
    // This function attempts to open the file specified by the filename.
    // If the file is opened successfully, an ifstream object representing the open file is returned.
    // If there's an error opening the file, a runtime_error exception is thrown with an informative message.
    ifstream infile(filename);
    if (!infile.is_open())
    {
        throw runtime_error("Failed to open file: " + filename);
    }
    return infile;
}

// Function to read numbers from the file and store them in a vector
vector<double> readNumbers(ifstream& infile)
{
    // This function reads numbers from the opened file (represented by the ifstream object)
    // and stores them in a vector (a collection of numbers).
    // The function loops through the file until there are no more numbers to read.
    vector<double> numbers;
    double number;
    while (infile >> number)
    {
        numbers.push_back(number);
    }
    return numbers;
}

// Function to calculate statistics from a vector of numbers
tuple<size_t, double, double> calculateStatistics(const vector<double>& numbers)
{
    // This function takes a vector of numbers as input and calculates three statistics:
    //  - count_number: the total number of elements (numbers) in the vector
    //  - sum_number: the sum of all the numbers in the vector
    //  - average: the average value of all the numbers (sum divided by count)
    // The function returns a tuple containing these three values.
    size_t count_number = numbers.size();
    double sum_number = 0.0;
    for (double num : numbers)
    {
        sum_number += num;
    }
    double average = count_number > 0 ? sum_number / count_number : 0.0;
    return make_tuple(count_number, sum_number, average);
}

// Function to print statistics to the console
void printStatistics(const string& filename, size_t count_number, double sum_number, double average)
{
    cout << "File: " << filename << endl;
    cout << "Total count of numbers: " << count_number << endl;
    cout << "Their sum is: " << sum_number << endl;
    cout << "Their average is: " << average << endl;
}

// Function to write statistics to an output file (optional)
void writeStatisticsToFile(const string& filename, size_t count_number, double sum_number, double average)
{
    // This function attempts to write the calculated statistics to a file named "output.txt".
    // If the file is opened successfully, the statistics are written to the file.
    // If there's an error opening the file, a warning message is printed to the console.
    ofstream outfile("output.txt");
    if (outfile.is_open())
    {
        outfile << "File: " << filename << endl;
        outfile << "Total count of numbers: " << count_number << endl;
        outfile << "Their sum is: " << sum_number << endl;
        outfile << "Their average is: " << average << endl;
        outfile.close();
    } 
    else 
    {
        cerr << "Warning: Could not open output file 'output.txt'." << endl;
    }
}


int main()

{
    try 
    {
        string filename = getFilename();
        ifstream infile = openFile(filename);
        vector<double> numbers = readNumbers(infile);

        tuple<size_t, double, double> stats = calculateStatistics(numbers);
        size_t count_number = get<0>(stats);
        double sum_number = get<1>(stats);
        double average = get<2>(stats);

        printStatistics(filename, count_number, sum_number, average);
        writeStatisticsToFile(filename, count_number, sum_number, average);

        infile.close();
    } 

    catch (const runtime_error& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

  return 0;
}