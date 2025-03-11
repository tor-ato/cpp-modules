#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixedPointValue_(0) {
}

Fixed::Fixed(const int intVal) {
	this->fixedPointValue_ =  intVal * (1 << Fixed::fractionalBits_);
}

Fixed::Fixed(const float floatVal) {
	this->fixedPointValue_ = (int) roundf(floatVal * (1 << Fixed::fractionalBits_));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::~Fixed() {
}

Fixed &Fixed::operator=(const Fixed &fixed) {
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

bool Fixed::operator==(const Fixed &rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return !(*this == rhs);
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return !(*this > rhs);
}

bool Fixed::operator>(const Fixed &rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return !(*this < rhs);
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed result;
	int product = this->getRawBits() * rhs.getRawBits();
	result.setRawBits(product / (1 << (Fixed::fractionalBits_)));
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	Fixed result;
	int shifted = this->getRawBits() * (1 << Fixed::fractionalBits_);
	result.setRawBits(shifted / rhs.getRawBits());
	return result;
}

Fixed &Fixed::operator++() {
	this->fixedPointValue_++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--() {
	this->fixedPointValue_--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return a;
	return b;
}
