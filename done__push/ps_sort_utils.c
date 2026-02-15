/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:40:13 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/15 13:55:12 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*max_num(t_list *stack_a)
{
	t_list	*max;

	max = stack_a;
	while (stack_a)
	{
		if (stack_a->data > max->data)
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max);
}

t_list	*min_num(t_list *stack)
{
	t_list	*min;

	min = stack;
	while (stack)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	node_rank(t_list **stack)
{
	t_list	*head;
	int		list_size;
	int		index;

	list_size = ft_listsize(*stack);
	head = *stack;
	index = 0;
	while (index < list_size)
	{
		head->rank = 0;
		head->pos = index;
		if (head->pos > (list_size / 2))
			head->rank = 1;
		index++;
		head = head->next;
	}
}

void	target_in_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_b = stack_b;
	while (head_b)
	{
		head_a = stack_a;
		head_b->target = max_num(stack_a);
		while (head_a)
		{
			if (head_a->data > head_b->data
				&& (head_a->data < head_b->target->data))
				head_b->target = head_a;
			head_a = head_a->next;
		}
		if (head_b->target->data < head_b->data)
			head_b->target = min_num(stack_a);
		head_b = head_b->next;
	}
}

void	calculate_costs(t_list *stack_a, t_list *stack_b)
{
	t_list	*head_b;
	int		size_a;
	int		size_b;

	size_a = ft_listsize(stack_a);
	size_b = ft_listsize(stack_b);
	head_b = stack_b;
	while (head_b)
	{
		if (head_b->rank == 1)
			head_b->cost_b = size_b - head_b->pos;
		else
			head_b->cost_b = head_b->pos;
		if (head_b->target->rank == 1)
			head_b->cost_a = size_a - head_b->target->pos;
		else
			head_b->cost_a = head_b->target->pos;
		head_b = head_b->next;
	}
}
