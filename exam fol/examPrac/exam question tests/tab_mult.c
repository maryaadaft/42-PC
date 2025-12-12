#include <unistd.h>

int	mii_atoi(char *str)
{
	int i;
	int num;
	num = 0;

	i = 0;

	while(str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + (str[i] - 48); // minus 48 always
		i++;
	}
	return (num);
}

//putnbr

int	not_printf(int nbr)
{
	if (nbr > 9)
		not_printf(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
	return(nbr);
}

int	main(int argc, char **argv)
{
	int num;
	int i;
	int prod;

	i = 1;
	if (argc == 2)
	{
		num = mii_atoi(argv[1]);
		
		while (i <= 9)
		{
			prod = i * num;
			not_printf(i);
			write(1, " x ", 3);
			not_printf(num);
			write(1, " = ", 3);
			not_printf(prod);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
}