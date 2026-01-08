#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed {
  private:
	int raw_bits;
	static const int num_fractional_bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &fx);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// ex01:
	Fixed(const int decimal);
	Fixed(const float floating);
	int toInt(void) const;
	float toFloat(void) const;

	// ex02:
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &fx);

#endif
