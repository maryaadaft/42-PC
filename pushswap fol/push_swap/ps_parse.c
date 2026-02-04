#include "push_swap.h"

// any parsing fns go here?


// if multiple args then add to stack
//handle 2 arg, where split is needed or only one arg is given (without quotations)
//need strlen i think to check for one argument with quotations + no need for split or one argument without quotations

//check if already sorted!
int	is_list_sorted(s_list **stack_a)
{
	s_list	*current;

	if (!stack_a || !*stack_a)
		return (1);
	current = *stack_a;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_it_space(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= 9 && argv[i][j] <= 13) || argv[i][j] == 32)
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}