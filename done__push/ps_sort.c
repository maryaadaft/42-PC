/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:03:06 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/15 14:00:08 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stacks(t_list **stack_a, t_list **stack_b)
{
	node_rank(stack_a);
	node_rank(stack_b);
	target_in_a(*stack_a, *stack_b);
	calculate_costs(*stack_a, *stack_b);
}

t_list	*find_cheapest(t_list *stack, t_list *cheapest)
{
	int		total;
	int		min_cost;
	t_list	*ptr;

	ptr = stack;
	min_cost = INT_MAX;
	while (ptr)
	{
		if (ptr->rank == ptr->target->rank)
		{
			if (ptr->cost_a >= ptr->cost_b)
				total = ptr->cost_a;
			else
				total = ptr->cost_b;
		}
		else
			total = ptr->cost_a + ptr->cost_b;
		if (total < min_cost)
		{
			min_cost = total;
			cheapest = ptr;
		}
		ptr = ptr->next;
	}
	return (cheapest);
}

void	execute_moves(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	if ((cheapest)->rank == (cheapest)->target->rank)
	{
		while (*stack_b != cheapest && *stack_a != cheapest->target)
		{
			if ((cheapest)->rank == 0)
				ps_rr(stack_a, stack_b);
			else
				ps_rrr(stack_a, stack_b);
		}
	}
	while ((*stack_b) != cheapest)
	{
		if (cheapest->rank == 0)
			ps_rb(stack_b);
		else
			ps_rrb(stack_b);
	}
	while ((*stack_a) != cheapest->target)
	{
		if (cheapest->target->rank == 0)
			ps_ra(stack_a);
		else
			ps_rra(stack_a);
	}
	ps_pa(stack_a, stack_b);
}

void	sort_turk(t_list **stack_a, t_list **stack_b)
{
	int		list_size;
	t_list	*cheapest;

	list_size = ft_listsize(*stack_a);
	while (list_size > 3)
	{
		ps_pb(stack_a, stack_b);
		list_size--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		update_stacks(stack_a, stack_b);
		cheapest = NULL;
		cheapest = find_cheapest(*stack_b, cheapest);
		execute_moves(stack_a, stack_b, cheapest);
	}
	while (!is_list_sorted(stack_a))
	{
		ps_ra(stack_a);
	}
}
