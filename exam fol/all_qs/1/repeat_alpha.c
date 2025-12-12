#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		int repeat;
		while (argv[1][i] != '\0')
		{
			repeat = 0;
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				repeat = (argv[1][i] - 96);
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				repeat = (argv[1][i] - 65);
			else
				write(1, &argv[1][i], 1);
			while (repeat > 0)
			{
				write(1, &argv[1][i], 1);
				repeat--;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}