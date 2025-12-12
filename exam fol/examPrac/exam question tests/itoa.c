#include <stdlib.h>
#include <stdio.h>

int	count_dracula(int nbr)
{
	int count;
	count = 0;
	if (nbr <= 0)
	{
		count = 1;
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int i;

	i = 0;
	int size;
	char *abdu_the_kiddo;

	size = count_dracula(nbr);
	abdu_the_kiddo = malloc(sizeof(char) * (size + 1));

	if (abdu_the_kiddo == NULL)
		return NULL;
	if (nbr == 0)
	{
		abdu_the_kiddo[0] = '0';
		return (abdu_the_kiddo);
	}
	else if (nbr < 0)
	{
		abdu_the_kiddo[0] = '-';
		nbr = -nbr;
	}
	abdu_the_kiddo[size] = '\0';
	printf(" the size is : %d\n", size);
	printf(" the number is : %d\n", nbr);
	size--;
	while (nbr > 0)
	{
		abdu_the_kiddo[size] = nbr % 10 + '0';
		// printf("this is index %d and this is the value: %d\n\n", size, abdu_the_kiddo[size]);
		// printf("%d\n", abdu_the_kiddo[size - 1]);
		size--;
		nbr = nbr / 10;
	}
	return (abdu_the_kiddo);
}

int	main(void)
{
	int i = 0;
	char *str;
	str = ft_itoa(0);
	printf("%s", str);
}