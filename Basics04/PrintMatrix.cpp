

#include <iostream> // Include the iostream header file for input and output operations

using namespace std; // Use the standard namespace to avoid typing std:: every time


int main()
{
    // Define a 2D array named 'matrix' with 4 rows and 3 columns
    // Each row is initialized with a list of integers
    int matrix [4][3] =
    {
        {1,2,3},
        {4,5,6},
        {7,8,9},
        {1,2,3}
    };

    // Iterate through each row of the 'matrix' array
    // 'row' represents each row in the matrix
    for (auto& row : matrix) 
    {
        // 'element' represents each element in the current row
        for (auto& element : row) 
        {
            // Print the current element with a tab ('\t') for separation
            cout << element << "\t";
        }
        // After printing each row, move to the next line using endl
        cout << endl;
    }

	return 0;
}


