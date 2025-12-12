int	ft_atoi(const char *str)
{
	int i;
	int sign = 1;
	int numb = 0;
	i = 0;

	while (str[i] <= 32)
	{
		i++;
	}
	//somehow this works, and somehow this is not a while loop and somehow its stupid why
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
				//proceed as normal
	while (str[i] >= 48 && str[i] <= 57)
	{
		numb = (numb * 10) + str[i] - 48;
		i++;
	}
	return (numb * sign);
} 

#include <stdio.h>
#include <stdlib.h>
int	main(void)                                                                                                                                                                                                                                                                                                                                                                              
{
	// char str[] = "   --++--+1234ah223";

	printf("%d", ft_atoi("   --++--+1234ah223"));
	printf("\n%d\n\n", atoi("   --++--+1234ah223"));

	printf("%d", ft_atoi("012kjh"));
	printf("\n%d\n\n", atoi("012kjh"));

	printf("%d\n", ft_atoi("    +211  34asda "));
	printf("%d\n\n", atoi("    +211  34asda "));
	
	printf("%d\n", ft_atoi("++231s"));
	printf("%d\n\n", atoi("++231s"));

	printf("%d\n", ft_atoi("     --234  asldj"));
	printf("%d\n\n", atoi("     --234  asldj"));

	printf("%d\n", ft_atoi("   -456"));
	printf("%d\n\n", atoi("   -456"));

	printf("%d\n", ft_atoi("     -+234  asldj"));
	printf("%d\n\n", atoi("     -+234  asldj"));

	printf("%d\n", ft_atoi("sldj"));
	printf("%d\n\n", atoi("asldj"));
}