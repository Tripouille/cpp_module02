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
make fclean