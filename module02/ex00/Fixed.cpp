#include "Fixed.h"
#include <iostream>

Fixed::Fixed() : fixedPointValue_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : fixedPointValue_(0) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
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
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue_;
}

void Fixed::setRawBits(const int fixedPointValue) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue_ = fixedPointValue;
}
