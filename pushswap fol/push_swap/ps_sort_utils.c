/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:35:19 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/13 15:18:05 by maryaada         ###   ########.fr       */
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
		update_stacks(*stack_a, *stack_b);
		s_list *cheapest = find_cheapest(*stack_b);
		execute_moves(stack_a, stack_b, cheapest);
	}
    while (!is_list_sorted(stack_a))
    {
        ps_ra(stack_a);
    }
}
//========================================================================


void update_stacks(s_list *stack_a, s_list *stack_b)
{
	node_rank(&stack_a);
	node_rank(&stack_b);
    target_in_a(stack_a, stack_b);
    calculate_costs(stack_b, stack_a);

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

	// node_rank(&stack_a);
	// node_rank(&stack_b);
    
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


// s_list	*find_cheapest(s_list *stack_b)
// {
//     s_list	*cheapest;
//     s_list	*current;

//     cheapest = stack_b;
//     current = stack_b->next;
//     while (current)
//     {
//         if (current->total_cost < cheapest->total_cost)
//             cheapest = current;
//         current = current->next; 
//     }
//     return (cheapest);
// }

s_list *find_cheapest(s_list *stack_b)
{
    s_list *cheapest;
    s_list *cur;
    int a, b, cost, min;

    cur = stack_b;
    cheapest = stack_b;
    min = 2147483647;
    while (cur)
    {
        a = cur->cost_a;
        if (a < 0)
            a = -a;
        b = cur->cost_b;
        if (b < 0)
            b = -b;

        if ((cur->cost_a >= 0 && cur->cost_b >= 0)
         || (cur->cost_a < 0 && cur->cost_b < 0))
        {
            if (a > b)
                cost = a;
            else
                cost = b;
        }
        else
            cost = a + b;

        if (cost < min)
        {
            min = cost;
            cheapest = cur;
        }
        cur = cur->next;
    }
    return (cheapest);
}





//====================================================================


void	execute_moves(s_list **stack_a, s_list **stack_b, s_list *cheapest)
{
    // int		cost_a;
    // int		cost_b;

    // cost_a = cheapest->cost_a;
    // // cost_a = 2;
    // cost_b = cheapest->cost_b;
    // // cost_b = 3;
    
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

    // while((*stack_b)->rank == 0 && (*stack_b) != cheapest)
    // {
    //     ps_rr(stack_a, stack_b);
    // }
    // while((*stack_b)->rank == 1 && (*stack_b) != cheapest)
    // {
    //     ps_rrr(stack_a, stack_b);
    // }

    // while((*stack_b)->target->rank == 0 && (*stack_a) != cheapest->target)
    // {
    //     ps_rr(stack_a, stack_b);
    // }
    // while((*stack_b)->target->rank == 1 && (*stack_a)->target != cheapest->target)
    // {
    //     ps_rrr(stack_a, stack_b);
    // }
    //=====
    ps_pa(stack_a, stack_b);

}

/*  while (cost_a > 0)
 {
     ps_ra(stack_a);
     cost_a--;
 }
 while (cost_a < 0)
 {
     ps_rra(stack_a);
     cost_a++;
 }
 while (cost_b > 0)
 {
     ps_rb(stack_b);
     cost_b--;
 }
 while (cost_b < 0)
 {
     ps_rrb(stack_b);
     cost_b++;
 } */