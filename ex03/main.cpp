#include <string>
#include <iostream>
#include <sstream>

void		calcul(std::stringstream &ss, unsigned long s, unsigned long e)
{
	float		one, two;
	char		op;
	std::cout << "s = " << s << " e = " << e << std::endl;
	ss.seekg(s + 1);
	ss >> one >> op >> two;
	std::cout << "one " << one << " op = " << op << " two = " << two << std::endl;
	std::string result = std::to_string(one * two);
	ss.str(ss.str().replace(s + 1, e - s - 1, result));
	std::cout << "r = " << ss.str() << std::endl;
}

unsigned long	calcul_start(std::string str, unsigned long s, unsigned long op_pos)
{
	unsigned long start = op_pos - 1;

	if (s == 0)
		return (0);
	while (start > s && std::string(" +-*/").find(str[start], 0) == std::string::npos)
		start--;
	return (start);
}

unsigned long	calcul_end(std::string str, unsigned long e, unsigned long op_pos)
{
	unsigned long end = op_pos + 1;

	if (str.size() < e)
		e = str.size();
	while (end < e && std::string(" +-*/").find(str[end], 0) == std::string::npos)
		end++;
	return (end);
}


void		calcul_parenthese(std::stringstream &ss, unsigned long s)
{
	unsigned long		op_pos, e;

	while ((op_pos = ss.str().find('*', s + 1)) != std::string::npos)
	{
		std::cout << "do multi" << std::endl;
		e = ss.str().find(')', s + 1);
		calcul(ss, calcul_start(ss.str(), s, op_pos), calcul_end(ss.str(), e, op_pos));
	}
	/*while ((op_pos = ss.str().find('/', s + 1)) != std::string::npos)
	{
		std::cout << "do div" << std::endl;
		e = ss.str().find(')', s + 1);
		calcul(ss, calcul_start(ss.str(), s, op_pos), calcul_end(ss.str(), e, op_pos));
	}
	while ((op_pos = ss.str().find('+', s + 1)) != std::string::npos)
	{
		std::cout << "do +" << std::endl;
		e = ss.str().find(')', s + 1);
		calcul(ss, calcul_start(ss.str(), s, op_pos), calcul_end(ss.str(), e, op_pos));
	}
	while ((op_pos = ss.str().find('-', s + 1)) != std::string::npos)
	{
		std::cout << "do -" << std::endl;
		e = ss.str().find(')', s + 1);
		calcul(ss, calcul_start(ss.str(), s, op_pos), calcul_end(ss.str(), e, op_pos));
	}*/
	ss.str(ss.str().substr(1, ss.str().find(')', s + 1) - 1));
}

void		parse_parentheses(std::stringstream &ss, int s)
{
	if (ss.str().find('(', s + 1) != std::string::npos)
		parse_parentheses(ss, ss.str().find('(', s + 1));
	if (ss.str()[s] == '(' && ss.str().find(')', s + 1) == std::string::npos)
	{
		std::cerr << "ERROR: missing )" << std::endl;
		exit (-1);
	}
	calcul_parenthese(ss, s);
}

int		main (int ac, char **av)
{
	std::stringstream	ss;

	if (ac != 2)
		return (-1);
	ss << av[1];
	parse_parentheses(ss, ss.str().find('(', 0));
	std::cout << ss.str() << std::endl;
	return 0;
}