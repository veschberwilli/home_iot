#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
  private:
    double real {0.0};                                  // Default constructor
    double imag {0.0};
  public:
      Complex() {}
	  Complex(double r, double i) : real(r), imag(i) {} // Constructor with arguments
	  
	  // Accept compiler-generated defaults for copy constructor and assignment operator
	  // Complex(Complex& other) : real(other.real), imag(other.imag) {}
	  // Complex& operator=(Complex&) {real = other.real; imag = other.imag;}
	  
	  // Unary operators are member functions
	  Complex operator +=(const Complex& rhs);
	  // Lots of other member functions
	  // ...
	  std::ostream& print(std::ostream& os) const;
};

//Binary operators are non-member functions
Complex operator + (const Complex& lhs, const Complex& rhs);
std::ostream& operator << (std::ostream&, const Complex&);

#endif //COMPLEX_H