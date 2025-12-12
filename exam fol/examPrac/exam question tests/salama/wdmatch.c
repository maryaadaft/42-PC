#include <unistd.h>

int ft_strlen(char *str)
{
	int len;
	len = 0;
	while(str[len])
	{
		len++;
	}
	return (len);
}
int main (int argc, char **argv)

{
	if (argc == 3)
	{
		int i;
		int j;
		int len = ft_strlen(argv[1]);
		int w;
		i = 0;
		j = 0;

		while (argv[2][j] != '\0' && (i < len))
		{
			if (argv[1][i] == argv[2][j])
			{
				i++;
			}
			j++;
			w = 0;
			if (i == len)
			{
				while (argv[1][w])
				{
					write (1, &argv[1][w], 1);
					w++;
				}
			}
		}
	}
	write(1, "\n", 1);
}