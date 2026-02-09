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
		parse_single_arg(argv[1], stack_a);
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

int	is_sorted(s_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

s_list	*find_target(s_list *stack_a, int value)
{
	s_list	*target;
	s_list	*current;

	target = NULL;
	current = stack_a;
	while (current)
	{
		if (current->data > value)
		{
			if (!target || current->data < target->data)
				target = current;
		}
		current = current->next;
	}
	return (target);
}

int	get_rotation_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (-(size - pos));
}

void	rotate_to_pos(s_list **stack, int pos, int size)
{
	int	cost;
	int	i;

	cost = get_rotation_cost(pos, size);
	if (cost >= 0)
	{
		i = 0;
		while (i < cost)
		{
			ps_ra(stack);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < -cost)
		{
			ps_rra(stack);
			i++;
		}
	}
}

void	simple_sort(s_list **stack_a, s_list **stack_b)
{
	s_list	*target;
	int		size_a;
	int		pos;

	while (*stack_b)
	{
		size_a = ft_listsize(*stack_a);
		set_pos(*stack_a);
		target = find_target(*stack_a, (*stack_b)->data);
		
		if (!target)
			target = min_num(*stack_a);
		
		pos = target->pos;
		rotate_to_pos(stack_a, pos, size_a);
		ps_pa(stack_a, stack_b);
	}
	
	size_a = ft_listsize(*stack_a);
	set_pos(*stack_a);
	target = min_num(*stack_a);
	pos = target->pos;
	rotate_to_pos(stack_a, pos, size_a);
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
	
	if (!stack_a || is_sorted(stack_a))
		return (0);
	
	reset_rank(stack_a);
	node_rank(&stack_a);
	
	if (ft_listsize(stack_a) == 2)
		sort_two(&stack_a);
	else if (ft_listsize(stack_a) == 3)
		sort_three(&stack_a);
	else
	{
		while (ft_listsize(stack_a) > 3)
			ps_pb(&stack_a, &stack_b);
		sort_three(&stack_a);
		simple_sort(&stack_a, &stack_b);
	}
	
	return (0);
}