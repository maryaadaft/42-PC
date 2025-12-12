#include <unistd.h>

int	not_printf(int nbr)
{
	if (nbr > 9)
		not_printf(nbr / 10);
	write(1, &"0123456789"[nbr % 10], 1);
	return(nbr);
}

int	main(int argc, char **argv)
{
	int i;
	int num;

	i = 0;
	if (argc > 1)
	{
		while (i < (argc - 1))
		{
			i++;
		}
		not_printf(i);
	}
}