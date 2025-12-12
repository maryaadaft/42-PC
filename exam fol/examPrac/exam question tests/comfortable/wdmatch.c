#include <unistd.h>
//get length for the 1st str and increment argv[2] based off of the length of argv[1]
int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	int w;
	int len;
	// leave var value inside if statements
	if (argc == 3)
	{
		len = ft_strlen(argv[1]);
		i = 0;
		j = 0;
		while((argv[2][j] != '\0') && i < len)
		{
			if (argv[1][i] == argv[2][j])
			{
				i++;
			}
			j++;
		}
// print out the 1st string once i reaches the length of the 1st arg
		w = 0;
		if (i == len)
		{
			while(argv[1][w] != '\0')
			{
				write(1, &argv[1][w], 1);
				w++;
			}
		}
	}
	write(1, "\n", 1);
}