#include <iostream>
#include <cmath>
#include <iomanip>
#include "assign5.h"

// Default constructor initializing real and imaginary parts to 0.
Complex::Complex() : real(0), imag(0) {}

// Parameterized constructor initializing real and imaginary parts with given values.
Complex::Complex(double real, double imag) : real(real), imag(imag) {}

// Overloaded << operator for displaying complex numbers.
std::ostream &operator<<(std::ostream &out, const Complex &c) {
  out << c.real << " + " << c.imag << "i";
  return out;
}

// Overloaded >> operator for reading complex numbers from the input stream.
std::istream &operator>>(std::istream &in, Complex &c) {
  std::cout << "Enter real part: ";
  in >> c.real;
  std::cout << "Enter imag part: ";
  in >> c.imag;
  return in;
}

// Overloaded arithmetic operators (+, -, *, /) for complex numbers.
Complex Complex::operator+(const Complex &other) {
  return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex &other) {
  return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex &scalar) const{
  
  // Multiplication of two complex numbers.
  double result_real = real * scalar.real - imag * scalar.imag;
  double result_imag = real * scalar.imag + imag * scalar.real;
  return Complex(result_real, result_imag);
}

Complex Complex::operator/(const Complex &other) {
  
  // Division of two complex numbers.
  double denominator = other.real * other.real + other.imag * other.imag;
  double result_real = (real * other.real + imag * other.imag) / denominator;
  double result_imag = (imag * other.real - real * other.imag) / denominator;
  std::cout << std::fixed << std::setprecision(2);
  return Complex(result_real, result_imag);
} 

//Method to calculate the magnitude for the complex number
double Complex::mag() {
  std::cout << std::fixed << std::setprecision(0);
  return sqrt(real * real + imag * imag);
}

//Method to find the conjugate for the complex number
Complex Complex::conjugate() {
  return Complex(real, -imag);
}

// Overloaded * operator for scalar multiplication with a complex number
Complex Complex::operator*(const double &scalar) {
  return Complex(real * scalar, imag * scalar);
}

// Friend function for scalar multiplication from the left.
Complex operator*(const double &scalar, const Complex &c) {
  return Complex(c.real * scalar, c.imag * scalar);
}

// Method displaying a menu for interacting with complex number functionalities
void Complex::menu() {
  int choice; 
  Complex c1, c2;

  cout << "Enter the first complex number:\n";
  cin >> c1;
  cout << "Enter the second complex number:\n";
  cin >> c2;
  
  while (true) {
    cout << "1: Additon\n2: Subtraction\n3; Multiplication\n4: Division\n5: Magnitude\n6: Conjugate\n7: Scalar multiplication from left\n8: Scalar multiplication from right\n9: Quit\nEnter your selection: ";
    cin >> choice;

    // Cases performing different operations on complex numbers
    // Outputting results to the console.
    switch (choice) {
      case 1:
        cout << "C1 + C2 = " << c1 + c2 << "\n";
        break;

      case 2:
        cout << "C1 - C2 = " << c1 - c2 << "\n";
        break;

      case 3:
        cout << "C1 * C2 = " << c1 * c2 << "\n";
        break;

      case 4:
        cout << "C1 / C2 = " << c1 / c2 << "\n";
        break;

      case 5:
        cout << "|C1| = " << c1.mag() << "\n";
        break;

      case 6:
        cout << "Conjugate of C1 = " << c1.conjugate() << "\n";
        break;

      case 7:
        double scalar;
        cout << "Enter the scalar: ";
        cin >> scalar;
        cout << scalar << " * C1 = " << scalar * c1 << "\n";

      case 8:
        double scalar2;
        cout << "Enter the scalar: ";
        cin >> scalar2;
        cout << "C1 * " << scalar2 << " = " << c1 * scalar2 << "\n";
        break;

      //thanks the user once they are done using the program
      case 9:
        cout << "Thank you for using the complex number app!\n";
        return;

      // Error handling for invalid choices.
      default:
        cout << "Invalid choice! Please enter a number between 1 and 9.\n";
        break;
    }
  }
}