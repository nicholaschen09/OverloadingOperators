#ifndef ASSIGN5_H
#define ASSIGN5_H

#include <iostream>
#include <cmath>

using namespace std;

class Complex {

//public functions declaration
public:
  double real;
  double imag;

  /// Default constructor for the Complex class
  Complex();
  Complex(double real, double imag);

  //Overloaded operators for addition, subtraction, multiplication, and division of complex numbers.
  Complex operator+(const Complex &other);
  Complex operator-(const Complex &other);
  Complex operator*(const Complex &scalar) const;
  Complex operator/(const Complex &other);

  //// Method to calculate the magnitude of the complex number.
  double mag();

  // Method to find the conjugate of the complex number.
  Complex conjugate();

  // Overloaded operator for scalar multiplication with a complex number.
  Complex operator*(const double &scalar);

  // Overloaded insertion (<<) and extraction (>>) operators for input and output operations with complex numbers.
  friend std::ostream &operator<<(std::ostream &out, const Complex &c);
  friend std::istream &operator>>(std::istream &in, Complex &c);

  void menu();

};

#endif