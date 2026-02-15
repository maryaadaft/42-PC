CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCs = ps_main.c ps_parse.c list_fn.c ps_error.c ps_op1.c ps_op2.c ps_op3.c ps_op4.c mylib/to_num.c mylib/ft_isdigit.c mylib/ft_split.c mylib/ft_strlen.c mylib/ft_substr.c sort_three.c ps_sort_utils.c ps_sort.c
OBJs = ${SRCs:.c=.o}
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJs)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJs)

clean:
	rm -rf $(OBJs)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re