#include <unistd.h>
#include <stdio.h>

//mini atoi
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
void	not_printf(int num)
{
	if (num > 9)
		not_printf(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}
int	prime_desuka(int nb)
{
	int	prime;

	prime = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (prime < nb)
	{
		if (nb % prime == 0)
			return (0);
		prime++;
	}
	return (1);
}
int	main(int argc, char **argv)
{
	int num;
	int sum;
	int i;

	i = 2;
	sum = 0;
	if(argc == 2)
	{
		num = mii_atoi(argv[1]);
		printf("%d\n", num);
		while (i <= num)
		{
			if(prime_desuka(i) == 1)
			{	
				sum = sum + i;
			}
			i++;
		}
		not_printf(sum);
	}
	write(1, "\n", 1);
}