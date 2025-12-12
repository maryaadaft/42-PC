#include <unistd.h>

int	ft_atoi(const char *str)
{
	int i = 0;
	int num = 0;
	int sign = 1;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while(str[i] >= 48 && str[i] <= 57)
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n", ft_atoi("-123"));
// }