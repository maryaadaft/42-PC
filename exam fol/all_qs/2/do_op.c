#include <unistd.h>
#include <stdio.h>

// mini atoi
int	mini_atoi(char *str)
{
	int i = 0;
	int numb = 0;
	int sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		numb = numb * 10 + str[i] - 48;
		i++;
	}
	return (numb * sign);
}

//not_printf
int not_printf(int nb)
{
	if (nb > 9)
		not_printf(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
	return (nb);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		int first_num = mini_atoi(argv[1]);
		int i = 0;
		int sec_num = mini_atoi(argv[3]);
		int operate;

		// printf("%d\n", first_num);
		// printf("%d\n", sec_num);

		if (argv[2][0] == '+')
		{
			operate = first_num + sec_num;
		}
		else if (argv[2][0] == '-')
		{
			operate = first_num - sec_num;
		}
		else if (argv[2][0] == '*')
		{
			operate = first_num * sec_num;
		}
		else if (argv[2][0] == '/')
		{
			operate = first_num / sec_num;
		}
		// printf("%d\n", operate);
		not_printf(operate);
	}
	write(1, "\n", 1);
}