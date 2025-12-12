#include <unistd.h>

int	not_printf(nb)
{
	if (nb > 9)
		not_printf(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	return (nb);
}

int	mini_atoi(char *str)
{
	int i = 0;
	int num = 0;

	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num  *10 + str[i] - 48;
		i++;
	}
	return (num);
}


int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		int nb = mini_atoi(argv[1]);
		int multi;
		while (i <= 9)
		{
			not_printf(i);
			write(1, " x ", 3);
			not_printf(nb);
			write(1, " = ", 3);
			multi = i * nb;
			not_printf(multi);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);

}