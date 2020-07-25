#include "Fixed.hpp" 

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
	(void)_dotDelta;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed		&Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &other)
		return (*this);
	_rawBits = other.getRawBits();
	return (*this);
}

int			Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void		Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}
