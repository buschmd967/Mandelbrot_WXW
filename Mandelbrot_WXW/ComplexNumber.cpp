#include "ComplexNumber.h"


ComplexNumber ComplexNumber::operator+(const ComplexNumber& c) {
	ComplexNumber result;
	result.real = real + c.real;
	result.imaginary = imaginary + c.imaginary;
	return result;
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& c) {
	ComplexNumber result;
	result.real = real - c.real;
	result.imaginary = imaginary - c.imaginary;
	return result;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& c) const{
	ComplexNumber result;
	result.real = (real * c.real) - (imaginary * c.imaginary);
	result.imaginary = (real * c.imaginary) + (imaginary * c.real);
	return result;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber c) {
	ComplexNumber result;
	result.real = (real * c.real) - (imaginary * c.imaginary);
	result.imaginary = (real * c.imaginary) + (imaginary * c.real);
	return result;
}

ComplexNumber ComplexNumber::operator*(const int& i) {
	ComplexNumber result;
	result.real = real * i;
	result.imaginary = imaginary * i;
	return result;
}

void ComplexNumber::operator=(const ComplexNumber& c) {
	real = c.real;
	imaginary = c.imaginary;
}

void ComplexNumber::operator=(ComplexNumber& c) {
	real = c.real;
	imaginary = c.imaginary;
}

void ComplexNumber::copy(ComplexNumber& c) const {
	c.real = real;
	c.imaginary = imaginary;
}

bool ComplexNumber:: operator==(const ComplexNumber& c) const {
	return (c.real == real) && (c.imaginary == imaginary);
}