#pragma once
#include "ComplexNumber.h"
#include <vector>
#include <tuple>

class Calculator
{
private:
	ComplexNumber _c = ComplexNumber(-1,0);
	ComplexNumber z(const ComplexNumber & c, const ComplexNumber& z) const;
	int GetDepth(const ComplexNumber& c, const int maxDepth) const;
	int Distance(const ComplexNumber& c) const;
public:
	Calculator() {}
	~Calculator() {}
	std::vector<std::tuple<ComplexNumber, int>> Mandelbrot(const int maxDepth, const float deltax, const float deltay);
};

