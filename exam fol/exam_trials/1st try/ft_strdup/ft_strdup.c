#include <stdlib.h>

char    *ft_strdup(char *src)
{
	int i = 0;
	char *dup;

	while (src[i] != '\0')
		i++;
	dup = malloc((sizeof(char) * i) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while(src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
