/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:17:00 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 20:05:01 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ps_sa(t_list **stack_a)
{
	ps_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ps_sb(t_list **stack_b)
{
	ps_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ps_ss(t_list **stack_a, t_list **stack_b)
{
	ps_swap(stack_a);
	ps_swap(stack_b);
	write(1, "ss\n", 3);
}
