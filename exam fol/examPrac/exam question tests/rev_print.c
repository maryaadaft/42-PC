#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int i;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			i++;
		}
		while (i >= 0)
		{
			write (1, &argv[1][i], 1);
			i--;
		}
		printf("\n%s", argv[1]);
	}
}