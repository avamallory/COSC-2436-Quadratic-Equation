#include "QuadraticEquation.h"
#include <cmath>
#include <iostream>

using namespace std;

// Epsilon created for floating-point zero comparison
const double EPS = 1e-9;

// Constructor initializes coefficient values
QuadraticEquation::QuadraticEquation(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

// Getters return coefficient values
double QuadraticEquation::getA() const {
    return a;
}

double QuadraticEquation::getB() const {
    return b;
}

double QuadraticEquation::getC() const {
    return c;
}

// Setters update coefficients
void QuadraticEquation::setA(double a) {
    this->a = a;
}

void QuadraticEquation::setB(double b) {
    this->b = b;
}

void QuadraticEquation::setC(double c) {
    this->c = c;
}


void QuadraticEquation::compute() {
    discriminant = (pow(b, 2) - 4 * a * c);

    // Positive discriminant? 2 real roots.
    if (discriminant > EPS) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Positive discriminant has two roots x = "
            << root1 << " and x = " << root2 << "." << endl;
    }
    // Is discriminant practically zero? 1 real root.
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


