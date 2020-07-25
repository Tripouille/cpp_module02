#ifndef FIXED_HPP 
# define FIXED_HPP
# include <iostream>

class Fixed 
{
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed(void);
		Fixed(Fixed const &other);
		Fixed	&operator=(Fixed const &other);

		int			getRawBits(void) const;
		int			getDotDelta(void) const;
		void		setRawBits(int const raw);
		int			toInt(void) const;
		float		toFloat(void) const;

	private:
		int 				_rawBits;
		int const 			_dotDelta = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &value);

#endif