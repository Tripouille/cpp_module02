#ifndef FIXED_HPP 
# define FIXED_HPP
# include <iostream>

class Fixed 
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &other);

		Fixed	&operator=(Fixed const &other);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int 				_rawBits;
		int	const		_dotDelta = 8;
};

#endif