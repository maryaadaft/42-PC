/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:17:00 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 17:17:01 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ====== push operations
// ====== only swaps for a. b or both

// swaps
void    ps_swap(s_list **stack)
{
    s_list	*first;
	s_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
}

// swap a
void	ps_sa(s_list **stack_a)
{
	ps_swap(stack_a);
	write(1, "sa\n", 3);
}

// swap b
void	ps_sb(s_list **stack_b)
{
    ps_swap(stack_b);
    write(1, "sb\n", 3);
}

// swap both a and b
void	ps_ss(s_list **stack_a, s_list **stack_b)
{
    ps_swap(stack_a);
    ps_swap(stack_b);
    write(1, "ss\n", 3);
}