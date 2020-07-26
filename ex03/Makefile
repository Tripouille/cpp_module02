NAME				= eval_expr
SRCS				= $(addprefix srcs/, main.cpp op.cpp calcul.cpp Fixed.cpp)
INCLUDES			= $(addprefix includes/, Fixed.hpp eval_expr.hpp)
OBJS				= ${SRCS:.cpp=.o}

CC					= clang++
CFLAGS				= -g3 -Wall -Wextra -Werror -I includes

all:				${NAME}

${OBJS}:			${INCLUDES}

.cpp.o:
					${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

${NAME}:			${OBJS}
					${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
					rm -rf ${OBJS}

fclean:				clean
					rm -rf ${NAME}

re:					fclean all

.PHONY:				all clean fclean re
