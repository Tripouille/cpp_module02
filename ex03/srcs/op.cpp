#include "eval_expr.hpp"

int			get_op_pos(std::string str, unsigned long s, char op)
{
	unsigned long		i;
	unsigned long end = str.find(')', s);

	if (end > str.size())
		end = str.size();
	for (i = s; i < end; i++)
		if (str[i] == op)
			for (int r = i - 1; i > s && std::string("/*-+").find(str[r], 0) == std::string::npos; r--)
				if (isdigit(str[r]))
					return (i);
	return (-1);
}

std::string		do_add(Fixed one, Fixed two)
{
	return (std::to_string((one + two).toFloat()));
}

std::string		do_sub(Fixed one, Fixed two)
{
	return (std::to_string((one - two).toFloat()));
}

std::string		do_mul(Fixed one, Fixed two)
{
	return (std::to_string((one * two).toFloat()));
}

std::string		do_div(Fixed one, Fixed two)
{
	return (std::to_string((one / two).toFloat()));
}
