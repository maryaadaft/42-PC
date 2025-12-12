#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int r;
	char *str = (char*)s;

	while(str[i] != '\0')
	{
		r = 0;
		while (reject[r] != '\0')
		{
			if (str[i] == reject[r])
			{
				return (i);
			}
			r++;
		}
		i++;
	}
	return (i);
}

/* #include <stdio.h>
int	main(void)
{
	char str[] = "hi! I'm Mii, and you?";
	char rej[] = "!',?";

	printf("%zu\n", ft_strcspn(str, rej));
	
} */