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
using namespace std;

// Epsilon created for floating-point zero comparison
const double EPS = 1e-9;

class QuadraticEquation {
public:
    double discriminant; // discriminant = b^2 - 4ac
    double root1;        // first root (if real)
    double root2;        // second root (if real)

    // Constructor initializes coefficient values
    QuadraticEquation(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    // Getters return coefficient values
    double getA() const {
        return a;
    }
    double getB() const {
        return b;
    }
    double getC() const {
        return c;
    }

    // Setters update coefficients
    void setA(double a) {
        this->a = a;
    }
    void setB(double b) {
        this->b = b;
    }
    void setC(double c) {
        this->c = c;
    }


    void compute() {


        discriminant = (pow(b, 2) - 4 * a * c);

        // Positive discriminant? 2 real roots.
        if (discriminant > EPS) {
            root1 = (-b + sqrt(discriminant)) / (2 * a);
            root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Positive discriminant has two roots x = "
                << root1 << " and x = " << root2 << "." << endl;
        }
        // Is discriminant close to zero? 1 real root.
        else if (fabs(discriminant) <= EPS) {
            root1 = (-b / (2 * a));
            cout << "Zero discriminant has 1 root x = "
                << root1 << "." << endl;
        }
        // Negative discriminant? 0 real roots.
        else {
            cout << "Negative discriminant has no real roots (complex roots)." << endl;
        }
    }


private:
    // Coefficients of quadratic equation
    double a;
    double b;
    double c;
};

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