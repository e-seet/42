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
SRC_FILES			:=	main.c	utils.c
OBJS				=	$(SRC_FILES:.c=.o)

SRC_FILESLIBFT		:=	ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		ft_isascii.c		ft_isprint.c		\
						ft_strlen.c				ft_memset.c			ft_bzero.c			ft_memcpy.c			ft_memmove.c		\
						ft_strlcpy.c			ft_strlcat.c		ft_tolower.c		ft_toupper.c		ft_strchr.c			\
						ft_strrchr.c			ft_strncmp.c 		ft_memchr.c			ft_memcmp.c			ft_strnstr.c		\
						ft_atoi.c				ft_calloc.c			ft_strdup.c			ft_substr.c			ft_strjoin.c		\
						ft_strtrim.c			ft_split.c			ft_itoa.c			ft_strmapi.c		ft_striteri.c		\
						ft_putchar_fd.c			ft_putstr_fd.c		ft_putendl_fd.c		ft_putnbr_fd.c

LIBFT_DIR			=	../libft/
LIBFTSRC			=	$(addprefix $(LIBFT_DIR), $(SRC_FILESLIBFT))
OBJ_L				=	$(LIBFTSRC:.c=.o)

# **************************************************************************** #
# Bonus	Source
# **************************************************************************** #
# BSRC_FILES  := main.c	utils.c
# OBJS_BONUS  = $(BSRC_FILES:.c=.o)

# BSRC_FILESL	:=	ft_split.c ft_strjoin.c ft_strncmp.c	ft_strlen.c



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

bonus:


clean:
	rm	-f	$(OBJS)
	rm	-f	$(OBJ_L)
#	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
#	@make -C $(LIBFT_DIR) fclean

re:	fclean
