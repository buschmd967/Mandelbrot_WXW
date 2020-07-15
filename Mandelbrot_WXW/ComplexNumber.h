#pragma once

#ifndef COMPLEXNUMBER_h_
#define COMPLEXNUMBER_h_


class ComplexNumber
{
public:
	float real;
	float imaginary;
	ComplexNumber(float r, float i) { real = r; imaginary = i; };
	ComplexNumber() { real = 0; imaginary = 0; }

	ComplexNumber operator+(const ComplexNumber& c);
	ComplexNumber operator-(const ComplexNumber& c);
	ComplexNumber operator*(const ComplexNumber& c) const;
	ComplexNumber operator*(const ComplexNumber c);
	ComplexNumber operator*(const int & i);
	void operator=(const ComplexNumber& c);
	void operator=(ComplexNumber& c);
	void copy(ComplexNumber& c) const;
	bool operator==(const ComplexNumber& c) const;
};

#endif
