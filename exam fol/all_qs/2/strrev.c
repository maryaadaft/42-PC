int	ft_strlen(char *str)
{
	int i = 0;

	while(str[i] != '\0')
		i++;
	return (i);
}

char    *ft_strrev(char *str)
{
	int i = ft_strlen(str);
	int f = 0;

	i--;
	char temp;
	while (i > f)
	{
		temp = str[i];
		str[i] = str[f];
		str[f] = temp;
		i--;
		f++;
	}
	return (str);
}

/* #include <stdio.h>
int main(void)
{
	char str[] = "this way forward";
	printf("%s\n", ft_strrev(str));
} */