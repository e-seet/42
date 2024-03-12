NAME        = fract-ol
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
SRCS        = main.c utils.c
OBJS        = $(SRCS:.c=.o)
LIBFT_DIR   = ../libft/
LIBFTSRC    = $(addprefix $(LIBFT_DIR), $(SRC_FILESLIBFT))
OBJ_LIBFT   = $(LIBFTSRC:.c=.o)

$(NAME): $(OBJ_LIBFT) $(OBJS)
	$(CC) $(OBJ_LIBFT) $(OBJS) -Lminilibxopengl -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I minilibxopengl -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS) $(OBJ_LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
