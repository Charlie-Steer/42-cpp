#ifndef FIXED_HPP
#define FIXED_HPP

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
};

#endif
