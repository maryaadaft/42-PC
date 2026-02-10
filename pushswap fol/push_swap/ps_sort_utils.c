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

int	get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);     // rotate
	return (pos - size);  // reverse rotate (negative)
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
		calculate_costs(*stack_a, *stack_b);
		// s_list *cheapest = find_cheapest(*stack_b);
		execute_moves(stack_a, stack_b);
	}
}
//========================================================================


//new fns

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
    int		size_a;
    int		size_b;

    size_a = ft_listsize(stack_a);
    size_b = ft_listsize(stack_b);
    current_b = stack_b;

	node_rank(&stack_a);
	node_rank(&stack_b);
    
    while (current_b)
    {
        target = target_in_a(stack_a, current_b);
        cost_a = get_cost(target->pos, size_a);
        cost_b = get_cost(current_b->pos, size_b);
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

//====================================================================



void	execute_moves(s_list **stack_a, s_list **stack_b)
{
    int		cost_a;
    int		cost_b;

    // cost_a = cheapest->cost_a;
    cost_a = 2;
    // cost_b = cheapest->cost_b;
    cost_b = 3;
    
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

