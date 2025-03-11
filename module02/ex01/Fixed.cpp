#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intVal) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue_ =  intVal * (1 << Fixed::fractionalBits_);
}

Fixed::Fixed(const float floatVal) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue_ = (int) roundf(floatVal * (1 << Fixed::fractionalBits_));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixedPointValue_ = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	return this->fixedPointValue_;
}

void Fixed::setRawBits(const int raw) {
	this->fixedPointValue_ = raw;
}

float Fixed::toFloat() const {
	return (float)this->fixedPointValue_ / (1 << Fixed::fractionalBits_);
}

int Fixed::toInt() const {
	return this->fixedPointValue_ / (1 << fractionalBits_) ;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
