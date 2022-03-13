//
// Created by Mitchel Samual on 3/13/22.
//

#ifndef COMPUTORV_COMPLEXNUMBER_H
#define COMPUTORV_COMPLEXNUMBER_H

#include "Computor.hpp"

class ComplexNumber {

private:
	double	real;
	double	imag;

public:
	ComplexNumber();
	ComplexNumber(double real, double imag = 0);
	ComplexNumber(const ComplexNumber& other);

	ComplexNumber&	operator=(const ComplexNumber& other);
	ComplexNumber&	operator+=(const ComplexNumber& other);
	ComplexNumber&	operator-=(const ComplexNumber& other);
	ComplexNumber&	operator*=(const ComplexNumber& other);
	ComplexNumber&	operator/=(const ComplexNumber& other);

	ComplexNumber&	operator+=(double other);
	ComplexNumber&	operator-=(double other);
	ComplexNumber&	operator*=(double other);
	ComplexNumber&	operator/=(double other);

	std::string		toString();

	double 			getReal() const;
	double			getImag() const;

};

ComplexNumber	operator+(const ComplexNumber& left, const ComplexNumber& right);
ComplexNumber	operator-(const ComplexNumber& left, const ComplexNumber& right);
ComplexNumber	operator*(const ComplexNumber& left, const ComplexNumber& right);
ComplexNumber	operator/(const ComplexNumber& left, const ComplexNumber& right);

ComplexNumber	operator+(double left, const ComplexNumber& right);
ComplexNumber	operator-(double left, const ComplexNumber& right);
ComplexNumber	operator*(double left, const ComplexNumber& right);
ComplexNumber	operator/(double left, const ComplexNumber& right);

ComplexNumber	operator+(const ComplexNumber& left, double right);
ComplexNumber	operator-(const ComplexNumber& left, double right);
ComplexNumber	operator*(const ComplexNumber& left, double right);
ComplexNumber	operator/(const ComplexNumber& left, double right);

std::ostream&	operator<<(std::ostream&, const ComplexNumber& CN);


#endif //COMPUTORV_COMPLEXNUMBER_H
