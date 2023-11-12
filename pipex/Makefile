# **************************************************************************** #
# Vars
# **************************************************************************** #

NAME        = pipex
NAME_BONUS	= pipex_bonus

# **************************************************************************** #
# Comp and flags
# **************************************************************************** #
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# **************************************************************************** #
# Source
# **************************************************************************** #
SRC_FILES			:=	main.c	utils.c
OBJS				=	$(SRC_FILES:.c=.o)

SRC_FILESLIBFT		:=	ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		ft_isascii.c		ft_isprint.c		\
						ft_strlen.c				ft_memset.c			ft_bzero.c			ft_memcpy.c			ft_memmove.c		\
						ft_strlcpy.c			ft_strlcat.c		ft_tolower.c		ft_toupper.c		ft_strchr.c			\
						ft_strrchr.c			ft_strncmp.c 		ft_memchr.c			ft_memcmp.c			ft_strnstr.c		\
						ft_atoi.c				ft_calloc.c			ft_strdup.c			ft_substr.c			ft_strjoin.c		\
						ft_strtrim.c			ft_split.c			ft_itoa.c			ft_strmapi.c		ft_striteri.c		\
						ft_putchar_fd.c			ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c# **************************************************************************** #

# **************************************************************************** #
# Libft
# **************************************************************************** #

LIBFT_DIR			=	../libft/
LIBFTSRC			=	$(addprefix $(LIBFT_DIR), $(SRC_FILESLIBFT))
OBJ_L				=	$(LIBFTSRC:.c=.o)

# **************************************************************************** #
# Get_Next_Line
# **************************************************************************** #


# **************************************************************************** #
# Bonus	Source
# **************************************************************************** #
BSRC_FILES			:=	main.c	utils.c
BSRC_FILES_DIR		=	$(addprefix bonus/, $(BSRC_FILES))
OBJS_BONUS			=	$(BSRC_FILES_DIR:.c=.o)



# **************************************************************************** #
# Rules
# **************************************************************************** #
.PHONY: all clean fclean re

$(NAME):	$(OBJ_L) $(OBJS)
			@$(CC) $(OBJ_L) $(OBJS) -o $(NAME)

all: $(NAME)

# Pipex file
$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

# Libft
$(OBJ_L): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Declaring Bonus
$(NAME_BONUS):	$(OBJ_L) $(OBJS_BONUS)
		@$(CC) $(OBJ_L) $(OBJS_BONUS) -o $(NAME_BONUS)

# Command to create 'Make bonus'
bonus: $(NAME_BONUS)

$(OBJS_BONUS): %.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

clean:
	rm	-f	$(OBJS)
	rm	-f	$(OBJ_L)
#	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
#	@make -C $(LIBFT_DIR) fclean

re:	fclean
