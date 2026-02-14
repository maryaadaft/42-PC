/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:13:07 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 17:16:38 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ====== push operations
// ====== only reverse rotate

// reverse rotate
void	ps_rev_rotate(s_list **stack)
{
	s_list	*prev;
	s_list	*last;

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

void	ps_rra(s_list **stack_a)
{
	ps_rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

//reverse rotate b
void    ps_rrb(s_list **stack_b)
{
	ps_rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

//reverse rotate both a and b
void ps_rrr(s_list **stack_a, s_list **stack_b)
{
	ps_rev_rotate(stack_a);
	ps_rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}