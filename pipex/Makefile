# **************************************************************************** #
# Vars
# **************************************************************************** #

NAME        = pipex

# **************************************************************************** #
# Comp and flags
# **************************************************************************** #
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# LIBFT_DIR   = .././libft/
# LIBFT_DIR   = ./libft/
# LIBFT       = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
# Source
# **************************************************************************** #
SRC_FILES   := main.c
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

$(LIBFT):
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)

clean:
	rm	-f	$(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re:	fclean
