/*
File Name: StarSearch.cpp
Developer/Programmer: Charles Duncan
Date: 11/29/25
Requirements:
This program calculates a performer's final score based on five judge ratings. Each score is
between 0 and 10 and may include decimals. The highest and lowest scores are dropped, and the
average of the remaining three is computed. The program uses modular functions for input,
comparison, and calculation, with clear validation and purpose for each function.
*/

#include <iostream>
using namespace std;

//------------------------------------------------------------
// Function Prototypes
double getScore();
// Prompts the user for a judge's score between 0 and 10.
// Validates input and returns the score.

bool isLower(double a, double b);
// Returns true if a <= b, false otherwise.

bool isHigher(double a, double b);
// Returns true if a >= b, false otherwise.

double calcAverage(double total, double minScore, double maxScore);
// Calculates average by removing min and max from total and dividing remaining by 3.
// Returns the average score.
//------------------------------------------------------------

double getScore() {
    double score;
    do {
        cout << "Enter judge's score (0 - 10): ";
        cin >> score;
        if (score < 0 || score > 10) {
            cout << "Invalid input. Score must be between 0 and 10.\n";
        }
    } while (score < 0 || score > 10);
    return score;
}

bool isLower(double a, double b) {
    return a <= b;
}

bool isHigher(double a, double b) {
    return a >= b;
}

double calcAverage(double total, double minScore, double maxScore) {
    return (total - minScore - maxScore) / 3.0;
}

int main() {
    double score, minScore, maxScore, total = 0;

    // First judge
    score = getScore();
    minScore = score;
    maxScore = score;
    total += score;

    // Remaining four judges
    for (int i = 0; i < 4; ++i) {
        score = getScore();
        total += score;

        if (isLower(score, minScore)) {
            minScore = score;
        }
        if (isHigher(score, maxScore)) {
            maxScore = score;
        }
    }

    double average = calcAverage(total, minScore, maxScore);
    cout << "Final score (average of middle three): " << average << endl;

    return 0;
}
