// FileStatistics.cpp

#include <iostream>     // Program components must include the iostream header file
#include <fstream>      // Analogy for working with files, for I/O operations to/from files
#include <vector>
#include <stdexcept>

using namespace std;    // The program must include the namespace

// Function to get the filename from the user
string getFilename()
{
    string filename;
    cout << "Enter the name of the file you want to read from: ";
    getline(cin, filename);
    return filename;
}

// Function to open the file and handle errors
ifstream openFile(const string& filename)
{
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
    vector<double> numbers;
    double number;
    while (infile >> number)
    {
        numbers.push_back(number);
    }
    return numbers;
}

int main()

{
    try 
    {
        string filename = getFilename();
        ifstream infile = openFile(filename);
        vector<double> numbers = readNumbers(infile);

        // Calculate statistics
        size_t count_number = numbers.size();
        double sum_number = 0.0;

        for (double num : numbers)
        {
            sum_number += num;
        }

        double average = count_number > 0 ? sum_number / count_number : 0.0;

        // Print statistics to the console
        cout << "File: " << filename << endl;
        cout << "Total count of numbers: " << count_number << endl;
        cout << "Their sum is: " << sum_number << endl;
        cout << "Their average is: " << average << endl;

        // Write statistics to output file (optional)
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

        infile.close();

    } 
    catch (const runtime_error& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}