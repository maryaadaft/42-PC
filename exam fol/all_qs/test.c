#include <unistd.h>


/* ========= last word ========= */

/*
int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i] != '\0')
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int len = ft_strlen(argv[1]) - 1;
		while(argv[1][len] >= 9 && argv[1][len] <= 13 || argv[1][len] == 32)
			len--;
		while(argv[1][len] > 32 && argv[1][len] < 127)
			len--;
		if (argv[1][len] >= 9 && argv[1][len] <= 13 || argv[1][len] == 32)
			len++;
		while(argv[1][len] > 32 && argv[1][len] < 127)
		{
			write(1, &argv[1][len], 1);
			len++;
		}
	}
	write(1, "\n", 1);

} */


/* ========= fizz buzz ========= */

/* int not_printf(int n)
{
	if (n > 9)
		write(1, &"0123456789"[n / 10], 1);
	write(1, &"0123456789"[n % 10], 1);
	return (n);
}
int	main(void)
{
	int i = 1;
	
	while (i < 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
		write(1, "fizzbuzz\n", 9);
		if ((i % 3 == 0))
		write(1, "fizz\n", 5);
		if ((i % 5 == 0))
		write(1, "buzz\n", 5);
		else
		{
			not_printf(i);
			write(1, "\n", 1);
		}
		i++;
	}
} */

/* ========= ft_rrange ========= */

