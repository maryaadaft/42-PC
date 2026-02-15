/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:22:09 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/15 13:48:04 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		ps_sa(stack_a);
}

void	sort_three(t_list **stack_a)
{
	t_list	*max;

	max = max_num(*stack_a);
	if ((*stack_a)->data == max->data)
		ps_ra(stack_a);
	else if ((*stack_a)->next->data == max->data)
		ps_rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ps_sa(stack_a);
}
