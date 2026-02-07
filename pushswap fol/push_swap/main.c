

//=============================


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:47:09 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/07 19:54:02 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(s_list *stack)
{
    s_list	*temp;

    while (stack)
    {
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}

void	push_swap(s_list **stack_a, s_list **stack_b)
{
    int	size;

    size = ft_listsize(*stack_a);

    if (size == 2)
    {
        sort_two(stack_a);
        return ;
    }
    if (size == 3)
    {
        sort_three(stack_a);
        return ;
    }
	reset_rank(stack_a);
    node_rank(stack_a);

    while (ft_listsize(*stack_a) > 3)
        ps_pb(stack_a, stack_b);
    
    sort_three(stack_a);
    
    while (*stack_b)
    {
        set_pos(*stack_a);
        set_pos(*stack_b);
        calculate_costs(*stack_a, *stack_b);
        execute_moves(stack_a, stack_b, find_cheapest(*stack_b));
    }

	set_pos(*stack_a);
    while ((*stack_a)->rank != 0)
    {
        if ((*stack_a)->pos <= ft_listsize(*stack_a) / 2)
            ps_ra(stack_a);
        else
            ps_rra(stack_a);
        set_pos(*stack_a);
    }
}

int	parse_input(int argc, char **argv, s_list **stack_a)
{
	int	i;
	int	num;
	int	over_check;

	i = 1;
	over_check = 0;
	while (i < argc - 1)
	{
		if (!arg_is_num(argv[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		num = to_num(argv[i], over_check);
		if (arg_is_dup(*stack_a))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		add_node(stack_a, num);
	}
	return (1);
}

int	main(int argc, char **argv)
{
    s_list	*stack_a;
    s_list	*stack_b;

    stack_a = NULL;
    stack_b = NULL;
    
    // Parse input and build stack_a
    // ...your parsing code...
	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
    else
		parse_input(argc, argv, &stack_a);
	
    push_swap(&stack_a, &stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
    
    return (0);
}


