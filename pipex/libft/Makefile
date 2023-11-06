
NAME		=	libft.a

#				Files
SRCS		=	ft_strncmp.c		ft_split.c		ft_strjoin.c
OBJS		=	${SRCS:.c=.o}


# *******************************************************************************************************************
#				Rules
# *******************************************************************************************************************

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I includes

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

all:	${NAME}


clean:
	rm -f ${OBJS} $(BONUS_OBJS)

fclean: clean
	rm -f ${NAME}

re: 	fclean all
