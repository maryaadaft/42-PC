#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j = 0;
		int length = ft_strlen(argv[1]);

		while (argv[2][j] && i < length)
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}
		int w = 0;
		if (i == length)
		{
			while(argv[1][w])
			{
				write(1, &argv[1][w], 1);
				w++;
			}
		}
	}
	write(1, "\n", 1);
}

