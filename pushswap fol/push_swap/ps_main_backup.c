#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	check_duplicate(s_list *stack)
{
	s_list	*current;
	s_list	*compare;

	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->data == compare->data)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

void	parse_single_arg(char *arg, s_list **stack_a)
{
	char	**split;
	int		i;
	int		over;
	int		value;

	split = ft_split(arg, ' ');
	if (!split)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	while (split[i])
	{
		over = 0;
		value = to_num(split[i], &over);
		if (over)
		{
			free_split(split);
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_listadd_back(stack_a, ft_listnew(value));
		i++;
	}
	free_split(split);
}

void	parse_args(int argc, char **argv, s_list **stack_a)
{
	int		i;
	int		value;
	int		over;

	if (argc < 2)
		return ;
	if (argc == 2)
	{
		parse_single_arg(argv[1], stack_a);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			over = 0;
			value = to_num(argv[i], &over);
			if (over)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			ft_listadd_back(stack_a, ft_listnew(value));
			i++;
		}
	}
	if (check_duplicate(*stack_a))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	is_sorted_asc(s_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_to_b(s_list **a, s_list **b)
{
	int	size;
	int	chunk_size;
	int	rotations;

	size = ft_listsize(*a);
	chunk_size = size / 2;
	rotations = 0;
	
	while (ft_listsize(*a) > 3)
	{
		if ((*a)->rank < chunk_size)
		{
			ps_pb(a, b);
			rotations = 0;
		}
		else if (rotations < size)
		{
			ps_ra(a);
			rotations++;
		}
		else
		{
			break ;
		}
	}
}

void	final_rotate(s_list **stack_a)
{
	s_list	*min;
	int		size;
	int		pos;

	size = ft_listsize(*stack_a);
	set_pos(*stack_a);
	min = min_num(*stack_a);
	if (!min)
		return ;
	pos = min->pos;
	if (pos <= size / 2)
	{
		while (pos--)
			ps_ra(stack_a);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			ps_rra(stack_a);
	}
}

void	sort_turk(s_list **stack_a, s_list **stack_b)
{
	s_list	*cheapest;
	int		initial_b_size;

	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	initial_b_size = ft_listsize(*stack_b);
	while (*stack_b && initial_b_size > 0)
	{
		set_pos(*stack_a);
		set_pos(*stack_b);
		calculate_costs(*stack_a, *stack_b);
		cheapest = find_cheapest(*stack_b);
		if (!cheapest)
			break ;
		execute_moves(stack_a, stack_b, cheapest);
		initial_b_size--;
		if (initial_b_size < 0)
			break ;
	}
	final_rotate(stack_a);
}

int	main(int argc, char **argv)
{
	s_list	*stack_a;
	s_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &stack_a);
	if (!stack_a)
		return (0);
	if (is_sorted_asc(stack_a))
		return (0);
	reset_rank(stack_a);
	node_rank(&stack_a);
	if (ft_listsize(stack_a) == 2)
		sort_two(&stack_a);
	else if (ft_listsize(stack_a) == 3)
		sort_three(&stack_a);
	else
		sort_turk(&stack_a, &stack_b);
	return (0);
}
