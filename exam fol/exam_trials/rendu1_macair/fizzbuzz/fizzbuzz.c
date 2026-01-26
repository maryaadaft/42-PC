#include <unistd.h>

int not_printf(int nb)
{
    if (nb > 9)
		write(1, &"0123456789"[nb / 10], 1);
	write(1, &"0123456789"[nb % 10], 1);
	return (nb);
}

int main(void)
{
	int i = 1;

	while (i <= 100)
	{
		if ((i % 3 == 0) && (i % 5 == 0))
			write(1, "fizzbuzz\n", 9);
		else if ((i % 3 == 0))
			write(1, "fizz\n", 5);
		else if ((i % 5 == 0))
			write(1, "buzz\n", 5);
		else
		{
			not_printf(i);
			write(1, "\n", 1);
		}
		i++;
	}
}