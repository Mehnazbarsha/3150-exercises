#include <iostream>
#include <limits>
#include "isPrimeFunction.h"

using namespace std;

int main() {
    int testForPrime;

    cout << "=== Prime Number Checker ===" << endl;
    cout << "Enter an integer to test: ";

    // Input validation
    while (!(cin >> testForPrime)) {
        cout << "Invalid input! Please enter a valid integer: ";
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    if (isPrimeInteger(testForPrime)) {
        cout << testForPrime << " is a prime number!" << endl;
    } else {
        cout << testForPrime << " is NOT a prime number!" << endl;
    }

    // Additional information
    if (testForPrime <= 1) {
        cout << "Note: Numbers less than or equal to 1 are not considered prime by definition." << endl;
    } else if (testForPrime == 2) {
        cout << "Note: 2 is the smallest and only even prime number." << endl;
    }

    return 0;
}
