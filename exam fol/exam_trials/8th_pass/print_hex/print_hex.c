#include <unistd.h>

unsigned long	print_hex(unsigned long numb)
{
	if ((numb / 16) > 0)
		print_hex(numb / 16);
	write(1, &"0123456789abcdef"[numb % 16], 1);
	return (numb);
}

int	mini_atoi(char *str)
{
	int i = 0;
	int num = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10 + (str[i] - '0');
		}
		i++;
	}
	return(num);
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		int n_arg = mini_atoi(argv[1]);
		print_hex(n_arg);

	}
	write(1, "\n", 1);
}