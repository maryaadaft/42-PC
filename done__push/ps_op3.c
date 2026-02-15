/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:13:07 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/15 13:41:12 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rev_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ps_rra(t_list **stack_a)
{
	ps_rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	ps_rrb(t_list **stack_b)
{
	ps_rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_list **stack_a, t_list **stack_b)
{
	ps_rev_rotate(stack_a);
	ps_rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
