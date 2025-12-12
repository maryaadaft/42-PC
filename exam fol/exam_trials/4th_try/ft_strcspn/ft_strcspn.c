#include <stdlib.h>
#include <stdio.h>

// int	finding_nemo(char *str, char c)
// {
// 	int i = 0;

// 	while (str[i] != '\0')
// 	{
// 		if (c == str[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j;
	char *str = (char *)s;
	
	while (str[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (str[i] == reject[j])
					return (i);
			j++;
		}
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	char str[] = "what!the hecker";
// 	char look4[] = "! ";

// 	printf("%zu\n", ft_strcspn(str, look4));
// }