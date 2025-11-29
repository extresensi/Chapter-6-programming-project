/*
File Name: SafestDrivingArea.cpp
Developer/Programmer: Charles Duncan
Date: 11/29/25
Requirements:
This program asks the user to enter the number of automobile accidents reported in five
different geographic areas. It validates the input to ensure no negative values are entered.
The program determines which area had the fewest accidents and displays the safest driving
area. The program uses modular functions (including main) and continues until the user
chooses to quit.
*/

#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------------
// Function Prototypes
int getAccidents(string areaName);
// Prompts user for the number of accidents in a given area,
// validates input (must be >= 0), and returns the value.

int findLowest(int north, int south, int east, int west, int central);
// Determines which area has the fewest accidents and returns
// the index of that area.

void displaySafest(int lowestIndex);
// Displays the safest driving area based on the index returned
// by findLowest().
//------------------------------------------------------------

int getAccidents(string areaName) {
    int accidents;
    do {
        cout << "Enter the number of accidents reported in the " << areaName << " area: ";
        cin >> accidents;
        if (accidents < 0) {
            cout << "Invalid input. Number of accidents cannot be negative.\n";
        }
    } while (accidents < 0);
    return accidents;
}

int findLowest(int north, int south, int east, int west, int central) {
    int lowest = north;
    int index = 0; // 0 = North, 1 = South, 2 = East, 3 = West, 4 = Central

    if (south < lowest) { lowest = south; index = 1; }
    if (east < lowest)  { lowest = east;  index = 2; }
    if (west < lowest)  { lowest = west;  index = 3; }
    if (central < lowest) { lowest = central; index = 4; }

    return index;
}

void displaySafest(int lowestIndex) {
    string areas[5] = {"North", "South", "East", "West", "Central"};
    cout << "The safest driving area is: " << areas[lowestIndex] << endl;
}

int main() {
    char choice;
    do {
        // Step 1: Get accident data for each area
        int north   = getAccidents("North");
        int south   = getAccidents("South");
        int east    = getAccidents("East");
        int west    = getAccidents("West");
        int central = getAccidents("Central");

        // Step 2: Find the safest area
        int safestIndex = findLowest(north, south, east, west, central);

        // Step 3: Display results
        displaySafest(safestIndex);

        // Step 4: Ask user if they want to repeat
        cout << "Do you want to process another set of areas? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "Program terminated. Goodbye!\n";
    return 0;
}
