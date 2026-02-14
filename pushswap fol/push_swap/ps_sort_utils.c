/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:40:13 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 17:40:14 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list	*max_num(s_list *stack_a)
{
	s_list *max;

	max = stack_a;
	while(stack_a)
	{
		if (stack_a->data > max->data)
			max = stack_a;
		stack_a = stack_a->next;
	}
	return (max);
}

s_list	*min_num(s_list *stack)
{
	s_list *min;

	min = stack;
	while(stack)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

//where it sits in the list (nearer to the top or bottom) and position (index) in the list
void	node_rank(s_list **stack)
{
	s_list *head;
	int	list_size;
	int index;
	
	list_size = ft_listsize(*stack);
    head = *stack;
	index = 0;
	while (index < list_size)
	{
        head->rank = 0; //up
        head->pos = index;
        if (head->pos > (list_size / 2))
            head->rank = 1; //not up
        index++;
        head = head->next;
	}
}

// ...existing code...

void	sort_turk(s_list **stack_a, s_list **stack_b)
{
	int list_size;
    // s_list *head_b = *stack_b;

	list_size = ft_listsize(*stack_a);
	while(list_size > 3)
	{
		ps_pb(stack_a, stack_b);
		list_size--;
	}
	sort_three(stack_a); //push to b then sort the three in a
	while(*stack_b)
	{
		update_stacks(stack_a, stack_b);
		s_list *cheapest = NULL;
		cheapest = find_cheapest(*stack_b, cheapest);
		execute_moves(stack_a, stack_b, cheapest);
	}
    while (!is_list_sorted(stack_a))
    {
        ps_ra(stack_a);
    }
}
//========================================================================


void update_stacks(s_list **stack_a, s_list **stack_b)
{
	node_rank(stack_a);
	node_rank(stack_b);
    target_in_a(*stack_a, *stack_b);
    calculate_costs(*stack_a, *stack_b);

}

void    target_in_a(s_list *stack_a, s_list *stack_b)
{
    s_list	*head_a;
    s_list	*head_b;

    head_b = stack_b;
    while (head_b)
    {
        head_a = stack_a; //reset stack_a everytime
        head_b->target = max_num(stack_a);
        while(head_a)
        {
            if (head_a->data > head_b->data && 
                (head_a->data < head_b->target->data))
                head_b->target = head_a;
            head_a = head_a->next;
        }
        if (head_b->target->data < head_b->data)
            head_b->target = min_num(stack_a);
        head_b = head_b->next;
    }
}


void	calculate_costs(s_list *stack_a, s_list *stack_b)
{
    s_list	*head_b;
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

s_list *find_cheapest(s_list *stack, s_list *cheapest)
{
	int total;
	int min_cost;
    s_list *ptr;
  
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

void	execute_moves(s_list **stack_a, s_list **stack_b, s_list *cheapest)
{
    if ((cheapest)->rank == (cheapest)->target->rank)
    {
        while(*stack_b != cheapest  && *stack_a != cheapest->target )
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
