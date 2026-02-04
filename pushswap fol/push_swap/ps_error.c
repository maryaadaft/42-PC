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
    int num_flag = 0;

    i = 1;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (to_num(argv[i], &num_flag) == to_num(argv[j], &num_flag))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void    err_ret()
{
    write(2, "Error\n", 6);
    return ;
}
//if no args at all