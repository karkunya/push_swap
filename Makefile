SRCS =	main.c\
 		alg.c\
 		alg_utils.c\
 		operations1.c\
 		operations2p.c\
 		operations3s.c\
 		treeargc.c\
 		operations_utils.c\
 		parse_utils.c\
 		parse_args.c\

OBJS = ${SRCS:.c=.o}

NAME = push_swap
P_HEAD = push_swap.h

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

%.o: %.c
	${CC} ${CFLAGS} -c $< -I ${P_HEAD} -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re