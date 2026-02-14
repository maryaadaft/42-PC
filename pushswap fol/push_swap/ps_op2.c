/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:16:53 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 17:16:54 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ====== push operations
// only rotate fn for a and b and both

//rotate general
void    ps_rotate(s_list **stack)
{
    s_list	*first;
	s_list	*last;

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
void	ps_ra(s_list **stack_a)
{
	ps_rotate(stack_a);
	write(1, "ra\n", 3);
 }

//rotate b
void    ps_rb(s_list **stack_b)
{
    ps_rotate(stack_b);
    write(1, "rb\n", 3);
}
//rotate both a and b
void    ps_rr(s_list **stack_a, s_list **stack_b)
{
    ps_rotate(stack_a);
    ps_rotate(stack_b);
    write(1, "rr\n", 3);
}

