#include "Calculator.h"

std::vector<std::tuple<ComplexNumber, int>> Calculator::Mandelbrot(const int maxDepth, const float deltax, const float deltay) {
	ComplexNumber c;
	int d;
	std::vector<std::tuple<ComplexNumber, int>> pointsToPlot;
	pointsToPlot.clear();

	for (float i = -3; i <= 3; i += deltax) {
		for (float j = -3; j <= 3; j += deltay) {

			c = { i,j };
			d = GetDepth(c, maxDepth);
			if (d != -1) {
				pointsToPlot.push_back(std::tuple<ComplexNumber, int>(c, d));
			}
		}
	}

	return pointsToPlot;
	
	//c = { 0,0.1 };
	//d = GetDepth(c);
	//_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(c, d));
	//_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(ComplexNumber(d,d), 3));
	//_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(ComplexNumber(_maxDepth, _maxDepth), 4));
	
	/*
	_drawPane->_pointsToPlot.push_back( std::tuple<ComplexNumber, int>(ComplexNumber(1, 0), 0) );
	_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(ComplexNumber(1.5, 0), 3));
	_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(ComplexNumber(2, 0), 0));
	_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(ComplexNumber(2.5, 0), 3));
	_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(ComplexNumber(3, 0), 0));*/
}

ComplexNumber Calculator::z(const ComplexNumber & c, const ComplexNumber& z) const {
	ComplexNumber result;
	result = z * z + c;
	return result;
}

int Calculator::Distance(const ComplexNumber& c) const {
	return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

int Calculator::GetDepth(const ComplexNumber& c, const int maxDepth) const {
	int depth = -2;
	ComplexNumber current = c;
	std::vector<ComplexNumber> pastValues = { c };
	for (int i = 0; i <= maxDepth+2; i++) {
		current = z(c, current);
		if (Distance(current) > 2) {
			return -1;
		}
		for (auto j : pastValues) {
			if (j == current) {
				i = maxDepth + 3;
				//_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(ComplexNumber(7, 3), 1));
				break;
			}
		}
		pastValues.push_back(current);
		//_drawPane->_pointsToPlot.push_back(std::tuple<ComplexNumber, int>(current, 2));
		depth++;
		if (depth >= maxDepth) {
			return -1;
		}
	}
	return depth;

}
