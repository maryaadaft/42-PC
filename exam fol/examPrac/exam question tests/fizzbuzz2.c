#include <unistd.h>

void	not_printf(int n)
	{
		if (n > 9)
			not_printf(n / 10);
		write(1, &"0123456789"[n % 10], 1);
	}

int	main(void)
{
	int i;

	i = 1;

	while (i < 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			write(1, "fizzbuzz\n", 9);
		}
		else if (i % 3 == 0)
		{
			write(1, "fizz\n", 5);
		}
		else if (i % 5 == 0)
		{
			write(1, "buzz\n", 5);
		}
		else
		{
			not_printf(i);
			write(1, "\n", 1);
		}
		i++;
	}
}
