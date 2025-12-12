#include <unistd.h>
//solved it wrong dont look here
//
//
//
//
// correct one in union folder
 int	finding_nemo(char c, char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

//checking if the character we found alredy exists in the 1st string
int	found_him(char *og, char n, int b)
{
	int i;

	i = 0;
	while (i < b)
	{
		if (n == og[i])
			return (1);
		i++;
	}
	return (0);
}

//the dreadful main
int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 3)
	{
		while(argv[1][i] != '\0')
		{
			if ((finding_nemo(argv[1][i], argv[2]) == 1) && (found_him(argv[1], argv[1][i], i) == 0))
			{
				write(1, &argv[1][i], 1);
			}
			i++;
		}
		i = 0;
		while (argv[2][i] != '\0')
		{
			if (!(finding_nemo(argv[2][i], argv[1])));
		}
	}

}