#include "Fixed.hpp"

int main(void)
{
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "min " << min(a, b) << std::endl;
	std::cout << "max " << max(a, b) << std::endl;

	Fixed	tab[2] = {Fixed(42.0f), Fixed(21.0f)};
	std::cout << "min: " << min(*tab) << std::endl;
	std::cout << "max: " << max(*tab) << std::endl;
	Fixed c = max(*tab);
	c++;
	std::cout << c << std::endl;
	return 0;
}