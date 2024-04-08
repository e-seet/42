
# # **************************************************************************** #
# # Vars
# # **************************************************************************** #
NAME        = fract-ol

# # **************************************************************************** #
# # Comp and flags
# # **************************************************************************** #
CC := cc
CFLAGS := -Wall -Wextra -Werror

# # **************************************************************************** #
# # Source
# # **************************************************************************** #
SRC_FILES			:=	main.c	utils/utils.c	utils/utils2.c	utils/utils3.c	utils/calculations.c	utils/eventhandler.c	utils/bonus.c
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

# # **************************************************************************** #
# # Rules
# # **************************************************************************** #
.PHONY: all bonus clean fclean re

#$(NAME):	$(OBJ_LIBFT) $(OBJS)
#			@$(CC) $(OBJ_LIBFT) $(OBJS) -Lminilibxopengl -lmlx -framework OpenGL -framework AppKit -o $(NAME)

#all: $(NAME)
#$(OBJS): %.o: %.c
#	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I minilibxopengl -I/opt/X11/include -L/opt/X11/lib -lX11 -c $< -o $@

# Working!: This is for Macos
#$(NAME):	$(OBJ_LIBFT) $(OBJS)
#			@$(CC) $(OBJ_LIBFT) $(OBJS) -Lminilibxopengl -lmlx -L/opt/X11/lib -lX11 -framework OpenGL -framework AppKit -o $(NAME)

# UBUNTU Version!
$(NAME):	$(OBJ_LIBFT) $(OBJS)
			@$(CC) $(OBJ_LIBFT)	$(OBJS) -Lmlx_linux -lmlx_Linux -L/opt/X11/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


all: $(NAME)
$(OBJS): %.o: %.c
#ubuntu
#	@$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I minilibxopengl -I/opt/X11/include -c $< -o $@
	@$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@



# Libft file compilation
$(OBJ_LIBFT): %.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm	-f	$(OBJS)
	rm	-f	$(OBJ_LIBFT)


fclean: clean
	rm -f $(NAME)

re:	fclean all




# NAME        = fract-ol
# CC          = gcc
# CFLAGS      = -Wall -Wextra -Werror
# SRCS        = main.c utils.c
# OBJS        = $(SRCS:.c=.o)
# LIBFT_DIR   = ../libft/
# LIBFTSRC    = $(addprefix $(LIBFT_DIR), $(SRC_FILESLIBFT))
# OBJ_LIBFT   = $(LIBFTSRC:.c=.o)

# $(NAME): $(OBJ_LIBFT) $(OBJS)
# 	@$(CC) $(OBJ_LIBFT) $(OBJS) -Lminilibxopengl -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I minilibxopengl -c $< -o $@

# all: $(NAME)

# clean:
# 	rm -f $(OBJS) $(OBJ_LIBFT)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re
