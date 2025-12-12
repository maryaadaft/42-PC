#include <unistd.h>

int	finding_nemo(char *str, char c, int pos)
{
	int i = 0;
	while(i < pos)
	{
		if (c == str[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char *street_cat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while(dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		char *tog = street_cat(argv[1], argv[2]);

		while (tog[i])
		{
			if (finding_nemo(tog, tog[i], i) == 0)
			{
				write(1, &tog[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}