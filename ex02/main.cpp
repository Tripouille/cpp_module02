#include "Fixed.hpp"

int main(void)
{
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));
	Fixed	c(b * b + a - b / a);

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "min " << Fixed::min(a, b) << std::endl;
	std::cout << "max " << Fixed::max(a, b) << std::endl;
	
	Fixed	u(10), i(10);
	std::cout << u.toInt() << " / " << i.toInt() << " = " << u / i <<std::endl;
	std::cout << u.toInt() << " - " << i.toInt() << " = " << u - i <<std::endl;
	std::cout << u.toInt() << " + " << i.toInt() << " = " << u + i <<std::endl;
	std::cout << u.toInt() << " == " << i.toInt() << " = " << (u == i) << std::endl;
	std::cout << u.toInt() << " != " << i.toInt() << " = " << (u != i) << std::endl;
	std::cout << u.toInt() << " > " << i.toInt() << " = " << (u > i) << std::endl;
	std::cout << u.toInt() << " >= " << i.toInt() << " = " << (u >= i) << std::endl;
	std::cout << u.toInt() << " < " << i.toInt() << " = " << (u < i) << std::endl;
	std::cout << u.toInt() << " <= " << i.toInt() << " = " << (u <= i) << std::endl;
	std::cout << u << " u-- " << u-- << std::endl;
	std::cout << u << " --u " << --u << std::endl;

	return 0;
}