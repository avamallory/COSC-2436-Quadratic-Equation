/*
* Ava Mallory
* 3/7/26
* This program finds the roots of a quadratic equation.
* A class manages the variables a, b, and c, and determines
* the discriminant.
*/


#include <iostream>
#include <cmath>
#include <limits>
#include "QuadraticEquation.h"
using namespace std;


int main() {
   
    double a, b, c;
    // Get user input
    cout << "Enter coefficients a, b, c for ax^2 + bx + c = 0: " << endl;

    // Loop until correct input received
    while (true) {
        // Error message if input isn't a number
        if (!(cin >> a >> b >> c)) {
            cout << "Invalid input." << endl
                << "Enter three numbers: " << endl;

            // Fix cin and clear buffer for fresh input 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // Error message if 'a' is zero
        else if (fabs(a) <= EPS) {
            cout << "Invalid input. Leading coefficient cannot be zero." << endl;
        }
        // Break loop if input is valid
        else {
            break;
        }
    }

    // Create a QuadraticEquation object and then compute its roots, if any
    QuadraticEquation q(a, b, c);
    q.compute();


    return 0;
}
