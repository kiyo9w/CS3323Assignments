#include "Polynomial.h"

Polynomial::Polynomial(int degree) : coefficients(degree + 1, 0) {}

Polynomial::Polynomial(const Polynomial& other) : coefficients(other.coefficients) {}

double Polynomial::evaluate(double x) const {
    double result = 0, xPower = 1;
    for (double coef : coefficients) {
        result += coef * xPower;
        xPower *= x;
    }
    return result;
}

istream& operator>>(istream& in, Polynomial& p) {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    in >> degree;
    p.coefficients.assign(degree + 1, 0);
    cout << "Enter " << degree + 1 << " coefficients from constant to highest degree:\n";
    for (int i = degree; i >= 0; i--) in >> p.coefficients[i];
    return in;
}

ostream& operator<<(ostream& out, const Polynomial& p) {
    bool first = true;
    for (int i = p.coefficients.size() - 1; i >= 0; --i) {
        if (p.coefficients[i] != 0) {
            if (!first) out << (p.coefficients[i] < 0 ? " - " : " + ");
            if (first && p.coefficients[i] < 0) out << "-";
            if (abs(p.coefficients[i]) != 1 || i == 0) out << abs(p.coefficients[i]);
            if (i > 0) out << "x" << (i > 1 ? "^" + to_string(i) : "");
            first = false;
        }
    }
    return first ? out << 0 : out;
}

Polynomial operator+(const Polynomial& a, const Polynomial& b) {
    int maxDegree = max(a.coefficients.size(), b.coefficients.size());
    Polynomial result(maxDegree - 1);
    for (int i = 0; i < maxDegree; ++i)
        result.coefficients[i] = (i < a.coefficients.size() ? a.coefficients[i] : 0) +
                                 (i < b.coefficients.size() ? b.coefficients[i] : 0);
    return result;
}

Polynomial operator*(const Polynomial& a, const Polynomial& b) {
    Polynomial result(a.coefficients.size() + b.coefficients.size() - 2);
    for (int i = 0; i < a.coefficients.size(); ++i)
        for (int j = 0; j < b.coefficients.size(); ++j)
            result.coefficients[i + j] += a.coefficients[i] * b.coefficients[j];
    return result;
}