#ifndef CPP_MODULES_FIXED_H
#define CPP_MODULES_FIXED_H

class Fixed {
private:
	int fixedPointValue_;
	static const int franctionalBits_ = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();

	Fixed &operator=(const Fixed &fixed);

	int getRawBits() const;
	void setRawBits(int fixedPointValuh);
};

#endif
