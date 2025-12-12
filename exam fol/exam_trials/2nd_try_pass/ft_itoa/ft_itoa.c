#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	digging(long nbr)
{
	int count = 0;

	if (nbr == 0)
	{
		count = 1;
		return (count);
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
		count = 1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int len = digging(nbr);
	char *num_str = malloc((len + 1));
	if (!num_str)
		return (NULL);
	num_str[len] = '\0';
	if (nbr == 0)
	{
		num_str[0] = '0';
		return (num_str);
	}
	if (nbr < 0)
	{
		num_str[0] = '-';
		nbr = nbr * -1;
	}
	len--;
	while (nbr > 0)
	{
		num_str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (num_str);
}


// int	main(void)
// {
// 	// int res = digging(-123);
// 	// printf("%d\n", res);

// 	char *res2 = ft_itoa(0);
// 	printf("%s\n", res2);
	
// }