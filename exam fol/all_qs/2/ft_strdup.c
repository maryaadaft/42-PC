#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	int i = 0;

	int len = ft_strlen(src);
	char *dest = malloc(len + 1);

	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* #include <stdio.h>
int main(void)
{
	char src[] = "hi hi";
	char *dest;
	dest = ft_strdup(src);
	printf("%s\n", dest);
}
 */