#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{

		int r = ft_strlen(argv[1]) - 1;
		
		while (r >= 0)
		{
			write(1, &argv[1][r], 1);
			r--;
		}
	}
	write(1, "\n", 1);
}


