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
SRC_FILES			:=	main.c	utils.c	utils2.c
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
# Get_Next_Line
# **************************************************************************** #
SRC_FILES_GNL		:=	get_next_line.c		get_next_line_utils.c
GNL_DIR				=	./get_next_line/
GNLSRC				=	$(addprefix $(GNL_DIR), $(SRC_FILES_GNL))
OBJ_GNL				=	$(GNLSRC:.c=.o)

# **************************************************************************** #
# Bonus	Source
# **************************************************************************** #
BSRC_FILES			:=	main.c	utils.c	utils2.c
BSRC_FILES_DIR		=	./bonus/
BSRC				=	$(addprefix $(BSRC_FILES_DIR), $(BSRC_FILES))
OBJS_BONUS			=	$(BSRC:.c=.o)

# **************************************************************************** #
# Rules
# **************************************************************************** #
.PHONY: all bonus clean fclean re

$(NAME):	$(OBJ_LIBFT) $(OBJS)
			@$(CC) $(OBJ_LIBFT) $(OBJS) -o $(NAME)

all: $(NAME)

# Pipex file compilation
# -I to include the directory where the header files for libft are located
$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

# Libft file compilation
$(OBJ_LIBFT): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Declaring Bonus [Refer to line 51]
$(NAME_BONUS):	$(OBJ_LIBFT)	$(OBJ_GNL) $(OBJS_BONUS)
		@$(CC) $(OBJ_LIBFT) $(OBJ_GNL)	$(OBJS_BONUS) -o $(NAME_BONUS)

# Command to create 'Make bonus'
bonus: $(NAME_BONUS)

# Pipex Bonus file compilation
# -I to include the directory where the header files for libft are located
$(OBJS_BONUS): %.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

# GNL file compilation
$(OBJ_GNL): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm	-f	$(OBJS)
	rm	-f	$(OBJ_LIBFT)
	rm	-f	$(OBJ_GNL)
	rm	-f	$(OBJS_BONUS)


fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
#	@make -C $(LIBFT_DIR) fclean

re:	fclean
