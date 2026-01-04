#include "push_swap.h"

//handle non integer args
int arg_is_num(char **argv)
{
	int i;
	int j;

    i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//handle duplicate number args
int arg_is_dup(char **argv)
{
    int i;
    int j;

    i = 1;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

//protect against int overflow/underflow
int arg_overflow(char **argv)
{
    int i;
    long num;

    i = 1;
    while (argv[i])
    {
        num = ft_atoi(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            return (1);
        i++;
    }
    return (0);
}
//if no args at all