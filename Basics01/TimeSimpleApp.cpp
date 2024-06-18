// TimeSimpleApp.cpp - This is the filename of the C++ program

#include <iostream> // This line includes the iostream library, which provides input and output functionalities for the program.
#include <iomanip>  // This line includes the iomanip library, which provides additional formatting options for output.

using namespace std; // This line tells the compiler to use the "std" namespace, which contains standard objects like cout, cin, and endl.

class Time 
{   
    // This defines a class called "Time" that represents a time of day.
    private:
        int hour;  // This variable stores the hour value (0-23).
        int minute; // This variable stores the minute value (0-59).

public:
    // Constructor to initialize hour and minute to 0
    Time() 
    {
        hour = 0;
        minute = 0;
    }
    
    // Function to set the time (with basic input validation)
    int set_time() 
    {
        cout << "Enter hour and minute separated by a space (e.g., 11 45): "; // Prompts the user to enter the time in a specific format.
        cin >> hour >> minute;                                                // Reads the hour and minute values from the user input.

        // Basic validation (can be improved)
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59) 
        {
            cout << "Invalid time! Please enter hour in range 0-23 and minute in range 0-59." << endl; // Displays an error message if the entered time is invalid.
            return 1; // Returns 1 to indicate an error during time setting.
        }

        return 0; // Returns 0 to indicate successful time setting.
    }

    // Function to display the time
    void display_time() const 
    {
        cout << "Time: " << setw(2) << setfill('0') << hour << ":"  // Formats the output to display "Time: " followed by the hour with leading zeros (if needed).
            << setw(2) << setfill('0') << minute << endl;          // Formats the output to display the minute with leading zeros (if needed) and a newline character.
    }
};

int main() {
    Time time_object; // Creates an object of type "Time" called "time_object".

    int set_time_result = time_object.set_time(); // Calls the set_time() function of the time_object and stores the return value (0 for success, 1 for error).

    if (set_time_result != 0) {
        // Handle error if set_time returned a non-zero value (indicating error)
        cout << "Error: Invalid time entered." << endl; // Displays an error message if time setting failed.
        return 1;                                       // Returns 1 from the main function to signal an error.
    }

    time_object.display_time(); // Calls the display_time() function of the time_object to display the set time.

    return 0; // Returns 0 from the main function to indicate successful program execution.
}