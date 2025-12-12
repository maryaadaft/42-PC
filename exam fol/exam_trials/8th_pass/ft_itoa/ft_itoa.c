#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int count_num(long n)
{
	int count = 0;
	if (n == 0)
	{
		count = 1;
		return (count);
	}
	if (n < 0)
	{
		count = 1;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	long num = (long)nbr;
	int len = count_num(num);
	char *streeng = malloc(len + 1);
	if (!streeng)
		return (NULL);
	streeng[len] = '\0';
	if (num == 0)
	{
		streeng[0] = '0';
		return (streeng);
	}
	if (num < 0)
	{
		streeng[0] = '-';
		num = num * -1;
	}
	len--;
	while (num > 0)
	{
		streeng[len] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return(streeng);
}


// int main(void)
// {
// 	// printf(("%d\n"), count_num(-123));

// 	printf("%s\n", ft_itoa(123));

// }