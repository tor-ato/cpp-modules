#ifndef CPP_MODULES_FIXED_H
#define CPP_MODULES_FIXED_H

#include <iostream>

class Fixed {
private:
	int fixedPointValue_;
	static const int fractionalBits_ = 8;
public:
	Fixed();
	Fixed(const int intVal);
	Fixed(const float floatVal);
	Fixed(const Fixed &fixed);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif
