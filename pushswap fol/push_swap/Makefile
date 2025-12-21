CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCs = push_swap.c ps_parse.c list_fn.c
OBJs = ${SRCs:.c=.o}
# AR = ar rcs
NAME = push_swap

lib_dir = libfoot
LIBFT = lib_dir/libft.a

all: $LIBFT $(NAME)

$LIBFT:
	make -C libft
$(NAME): $(OBJs)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJs)

clean:
	rm -rf $(OBJs)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re