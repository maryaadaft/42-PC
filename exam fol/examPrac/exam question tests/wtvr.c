int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int num;
	i = 0;
	num = 0;
	sign = 1;
	while (str[i] <= 32)
	{
		i++;
	}
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num * sign);
}
#include <stdio.h>
int main ()
{
	char str[] = "   -12";
	printf("%d", ft_atoi(str));

}