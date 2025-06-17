#include <iostream>
#include <limits>   // For input validation
#include <iomanip>  // For std::fixed and std::setprecision

// This program calculates the Body Mass Index (BMI) based on user input.

/**
 * Calculates BMI given height in centimeters and weight in kilograms.
 * @param height_cm Height in centimeters
 * @param weight_kg Weight in kilograms
 * @return Calculated BMI
 */
float calculate_bmi(int height_cm, int weight_kg) {
    float height_m = static_cast<float>(height_cm) / 100.0f;
    return weight_kg / (height_m * height_m);
}

int main()
{
    int height_centimeters = 0;
    int weight_kg = 0;

    // Prompt user for height and validate the input (must be a positive integer)
    std::cout << "Enter your height in centimeters: ";
    while (!(std::cin >> height_centimeters) || height_centimeters <= 0) {
        std::cout << "Invalid input. Please enter a positive integer for height: ";
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    // Prompt user for weight and validate the input (must be a positive integer)
    std::cout << "Enter your weight in kilograms: ";
    while (!(std::cin >> weight_kg) || weight_kg <= 0) {
        std::cout << "Invalid input. Please enter a positive integer for weight: ";
        std::cin.clear(); // Clear error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    // Calculate BMI using the inputted values
    float bmi = calculate_bmi(height_centimeters, weight_kg);

    // Output the result, formatted to two decimal places
    std::cout << "Your BMI is: " << std::fixed << std::setprecision(2) << bmi << std::endl;

    // Provide basic feedback about the BMI category
    if (bmi < 18.5f) {
        std::cout << "Category: Underweight" << std::endl;
    } else if (bmi < 25.0f) {
        std::cout << "Category: Normal weight" << std::endl;
    } else if (bmi < 30.0f) {
        std::cout << "Category: Overweight" << std::endl;
    } else {
        std::cout << "Category: Obesity" << std::endl;
    }

    // Wait for user input before closing (optional for some environments)
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    std::cin.get();

    return 0;
}