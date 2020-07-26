#!/bin/bash
make
function test
{
	printf "./eval_expr $1\n"
	echo -n "RESULT = " && ./eval_expr "$1"
}
test "(18.18 + 3.03) * 2"
test "(1) + (8 * 2 + 5 - 2 * 10)"
test "(-1 - 10 * ((2 + 5) * 5) + 1)"
test "(-1 - -2) * 5"
make fclean