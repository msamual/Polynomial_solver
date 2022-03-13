//
// Created by Mitchel Samual on 3/13/22.
//

#include "../includes/ComplexNumber.hpp"

ComplexNumber::ComplexNumber() : real(0), imag(0)
{}

ComplexNumber::ComplexNumber(double real, double imag) : real(real), imag(imag)
{}

ComplexNumber::ComplexNumber(const ComplexNumber &other) : real(other.real), imag(other.imag)
{}

ComplexNumber&	ComplexNumber::operator=(const ComplexNumber &other)
{
	this->real = other.real;
	this->imag = other.imag;
	return *this;
}

double 			ComplexNumber::getReal() const {return this->real;}
double			ComplexNumber::getImag() const {return this->imag;}

ComplexNumber&	ComplexNumber::operator+=(const ComplexNumber &other)
{
	this->real += other.real;
	this->imag += other.imag;
	return *this;
}

ComplexNumber&	ComplexNumber::operator-=(const ComplexNumber &other)
{
	this->real -= other.real;
	this->imag -= other.imag;
	return *this;
}

ComplexNumber&	ComplexNumber::operator*=(const ComplexNumber &other)
{
	double a, b;
	a = (this->getReal() * other.getReal()) + abs(this->getImag() * other.getImag());
	b =	(this->getReal() * other.getImag()) + (this->getImag() * other.getReal());
	this->real = a;
	this->imag = b;
	return *this;
}

ComplexNumber&	ComplexNumber::operator/=(const ComplexNumber &other)
{
	double a, b;
	a = (this->getReal() * other.getReal()) + abs(this->getImag() * other.getImag());
	b =	(this->getReal() * -other.getImag()) + (this->getImag() * other.getReal());
	this->real = a;
	this->imag = b;
	return *this;
}

ComplexNumber&	ComplexNumber::operator+=(double other)
{
	this->real += other;
	return *this;
}

ComplexNumber&	ComplexNumber::operator-=(double other)
{
	this->real -= other;
	return *this;
}

ComplexNumber&	ComplexNumber::operator*=(double other)
{
	this->real *= other;
	this->imag *= other;
	return *this;
}

ComplexNumber&	ComplexNumber::operator/=(double other)
{
	this->real /= other;
	this->imag /= other;
	return *this;
}

std::string 	ComplexNumber::toString()
{
	std::stringstream ss;
	ss << this->getReal();
	if (this->getImag())
		ss << (this->getImag() < 0 ? " + " : " - ") << abs(this->getImag()) << 'i';
	return ss.str();
}

ComplexNumber	operator+(const ComplexNumber& left, const ComplexNumber& right)
{
	return (ComplexNumber(left.getReal() + right.getReal()), left.getImag() + right.getImag());
}

ComplexNumber	operator-(const ComplexNumber& left, const ComplexNumber& right)
{
	return (ComplexNumber(left.getReal() - right.getReal()), left.getImag() - right.getImag());
}

ComplexNumber	operator*(const ComplexNumber& left, const ComplexNumber& right)
{
	double a, b;

	a = (left.getReal() * right.getReal()) + abs(left.getImag() * right.getImag());
	b =	(left.getReal() * right.getImag()) + (left.getImag() * right.getReal());
	return ComplexNumber(a, b);
}

ComplexNumber	operator/(const ComplexNumber& left, const ComplexNumber& right)
{
	double a, b;

	a = (left.getReal() * right.getReal()) + abs(left.getImag() * -right.getImag());
	b =	(left.getReal() * -right.getImag()) + (left.getImag() * right.getReal());
	return ComplexNumber(a, b);
}

ComplexNumber	operator+(const ComplexNumber& left, double right)
{
	return (ComplexNumber(left.getReal() + right), left.getImag());
}

ComplexNumber	operator-(const ComplexNumber& left, double right)
{
	return (ComplexNumber(left.getReal() - right), left.getImag());
}

ComplexNumber	operator*(const ComplexNumber& left, double right)
{
	return ComplexNumber(left.getReal() * right, left.getImag() * right);
}

ComplexNumber	operator/(const ComplexNumber& left, double right)
{
	return ComplexNumber(left.getReal() / right, left.getImag() / right);
}

ComplexNumber	operator+(double left, const ComplexNumber& right)
{
	ComplexNumber	res(left + right.getReal(), right.getImag());
	return (res);
}

ComplexNumber	operator-(double left, const ComplexNumber& right)
{
	ComplexNumber	res(left - right.getReal(), right.getImag());
	return (res);
}

ComplexNumber	operator*(double left, const ComplexNumber& right)
{
	return ComplexNumber(left * right.getReal(), left * right.getReal());
}

ComplexNumber	operator/(double left, const ComplexNumber& right)
{
	return ComplexNumber(left / right.getReal(), left / right.getImag());
}

std::ostream&	operator<<(std::ostream& stream, const ComplexNumber& CN)
{
	stream << CN.getReal();
	if (CN.getImag())
		stream << (CN.getImag() < 0 ? " + " : " - ") << abs(CN.getImag()) << 'i';
	return stream;
}