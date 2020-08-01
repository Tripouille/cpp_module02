#!/bin/bash
make
function test
{
	printf "./eval_expr $1\n"
	echo -n "my result = " && ./eval_expr "$1"
	echo -n "bc result = "
	echo "$1" | bc
}
test "(18.18 + 3.03) * 2"
test "(1) + (8 * 2 + 5 - 2 * 10)"
test "(-1 - 10 * ((2 + 5) * 5) + 1)"
test "(-1 - -2) * 5"
test "(-1 - (((-2 + 4 * (5 + 1)) * 2) * 10)* 10) * 10 + 0"
test "(2 * 8 / 9 + 2 - -5) / 5 + 5 * (25 * 2) - 12 * 1"
test "0 + 0"
test "1*3+5/2"
test "1 * 3 + 5 / 2"
test "1*3+5/-2"
test "4 * 2 + 5 * 4"
test "4-2.5*2+4"
test "4 - 2.5 * 2 + 4"
test "5 - +4"
test "5-+4"
test "5 * (-4 + -1 * 2)"
test "5*(-4+-1*2)"
test "(0.225 * 4 + 0.1) / 4.0 + (7.0 * 4 - 20.0)"
test " -1 + 3"
test "-1 - ((((((((3 + 4) * 1 + 5) * 7 + 1) * 2 + 0) * -7 - 1) * 3 - 6) * (-8-1) + 5) + 1)"
test "              -1 + 3        /            -2 "
test "-1 + 3/2 "
test "+1 + 3/2 "
make fclean