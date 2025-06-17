#include <iostream>
#include <limits> // For input validation
#include <iomanip> // For std::fixed and std::setprecision

// This program calculates the Body Mass Index (BMI) from user input.

int main()
{
    int height_centimeters = 0;
    int weight_kg = 0;

    // Prompt for height and validate input
    std::cout << "Enter your height in centimeters: ";
    while (!(std::cin >> height_centimeters) || height_centimeters <= 0) {
        std::cout << "Invalid input. Please enter a positive integer for height: ";
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    // Prompt for weight and validate input
    std::cout << "Enter your weight in kilograms: ";
    while (!(std::cin >> weight_kg) || weight_kg <= 0) {
        std::cout << "Invalid input. Please enter a positive integer for weight: ";
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    // Convert height from centimeters to meters
    float height_meters = static_cast<float>(height_centimeters) / 100.0f;

    // Calculate BMI
    float bmi = static_cast<float>(weight_kg) / (height_meters * height_meters);

    // Output result with two decimal places
    std::cout << "Your BMI is: " << std::fixed << std::setprecision(2) << bmi << std::endl;

    // Provide basic BMI category feedback
    if (bmi < 18.5f) {
        std::cout << "Category: Underweight" << std::endl;
    } else if (bmi < 25.0f) {
        std::cout << "Category: Normal weight" << std::endl;
    } else if (bmi < 30.0f) {
        std::cout << "Category: Overweight" << std::endl;
    } else {
        std::cout << "Category: Obesity" << std::endl;
    }

    // Wait for user input before closing (optional)
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cin.get();

    return 0;
}