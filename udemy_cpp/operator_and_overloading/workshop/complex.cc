#include "complex.h"

using namespace std;

// Unary operators are member functions
Complex Complex::operator +=(const Complex& rhs) {
    real += rhs.real;                     // Assign new value of real member
    imag += rhs.imag;                 // Assign new value of imag member
    return *this;                           // Return modified object by value
};
	
// Lots of other member functions
// ...

std::ostream& Complex::print(std::ostream& os) const {
	os << "(" << real << ", " << imag << ")";
	return os;
}

//Binary operators are non-member functions
Complex operator + (const Complex& lhs, const Complex& rhs) {
    Complex temp {lhs};                 // Make a copy of the lhs argument
    temp += rhs;                             // Add the rhs argument to it
    return temp;                              // Return the result
}

std::ostream& operator << (std::ostream& os, const Complex& c) {
	return c.print(os);
}

int main() {
	Complex c;         // Default constructor
	Complex c1(1, 1);
	Complex c2(2, 2);  // Constructor with arguments
	Complex c3(c);     // Copy constructor
	cout << "c = " << c << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	cout << "Assigning c3 to c2" << endl;
	c3 = c2;
	cout << "c3 = " << c3 << endl;
	cout << "c1 + c2 = " << c1 + c2 << endl;
	cout << "Calculating c2 += c3" << endl;
	c2 += c3;
	cout << "c2 = " << c2 << endl;
}