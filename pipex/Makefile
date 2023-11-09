# **************************************************************************** #
# Vars
# **************************************************************************** #

NAME        = pipex

# **************************************************************************** #
# Comp and flags
# **************************************************************************** #
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# **************************************************************************** #
# Source
# **************************************************************************** #
SRC_FILES   := main.c	utils.c
OBJS        = $(SRC_FILES:.c=.o)

SRC_FILESL  := ft_split.c ft_strjoin.c ft_strncmp.c	ft_strlen.c
LIBFT_DIR   = libft/
LIBFTSRC	= $(addprefix $(LIBFT_DIR), $(SRC_FILESL))
OBJ_L	   	= $(LIBFTSRC:.c=.o)

# **************************************************************************** #
# Rules
# **************************************************************************** #
.PHONY: all clean fclean re

$(NAME):	$(OBJ_L) $(OBJS)
			@$(CC) $(OBJ_L) $(OBJS) -o $(NAME)

all: $(NAME)

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

$(OBJ_L): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	
# $(LIBFT):
# 	@make -C $(LIBFT_DIR)
# 	@cp $(LIBFT) $(NAME)

clean:
	rm	-f	$(OBJS)
	rm	-f	$(OBJ_L)
#	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
#	@make -C $(LIBFT_DIR) fclean

re:	fclean
