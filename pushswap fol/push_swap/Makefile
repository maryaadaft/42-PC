CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCs = push_swap.c ps_parse.c list_fn.c
OBJs = ${SRCs:.c=.o}
AR = ar rcs
NAME = push_swap


LIBFT = libfoot/libft.a

all: $(NAME)

$(LIBFT):
	make -C libfoot

# $(NAME): $(OBJs) $(LIBFT)
# 	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJs)

$(NAME): $(OBJs) $(LIBFT)
	$(AR) $(NAME) $(LIBFT)$(OBJs)

clean:
	rm -rf $(OBJs)
# run clean in libft folder
	make clean -C libfoot
fclean: clean
	rm -rf $(NAME)
# run fclean in libft folder
	make fclean -C libfoot

re: fclean all

.PHONY: all clean fclean re