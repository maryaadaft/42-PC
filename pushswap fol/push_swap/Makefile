CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCs = push_swap.c ps_parse.c list_fn.c
OBJs = ${SRCs:.c=.o}
AR = ar rcs
NAME = push_swap

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	(cd libft && make)

$(NAME): $(OBJs) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJs) $(LIBFT)

# $(NAME): $(OBJs) $(LIBFT)
# 	$(AR) $(NAME) $(LIBFT) $(OBJs)

clean:
	(cd libft && make clean)
	rm -rf $(OBJs)
# run clean in libft folder

fclean: clean
	(cd libft && make fclean)
	rm -rf $(NAME)
# run fclean in libft folder

re: fclean all

.PHONY: all clean fclean re