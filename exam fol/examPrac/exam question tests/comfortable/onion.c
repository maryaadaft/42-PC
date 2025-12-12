#include <unistd.h>
#include <stdio.h>

int	finding_nemo(char f, char *str, int p)
{
	int i;

	i = 0;
//checks from i all the way up to position i++(p) if the letter at i is found in the str
	while (i < p)
	{
		if (f == str[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

// strcat, whoever reads this, leave my fn names alone. Thank you
char  *street_cats(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
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
	return(dest);
}

int	main(int argc, char **argv)
{
	int i;
	char *neko;

	i = 0;
	if (argc == 3)
	{
		neko = street_cats(argv[1], argv[2]);
		while(neko[i] != '\0')
		{
			if(!(finding_nemo(neko[i], neko, i)))
				{
					write(1, &neko[i], 1);
				}
			i++;
		}
	}
	write(1, "\n", 1);
}