CC = cc

CFLAGS = -Wall -Werror -Wextra

SOUR = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_un_nbr.c ft_point.c ft_lower_hex.c ft_upper_hex.c

OBJ = $(SOUR:.c=.o)

AR = ar rcs

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re