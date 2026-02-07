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
	
}