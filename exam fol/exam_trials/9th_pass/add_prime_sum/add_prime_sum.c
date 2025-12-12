#include <unistd.h>
#include <stdio.h>

int	not_printf(int n)
{
	if (n > 9)
		write(1, &"0123456789"[n / 10], 1);
	write(1, &"0123456789"[n % 10], 1);
	return (n);
}

int prime_desuka(int num)
{
	int prime = 2;
	while (prime < num)
	{
		if ((num % prime == 0))
		{
			return (0);
		}
		prime++;
	}
	return 1;
}

int mini_atoi(char *str)
{
	int i = 0;
	int numb = 0;

	while (str[i] >= 48 && str[i] <= 57)
	{
		numb = (numb * 10) + str[i] - 48;
		i++;
	}
	return (numb);
}

#include <stdio.h>
int	main(int argc, char **argv)
{
	int sum = 0;
	// printf("%d\n", arg_numb);
	
	if (argc == 2)
	{
		int check = 2;
		int arg_numb = mini_atoi(argv[1]);
		while (check <= arg_numb)
		{
			if ((prime_desuka(check) == 1))
			{
				sum += check;
			}
			// printf("check is currently: %d\n sum is currently: %d\n", check, sum);
			check++;
		}
		not_printf(sum);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);

}