/*
File Name: RectangleProperties.cpp
Developer/Programmer: Charles Duncan
Date: 11/29/25
Requirements:
This program prompts the user to enter the length and width of a rectangle, validates the input,
calculates the perimeter and area, and displays the results. The program uses modular functions
(getLength_Width, calcPerimeter, calcArea, displayProperties, and main) and continues processing
rectangles until the user chooses to quit.
*/
#include <iostream>
#include <limits>
using namespace std;

//------------------------------------------------------------
// Function Prototypes
void getLength_Width(double &length, double &width);
// Prompts user for length and width, validates input (>0), 
// and returns values by reference.

double calcPerimeter(double length, double width);
// Takes validated length and width, calculates perimeter, 
// and returns the result.

double calcArea(double length, double width);
// Takes validated length and width, calculates area, 
// and returns the result.

void displayProperties(double perimeter, double area);
// Displays perimeter and area to the monitor. No return value.
//------------------------------------------------------------

void getLength_Width(double &length, double &width) {
    do {
        cout << "Enter the length of the rectangle (>0): ";
        if (!(cin >> length)) {
            cout << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            length = -1; // force repeat
            continue;
        }
        if (length <= 0) {
            cout << "Invalid input. Length must be greater than 0.\n";
        }
    } while (length <= 0);

    do {
        cout << "Enter the width of the rectangle (>0): ";
        if (!(cin >> width)) {
            cout << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            width = -1; // force repeat
            continue;
        }
        if (width <= 0) {
            cout << "Invalid input. Width must be greater than 0.\n";
        }
    } while (width <= 0);
}

double calcPerimeter(double length, double width) {
    return 2 * (length + width);
}

double calcArea(double length, double width) {
    return length * width;
}

void displayProperties(double perimeter, double area) {
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
}

int main() {
    double length, width;
    char choice;

    do {
        // Step 1: Get validated input
        getLength_Width(length, width);

        // Step 2: Calculate perimeter and area
        double perimeter = calcPerimeter(length, width);
        double area = calcArea(length, width);

        // Step 3: Display results
        displayProperties(perimeter, area);

        // Step 4: Ask user if they want to continue
        cout << "Do you want to process another rectangle? (Y/N): ";
        cin >> choice;
        // consume leftover input to avoid looping issues on bad input
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == 'Y' || choice == 'y');

    cout << "Program terminated. Goodbye!\n";
    return 0;
}
