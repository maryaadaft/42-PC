#include <unistd.h>
char    *ft_strrev(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		i++;
	}
	j = i - 1;
	i = 0;
	while (i < j)
	{
		char temp;
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return(str);
}

#include <stdio.h>
int main (void)
{
	char str[] = "Salama";
	printf("%s", ft_strrev(str));
}