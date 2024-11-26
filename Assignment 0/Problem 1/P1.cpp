#include <iostream>
using namespace std;

class complexNumber {
private:
    static int numCount;
    int Re, Imag;

public:
    static void setNumCount(int newNumCount){
        numCount = newNumCount;
    }

    complexNumber() {
        numCount++;
    }

    complexNumber(int Real, int Imaginary) {
        numCount++;
        cout << "constructor with argument is called" << endl;
        Re = Real;
        Imag = Imaginary;
    }

    ~complexNumber() {
        cout << "destructor is called" << endl;
        numCount--;
    }

    complexNumber(complexNumber &anycomplex) {
        numCount++;
        cout << endl;
        cout << "Copy constructor called" << endl;
        Re = anycomplex.Re;
        Imag = anycomplex.Imag;
    }

    void printComplex() {
        cout << "number of active complex numbers = " << numCount
             << " and present number..... = " << Re << " + j" << Imag << endl;
    }

    complexNumber operator+(complexNumber &b) {
        complexNumber temp;
        cout << "overloaded + is called" << endl;
        temp.Re = Re + b.Re;
        temp.Imag = Imag + b.Imag;
        return temp;
    }

    complexNumber operator++() {
        complexNumber temp;
        cout << "overloaded ++(pre) called" << endl;
        temp.Re = ++Re;
        temp.Imag = ++Imag;
        return temp;
    }

    complexNumber operator++(int) {
        complexNumber temp;
        cout << "overloaded ++(post) called" << endl;
        temp.Re = Re++;
        temp.Imag = Imag++;
        return temp;
    }

    friend ostream &operator<<(ostream &out, complexNumber &somecomplex) {
        cout << "overloaded << called" << endl;
        out << somecomplex.Re << " + j" << somecomplex.Imag;
        return out;
    }

    bool operator==(complexNumber &somecomplex){
        cout << "overload == called" << endl;
        bool check = (Re == somecomplex.Re && Imag == somecomplex.Imag);
        return check;
    }

    complexNumber operator*(complexNumber &somecomplex){
        cout << "overload * called" << endl;
        complexNumber result;
        result.Re = Re * somecomplex.Re - Imag * somecomplex.Imag;
        result.Imag = Re * somecomplex.Imag + Imag * somecomplex.Re;
        return result;
    }

    complexNumber& operator=(complexNumber somecomplex){
        cout << "operator = called" << endl;
        if(this != &somecomplex){
            Re = somecomplex.Re;
            Imag = somecomplex.Imag;
        }
        return *this;
    }

    friend istream &operator>>(istream &in, complexNumber &somecomplex){
        cout << "operator >> called" << endl;
        cout << "Enter the real part: ";
        in >> somecomplex.Re;
        cout << "Enter the imaginary part: ";
        in >> somecomplex.Imag;
        return in;
    }
};

int complexNumber::numCount = 0;

void printC(complexNumber a) {
    a.printComplex();
}

int main() {
    complexNumber A, B(1, 2), C(2, 3);

    B.printComplex();

    ++B;

    printC(C);

    A = B + C;

    A = B++;

    A.printComplex();
    B.printComplex();

    cout << A << B;

    cout << (A == B);

    C = A*B;
    cout << C;

    A = B;
    cout << A;

    cin >> A >> B;

    cout << A << B;

    cin.get();

    return 0;
}
