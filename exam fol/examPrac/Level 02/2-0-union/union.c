#include <unistd.h>
int	finding_nemo(char c, char *str, int p)
{
	int i;

	i = 0;

	while(i < p)
	{
		if (c == str[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char *wes_cat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(dest[i] != '\0')
	{
		i++;
	}
	while(src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main (int argc, char **argv)
{
	char *saved;
	int i;

	i = 0;
	if (argc == 3)
	{
		saved = wes_cat(argv[1], argv[2]);

		while (saved[i] != '\0')
		{
			if (!(finding_nemo(saved[i], saved, i)))
			{
				write(1, &saved[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}