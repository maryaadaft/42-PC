#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int len = ft_strlen(argv[1]) - 1;
			while ((argv[1][len] >= 9 && argv[1][len] <= 13) || argv[1][len] == 32)
			{
				len--;
			}
			while (argv[1][len] > 32 && argv[1][len] < 127) 
			{
				len--;
			}
			if ((argv[1][len] >= 9 && argv[1][len] <= 13) || argv[1][len] == 32)
				len++;
			while (argv[1][len] > 32 && argv[1][len] < 127)
			{
				write(1, &argv[1][len], 1);
				len++;
			}
		}
	write(1, "\n", 1);
}
	
