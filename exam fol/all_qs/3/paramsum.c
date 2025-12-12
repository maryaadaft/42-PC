#include <unistd.h>
int	not_printf(int nb)
{
	if (nb > 9)
		not_printf(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	return (nb);
}

int main(int argc, char **argv)
{
	(void)argv;

	if (argc > 1)
	{
		int i = 0;
		while (i < (argc - 1))
		{
			i++;
		}
		not_printf(i);
		write(1, "\n", 1);
	}
	else
		write(1, "1\n", 2);
}