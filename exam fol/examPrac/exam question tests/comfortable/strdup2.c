#include <stdlib.h>

char *ft_strdup(char *src)
{
	int i;
	i = 0;
	char *dest;

	while (src[i] != '\0')
	{
		i++;
	}
	
	dest = malloc(sizeof(char) * i + 1);
	if (dest == NULL)
		return NULL;

	while (dest[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(void)
{
	char src[] = "lock me up and throw away the key";
	char *dest;
	dest = ft_strdup(dest);
	printf("%s", dest);
	free (dest);
}
