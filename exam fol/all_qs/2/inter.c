#include <unistd.h>

int	finding_nemo(char *str, char c)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return(1);
		i++;
	}
	return (0);
}

int	found_him(char *str, char c, int pos)
{
	int i = 0;
	while (i < pos)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		while (argv[1][i])
		{
			if ((finding_nemo(argv[2], argv[1][i]) == 1) && found_him(argv[1], argv[1][i], i) == 0)
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}