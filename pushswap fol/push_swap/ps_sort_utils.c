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

void	set_pos(s_list *stack)
{
	int i = 0;

	while (stack)
	{
		stack->pos = i++;
		stack = stack->next;
	}
}

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);     // rotate
	return (pos - size);  // reverse rotate (negative)
}

void	reset_rank(s_list *stack)
{
	while (stack)
	{
		stack->rank = -1;
		stack = stack->next;
	}
} //call this when finding the rank of the min number somewhere
//also move it away from this file

void	node_rank(s_list **stack)
{
	s_list *head;
	s_list *min;
	int	list_size;
	int i;
	
	list_size = ft_listsize(*stack);
	i = 0;
	while (i < list_size)
	{
		head = *stack;
		min = NULL;
		while (head)
		{
			if (head->rank == -1 && (!min || head->data < min->data))
				min = head;
			head = head->next;
			}
			min->rank = i;
			i++;
	}
}

s_list	*target_in_a(s_list *stack_a, s_list *stack_b)
{
	s_list	*target;
    s_list	*current;

    target = NULL;
    current = stack_a;
    while (current)
    {
        if (current->rank > stack_b->rank && 
            (!target || current->rank < target->rank))
            target = current;
        current = current->next;
    }
    if (!target)
        target = min_num(stack_a);
    return (target);
}

void	calculate_costs(s_list *stack_a, s_list *stack_b)
{
    s_list	*current_b;
    s_list	*target;
    int		cost_a;
    int		cost_b;

    current_b = stack_b;
    while (current_b)
    {
        target = target_in_a(stack_a, current_b);
        cost_a = get_cost(target->pos, ft_listsize(stack_a));
        cost_b = get_cost(current_b->pos, ft_listsize(stack_b));
        current_b->cost_a = cost_a;
        current_b->cost_b = cost_b;
        current_b->total_cost = abs(cost_a) + abs(cost_b);
        current_b = current_b->next;
    }
}


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

void	execute_moves(s_list **stack_a, s_list **stack_b, s_list *cheapest)
{
    int		cost_a;
    int		cost_b;

    cost_a = cheapest->cost_a;
    cost_b = cheapest->cost_b;
    
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

