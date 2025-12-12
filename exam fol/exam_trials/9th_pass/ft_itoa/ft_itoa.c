#include <unistd.h>
#include <stdlib.h>

int	diggy(long n)
{
	int count;

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
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	// long n = (long)nbr;
	int len = diggy(nbr);
	char *not_word = malloc(len + 1);
	if (!not_word)
		return (NULL);

	not_word[len] = '\0';
	if (nbr == 0)
	{
		not_word[0] = '0';
		return (not_word);
	}
	if (nbr < 0)
	{
		not_word[0] = '-';
		nbr = nbr * -1;
	}
	len--;
	while (nbr > 0)
	{
		not_word[len] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (not_word);
}

// #include <stdio.h>
// int main(void)
// {

// 	char *str = ft_itoa(16);
// 	printf("%s\n", str);
// }
