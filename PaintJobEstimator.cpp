/*
File Name: PaintJobEstimator.cpp
Developer/Programmer: Charles Duncan
Date: 11/29/25
Requirements:
This program estimates the total cost of a paint job based on user input. It calculates the
number of gallons of paint needed, labor hours required, cost of paint, labor charges, and
total cost. The program uses modular functions, validates input, applies constants for labor
and material rates, and accumulates totals across multiple rooms.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//------------------------------------------------------------
// Global Constants
const double SQFT_PER_GALLON = 110.0;
const double HOURS_PER_GALLON = 8.0;
const double LABOR_RATE = 25.0;

//------------------------------------------------------------
// Function Prototypes
int getRooms();
// Prompts user for number of rooms (> 0). Returns validated value.

double getSqFt(int roomNumber);
// Prompts user for square footage of a room (> 0). Returns validated value.

double getPricePerGallon(int roomNumber);
// Prompts user for price of paint per gallon (>= $10). Returns validated value.

int gallonsForRoom(double squareFeet);
// Calculates gallons needed for a room, rounding up to nearest whole number.

void displayEstimate(double paintCharge, int gallonsNeeded, double laborCharge, double laborHours);
// Displays the final estimate with formatted output.
//------------------------------------------------------------

int getRooms() {
    int rooms;
    do {
        cout << "Enter number of rooms to be painted: ";
        cin >> rooms;
        if (rooms < 1) {
            cout << "Invalid input. Must be at least 1 room.\n";
        }
    } while (rooms < 1);
    return rooms;
}

double getSqFt(int roomNumber) {
    double sqft;
    do {
        cout << "Enter square footage for room " << roomNumber << ": ";
        cin >> sqft;
        if (sqft <= 0) {
            cout << "Invalid input. Square footage must be greater than 0.\n";
        }
    } while (sqft <= 0);
    return sqft;
}

double getPricePerGallon(int roomNumber) {
    double price;
    do {
        cout << "Enter price per gallon of paint for room " << roomNumber << ": $";
        cin >> price;
        if (price < 10.0) {
            cout << "Invalid input. Price must be at least $10.00.\n";
        }
    } while (price < 10.0);
    return price;
}

int gallonsForRoom(double squareFeet) {
    return static_cast<int>(ceil(squareFeet / SQFT_PER_GALLON));
}

void displayEstimate(double paintCharge, int gallonsNeeded, double laborCharge, double laborHours) {
    cout << fixed << setprecision(2);
    cout << "\n--- Paint Job Estimate ---\n";
    cout << "Gallons of paint required: " << gallonsNeeded << endl;
    cout << "Hours of labor required:   " << laborHours << endl;
    cout << "Cost of paint:            $" << paintCharge << endl;
    cout << "Labor charges:            $" << laborCharge << endl;
    cout << "Total cost:               $" << (paintCharge + laborCharge) << endl;
}

int main() {
    int numRooms = getRooms();
    double paintCharge = 0.0, laborCharge = 0.0, laborHours = 0.0;
    int gallonsNeeded = 0;

    for (int i = 1; i <= numRooms; ++i) {
        double sqft = getSqFt(i);
        double price = getPricePerGallon(i);
        int gallons = gallonsForRoom(sqft);
        double hours = gallons * HOURS_PER_GALLON;

        gallonsNeeded += gallons;
        paintCharge += gallons * price;
        laborHours += hours;
        laborCharge += hours * LABOR_RATE;
    }

    displayEstimate(paintCharge, gallonsNeeded, laborCharge, laborHours);
    return 0;
}
