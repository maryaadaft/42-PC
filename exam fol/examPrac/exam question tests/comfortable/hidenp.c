#include <unistd.h>
//wdmatch but change the write of the last if statement
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
	// leave argv value inside if statements
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
// print out 1 or 0 based off of the output
		if (i == len)
		{
			write(1, "1", 1);
		}
		else
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}