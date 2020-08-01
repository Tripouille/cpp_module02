#include "eval_expr.hpp"

void		calcul(std::stringstream &ss, unsigned long s, unsigned long e)
{
	float		one, two;
	char		op;
	std::string	result;
	std::pair<char, fct> tab[4] = {
		make_pair('+', &do_add),
		make_pair('-', &do_sub),
		make_pair('*', &do_mul),
		make_pair('/', &do_div)
	};
	ss.seekg(s);
	ss >> one >> op >> two;
	for (int i = 0; i < 4; i++)
		if (tab[i].first == op)
			result = tab[i].second(Fixed(one), Fixed(two));
	ss.str(ss.str().replace(s, e - s + 1, result));
}

unsigned long	calcul_start(std::string str, unsigned long s, unsigned long op_pos)
{
	unsigned long	start = op_pos - 1;

	while (start > s && !isdigit(str[start]))
		start--;
	while (start > s && std::string(" /*-+").find(str[start]) == std::string::npos)
		start--;
	if (str[start] == ' ')
		while (start > s && str[start - 1] == ' ')
			start--;
	return (start == s ? start : start + 1);
}

unsigned long	calcul_end(std::string str, unsigned long s, unsigned long op_pos)
{
	unsigned long end = str.find(')', s);
	unsigned long cend = op_pos + 1;

	if (end > str.size())
		end = str.size();
	while (cend < end && !isdigit(str[cend]))
		cend++;
	while (cend < end && str[cend] && std::string(" /*-+").find(str[cend]) == std::string::npos)
		cend++;
	return (cend - 1);
}

void		calcul_expression(std::stringstream &ss, unsigned long s)
{
	int					op_pos;
	int					tmp;
	unsigned			start = ss.str()[s] == '(' ? s + 1 : s;

	do
	{
		op_pos = get_op_pos(ss.str(), start, '*');
		tmp = get_op_pos(ss.str(), start, '/');
		if ((tmp != -1 && tmp < op_pos) || op_pos == -1)
			op_pos = tmp;
		if (op_pos == -1)
		{
			op_pos = get_op_pos(ss.str(), start, '+');
			tmp = get_op_pos(ss.str(), start, '-');
			if ((tmp != -1 && tmp < op_pos) || op_pos == -1)
				op_pos = tmp;
		}
		if (op_pos != -1)
			calcul(ss, calcul_start(ss.str(), start, op_pos), calcul_end(ss.str(), start, op_pos));
	} while (op_pos != -1);
	if (ss.str()[s] == '(')
	{
		ss.str(ss.str().erase(s, 1));
		ss.str(ss.str().erase(ss.str().find(')', s), 1));
	}
}
