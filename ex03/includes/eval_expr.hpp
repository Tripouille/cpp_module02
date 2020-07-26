#ifndef EVAL_EXPR_HPP
# define EVAL_EXPR_HPP
# include <string>
# include <iostream>
# include <sstream>
# include <math.h>
# include "Fixed.hpp"

typedef std::string		(*fct)(Fixed, Fixed);

int				get_op_pos(std::string str, unsigned long s, char op);
std::string		do_add(Fixed one, Fixed two);
std::string		do_sub(Fixed one, Fixed two);
std::string		do_mul(Fixed one, Fixed two);
std::string		do_div(Fixed one, Fixed two);

void			calcul(std::stringstream &ss, unsigned long s, unsigned long e);
unsigned long	calcul_start(std::string str, unsigned long s, unsigned long op_pos);
unsigned long	calcul_end(std::string str, unsigned long s, unsigned long op_pos);
void			calcul_expression(std::stringstream &ss, unsigned long s);

#endif