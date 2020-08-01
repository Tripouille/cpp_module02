#include <math.h>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_rawBits = 0;
}

Fixed::Fixed(int const value)
{
	_rawBits = value << _dotDelta;
}

Fixed::Fixed(float const value)
{
	_rawBits = roundf(value * (1 << _dotDelta));
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const &other)
{
	*this = other;
}

Fixed		&Fixed::operator=(Fixed const &other)
{
	if (this == &other)
		return (*this);
	_rawBits = other.getRawBits();
	return (*this);
}

int			Fixed::getRawBits(void) const
{
	return (_rawBits);
}

int			Fixed::getDotDelta(void) const
{
	return (_dotDelta);
}

void		Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

int			Fixed::toInt(void) const
{
	return (_rawBits >> _dotDelta);
}

float		Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _dotDelta));
}

std::ostream	&operator<<(std::ostream &os, Fixed const &value)
{
	os << value.toFloat();
	return (os);
}

Fixed		Fixed::operator*(Fixed const &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed	Fixed::operator+(Fixed const &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	&Fixed::operator++()
{
	_rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++*this;
	return (temp);
}

Fixed		&Fixed::operator--()
{
	_rawBits--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	Fixed	temp = *this;
	--*this;
	return (temp);
}

int		Fixed::operator>(Fixed const &other) const
{
	return (_rawBits > other._rawBits);
}

int		Fixed::operator<(Fixed const &other) const
{
	return (_rawBits < other._rawBits);
}

int		Fixed::operator>=(Fixed const &other) const
{
	return (_rawBits >= other._rawBits);
}

int		Fixed::operator<=(Fixed const &other) const
{
	return (_rawBits <= other._rawBits);
}

int		Fixed::operator==(Fixed const &other) const
{
	return (_rawBits == other._rawBits);
}

int		Fixed::operator!=(Fixed const &other) const
{
	return (_rawBits != other._rawBits);
}

Fixed 			&Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

Fixed const		&Fixed::max(Fixed const &a, Fixed const &b)
{
	return (a > b ? a : b);
}

Fixed 			&Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed const		&Fixed::min(Fixed const &a, Fixed const &b)
{
	return (a < b ? a : b);
}
