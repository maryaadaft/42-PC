/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:35:19 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/12 16:49:35 by maryaada         ###   ########.fr       */
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

// int	get_cost(int pos, int size)
// {
// 	if (pos <= size / 2)
// 		return (pos);     // rotate
// 	return (pos - size);  // reverse rotate (negative)
// }

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
        head->rank = 0;
        head->pos = index;
        if (head->pos >= (list_size / 2))
            head->rank = 1;
        index++;
        head = head->next;
	}
}

// ...existing code...

void	sort_turk(s_list **stack_a, s_list **stack_b)
{
	int list_size;

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
		// calculate_costs(*stack_a, *stack_b);
		// s_list *cheapest = find_cheapest(*stack_b);
		execute_moves(stack_a, stack_b);
	}
}
//========================================================================


void update_stacks(s_list *stack_a, s_list *stack_b)
{
	node_rank(&stack_a);
	node_rank(&stack_b);
    target_in_a(stack_a, stack_b);
    calculate_costs(stack_a, stack_b);

}

// void execute_cheapest(s_list **a, s_list **b)
// {
//     s_list *c = find_cheapest(*b);

//     while (c->cost_a > 0 && c->cost_b > 0)
//         ps_rr(a, b), c->cost_a--, c->cost_b--;
//     while (c->cost_a < 0 && c->cost_b < 0)
//         ps_rrr(a, b), c->cost_a++, c->cost_b++;

//     finish_rotation(a, &c->cost_a, 'a');
//     finish_rotation(b, &c->cost_b, 'b');

//     ps_pa(a, b);
// }


void    target_in_a(s_list *stack_a, s_list *stack_b)
{
    s_list	*head_a;
    s_list	*head_b;

    head_b = stack_b;
    while (head_b)
    {
        head_a = stack_a; //reset stack_a everytime
        head_b->target = max_num(head_a);
        while(head_a)
        {
            if (head_a->data > head_b->data && 
                (head_a->data < head_b->target->data))
                head_b->target = head_a;
            head_a = head_a->next;
        }
        if (head_b->target->data < head_b->data)
            head_b->target = min_num(head_a);
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

	node_rank(&stack_a);
	node_rank(&stack_b);
    
    while (head_b)
    {
        if (head_b->rank == 1)
            head_b->cost_a = head_b->pos;
        else
            head_b->cost_a = size_a - head_b->pos;
        if (head_b->target->rank == 1)
            head_b->cost_a = head_b->target->pos;
        else
            head_b->cost_a = size_a - head_b->target->pos;
        head_b = head_b->next;
    }
}

// void calculate_costs(s_list *stack_a, s_list *stack_b)
// {
//     s_list *current_b;
//     s_list *target;
//     int size_a;
//     int size_b;

//     size_a = ft_listsize(stack_a);
//     size_b = ft_listsize(stack_b);

//     node_rank(&stack_a);
//     node_rank(&stack_b);

//     current_b = stack_b;
//     while (current_b)
//     {
//         target = target_in_a(stack_a, current_b);

//         // cost for A
//         if (target->pos <= size_a / 2)
//             current_b->cost_a = target->pos;
//         else
//             current_b->cost_a = target->pos - size_a;

//         // cost for B
//         if (current_b->pos <= size_b / 2)
//             current_b->cost_b = current_b->pos;
//         else
//             current_b->cost_b = current_b->pos - size_b;

//         current_b = current_b->next;
//     }
// }


s_list	*find_cheapest(s_list *stack_b)
{
    s_list	*cheapest;
    s_list	*current;

    cheapest = stack_b;
    current = stack_b->next;
    while (current)
    {
        if (current->total_cost < cheapest->total_cost)
            cheapest = current;
        current = current->next; 
    }
    return (cheapest);
}

//====================================================================


void	execute_moves(s_list **stack_a, s_list **stack_b)
{
    int		cost_a;
    int		cost_b;

    cost_a = cheapest->cost_a;
    // cost_a = 2;
    cost_b = cheapest->cost_b;
    // cost_b = 3;
    
    while (cost_a > 0 && cost_b > 0)
    {
        ps_rr(stack_a, stack_b);
        cost_a--;
        cost_b--;
    }
    while (cost_a < 0 && cost_b < 0)
    {
        ps_rrr(stack_a, stack_b);
        cost_a++;
        cost_b++;
    }
    while (cost_a > 0)
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
    }
    ps_pa(stack_a, stack_b);
}

