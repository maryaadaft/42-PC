#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int letter = 0;
		int word = 1;
		while(argv[word] != '\0')
		{
			while (argv[word][letter] != '\0')
			{
				argv[word][letter] += 32;
				letter++
			}
			word++;
		}
		
	}
}