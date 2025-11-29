/*
File Name: CelsiusTemperatureTable.cpp
Developer/Programmer: Charles Duncan
Date: 11/29/25
Requirements:
This program generates a temperature conversion table from Fahrenheit to Celsius for values
between 0 and 20 degrees Fahrenheit. It uses modular functions, named constants for flexibility,
and displays tabular data with proper formatting. The Celsius conversion is handled by a
dedicated function, and output is formatted with labels and precision.
*/

#include <iostream>
#include <iomanip>
using namespace std;

//------------------------------------------------------------
// Global Constants
const int MIN_FAHRENHEIT = 0;
const int MAX_FAHRENHEIT = 20;

//------------------------------------------------------------
// Function Prototypes
double getCelsius(int fahrenheit);
// Converts Fahrenheit to Celsius using the formula C = 5/9 * (F - 32).
// Input must be an integer Fahrenheit value.
// Returns the Celsius equivalent as a double.

void displayTable();
// Displays the temperature conversion table with headers and formatted output.
// Calls getCelsius() for each Fahrenheit value in the range.
//------------------------------------------------------------

double getCelsius(int fahrenheit) {
    return 5.0 / 9.0 * (fahrenheit - 32);
}

void displayTable() {
    cout << "Celsius Temperature Table\n";
    cout << "--------------------------\n";
    cout << setw(12) << "Fahrenheit" << setw(12) << "Celsius\n";
    cout << fixed << setprecision(1);

    for (int f = MIN_FAHRENHEIT; f <= MAX_FAHRENHEIT; ++f) {
        double c = getCelsius(f);
        cout << setw(12) << f << setw(12) << c << endl;
    }
}

int main() {
    displayTable();
    return 0;
}
