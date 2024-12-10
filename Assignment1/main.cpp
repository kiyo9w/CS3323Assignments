#include "Polynomial.h"

int main() {
    Polynomial p;

    cin >> p;
    cout << "The first polynomial is:\n" << p << endl;

    while (true) {
        cout << "\nChoose an option:\n";
        cout << "1. Evaluate the polynomial with x\n";
        cout << "2. Calculate the sum of two polynomials\n";
        cout << "3. Calculate the product of two polynomials\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        }

        if (choice == 1) {
            double xVal;
            cout << "Enter a value for x to evaluate the polynomial: ";
            cin >> xVal;
            cout << "P(" << xVal << ") = " << p.evaluate(xVal) << endl;
        }

        if (choice == 2 || choice == 3) {
            Polynomial q;
            cout << "Enter the second polynomial:\n";
            cin >> q;
            cout << "The second polynomial is:\n" << q << endl;

            if (choice == 2) {
                Polynomial sum = p + q;
                cout << "Sum of the two polynomials:\n" << sum << endl;
            } else if (choice == 3) {
                Polynomial product = p * q;
                cout << "Product of the two polynomials:\n" << product << endl;
            }
        }

        if (choice < 0 || choice > 4) {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}