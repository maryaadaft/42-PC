#include <stdlib.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int i = 0;

	while(s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// char *str1 = "helloooo";
// 	char *cpy = NULL;
// 	char *res = ft_strcpy("potato potato", cpy);


// 	printf("%s\n", res);
// }
