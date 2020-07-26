#include "eval_expr.hpp"

void		parse_parentheses(std::stringstream &ss, int s)
{
	if (ss.str().find('(', s + 1) != std::string::npos)
		parse_parentheses(ss, ss.str().find('(', s + 1));
	if (ss.str()[s] == '(' && ss.str().find(')', s + 1) == std::string::npos)
	{
		std::cerr << "ERROR: missing )" << std::endl;
		exit (-1);
	}
	calcul_expression(ss, s);
}

int		main (int ac, char **av)
{
	std::stringstream	ss;
	float				result;

	if (ac != 2)
		return (-1);
	ss << av[1];
	parse_parentheses(ss, 0);
	calcul_expression(ss, 0);
	ss.seekg(0);
	ss >> result;
	std::cout << result << std::endl;
	return 0;
}