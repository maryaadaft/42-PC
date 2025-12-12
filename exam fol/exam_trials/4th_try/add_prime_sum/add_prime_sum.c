int	smol_atoi(char *str)
{
	int num;
	int i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 - str[i] + '0';
		i++;
	}
	return (num);
}

int	not_printf(int n)
{
	if (n > 9)
		n = n / 10;
	write(1, &"0123456789"[n % 10], 1);
	return (n);
}

int	prime_desuka(int n)
{
	int p = 2;
	while (p < n)
	{
		if (n % p == 0)
		{
			return (0);
		}
		p++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int a_num = smol_atoi(argv[1]);
	int sum;

	if (argc == 2)
	{
			if (prime_desuka(a_num))
			{
				sum += a_num;
			}
	}
}
