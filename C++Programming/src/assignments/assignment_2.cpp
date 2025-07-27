#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Operator overloading: addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Operator overloading: subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Operator overloading: multiplication
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imag * other.imag;
        double i = real * other.imag + imag * other.real;
        return Complex(r, i);
    }

    // Operator overloading: equality
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }

    // Friend function: input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Friend function: output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        if (c.imag < 0)
            out << c.real << " - " << -c.imag << "i";
        else
            out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;
    int choice;

    cout << "--- Complex Number Calculator ---\n";
    cout << "Enter first complex number:\n";
    cin >> c1;

    cout << "Enter second complex number:\n";
    cin >> c2;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add\n2. Subtract\n3. Multiply\n4. Compare\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Complex result;

        switch (choice) {
            case 1:
                result = c1 + c2;
                cout << "Result: " << result << endl;
                break;
            case 2:
                result = c1 - c2;
                cout << "Result: " << result << endl;
                break;
            case 3:
                result = c1 * c2;
                cout << "Result: " << result << endl;
                break;
            case 4:
                if (c1 == c2)
                    cout << "The complex numbers are equal.\n";
                else
                    cout << "The complex numbers are NOT equal.\n";
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
