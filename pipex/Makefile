# **************************************************************************** #
# Vars
# **************************************************************************** #

NAME        = pipex
PRINT_NAME  = PIPEX

# **************************************************************************** #
# Comp and flags
# **************************************************************************** #
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# LIBFT_DIR   = .././libft/
LIBFT_DIR   = ./libft/
LIBFT       = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
# Source
# **************************************************************************** #
SRC_FILES   := main.c
OBJS        = $(SRC_FILES:.c=.o)

# **************************************************************************** #
# Rules
# **************************************************************************** #
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

clean:
	rm	-f	$(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re:	fclean all
