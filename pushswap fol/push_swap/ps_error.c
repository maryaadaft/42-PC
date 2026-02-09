#include "push_swap.h"

//handle non integer args
//check in stack instead of args
int arg_is_num(char *argv)
{
    int i = 0;

    if (!argv || !argv[0])
        return (0);

    if (argv[i] == '+' || argv[i] == '-')
        i++;

    if (!argv[i])
        return (0);

    while (argv[i])
    {
        if (!ft_isdigit(argv[i]))
            return (0);
        i++;
    }
    return (1);
}

//handle duplicate number args
int arg_is_dup(s_list *stack, int data)
{
    s_list *current = stack;
    while (current)
    {
        if (current->data == data)
            return (1);
        current = current->next;
    }
    return (0);
}

//return with frees
void    err_ret()
{
    write(2, "Error\n", 6);
    exit(1);
}

//free split args (for success & failure)
void	free_split_args(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i] != NULL)
	{
		free(split_args[i]);
		i++;
	}
	free (split_args);
}

//free stack (in case of failure)
void    free_all_stack(s_list   **stack)
{
    s_list *head;
    s_list *tmp;

    head = *stack;
    while (head)
    {
        tmp = head;
        free(tmp);
        head = head->next;
    }
    free(head);
}
