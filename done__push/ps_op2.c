/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:16:53 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 22:07:56 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ps_ra(t_list **stack_a)
{
	ps_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	ps_rb(t_list **stack_b)
{
	ps_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	ps_rr(t_list **stack_a, t_list **stack_b)
{
	ps_rotate(stack_a);
	ps_rotate(stack_b);
	write(1, "rr\n", 3);
}
