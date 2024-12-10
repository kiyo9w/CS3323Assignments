#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Polynomial {
    vector<double> coefficients;

public:
    Polynomial(int degree = 0);
    Polynomial(const Polynomial& other);

    double evaluate(double x) const;

    friend istream& operator>>(istream& in, Polynomial& p);
    friend ostream& operator<<(ostream& out, const Polynomial& p);

    friend Polynomial operator+(const Polynomial& a, const Polynomial& b);
    friend Polynomial operator*(const Polynomial& a, const Polynomial& b);
};

#endif