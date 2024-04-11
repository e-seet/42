# **************************************************************************** #
# Vars
# **************************************************************************** #
NAME        = philo

# **************************************************************************** #
# Comp and flags
# **************************************************************************** #
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# **************************************************************************** #
# Source
# **************************************************************************** #
SRC_FILES			:=	main.c	utils/thread.c	utils/sleeping.c	utils/eating.c utils/thinking.c utils/utils.c
OBJS				=	$(SRC_FILES:.c=.o)

# **************************************************************************** #
# Libft
# **************************************************************************** #
SRC_FILESLIBFT		:=	ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		ft_isascii.c		ft_isprint.c		\
						ft_strlen.c				ft_memset.c			ft_bzero.c			ft_memcpy.c			ft_memmove.c		\
						ft_strlcpy.c			ft_strlcat.c		ft_tolower.c		ft_toupper.c		ft_strchr.c			\
						ft_strrchr.c			ft_strncmp.c 		ft_memchr.c			ft_memcmp.c			ft_strnstr.c		\
						ft_atoi.c				ft_calloc.c			ft_strdup.c			ft_substr.c			ft_strjoin.c		\
						ft_strtrim.c			ft_split.c			ft_itoa.c			ft_strmapi.c		ft_striteri.c		\
						ft_putchar_fd.c			ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c

LIBFT_DIR			=	../libft/
LIBFTSRC			=	$(addprefix $(LIBFT_DIR), $(SRC_FILESLIBFT))
OBJ_LIBFT				=	$(LIBFTSRC:.c=.o)


# **************************************************************************** #
# Rules
# **************************************************************************** #
.PHONY: all bonus clean fclean re

$(NAME):	$(OBJ_LIBFT) $(OBJS)
			@$(CC) $(OBJ_LIBFT) $(OBJS) -o $(NAME)

all: $(NAME)

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

# Libft file compilation
$(OBJ_LIBFT): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm	-f	$(OBJS)
	rm	-f	$(OBJ_LIBFT)


fclean: clean
	rm -f $(NAME)

re:	fclean
