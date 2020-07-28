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

		Fixed		&operator=(Fixed const &other);
		Fixed		operator*(Fixed const &other) const;
		Fixed		operator/(Fixed const &other) const;
		Fixed		operator+(Fixed const &other) const;
		Fixed		operator-(Fixed const &other) const;
		Fixed		&operator++();
		Fixed		operator++(int);
		int			operator>(Fixed const &other) const;
		int			operator<(Fixed const &other) const;
		int			operator>=(Fixed const &other) const;
		int			operator<=(Fixed const &other) const;
		int			operator==(Fixed const &other) const;
		int			operator!=(Fixed const &other) const;
 
		int			getRawBits(void) const;
		int			getDotDelta(void) const;
		void		setRawBits(int const raw);
		int			toInt(void) const;
		float		toFloat(void) const;

		static Fixed 			&max(Fixed &a, Fixed &b);
		static Fixed const		&max(Fixed const &a, Fixed const &b);
		static Fixed 			&min(Fixed &a, Fixed &b);
		static Fixed const		&min(Fixed const &a, Fixed const &b);

	private:
		int 				_rawBits;
		static int const	_dotDelta = 8;
};

std::ostream	&operator<<(std::ostream &os, Fixed const &value);

#endif