#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int letters;
		int strings = 1;

		while (argv[strings]) //while the arguments exist and is not null
		{
			letters = 0;
			while(argv[strings][letters] != '\0')
			{
				if((argv[strings][letters] >= 9 && argv[strings][letters] <= 13) || argv[strings][letters] == 32)
				{
					write(1, &argv[strings][letters], 1);
					letters++;
				}	
				if (argv[strings][letters] >= 65 && argv[strings][letters] <= 90)  //turn everything lowercase
				{
					argv[strings][letters] += 32;
				}
				if ((argv[strings][letters] >= 97 && argv[strings][letters] <= 122) && (argv[strings][letters + 1] >= 9 && argv[strings][letters + 1] <= 13 || argv[strings][letters + 1] == 32) || (argv[strings][letters + 1] == '\0'))
				{
					argv[strings][letters] -= 32;
				}
				write(1, &argv[strings][letters], 1);
				letters++;
			}
			strings++;
			write(1, "\n", 1);
		}
		write(1, "\n", 1);
	}
}