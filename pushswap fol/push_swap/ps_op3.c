#include "push_swap.h"

// ====== push operations
// ====== only reverse rotate

//reverse rotate a
void	ps_rra(s_list **stack_a)
{
	s_list	*prev;
	s_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;

	prev = NULL;
	last = *stack_a;

	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;

	last->next = *stack_a;
	*stack_a = last;

	write(1, "rra\n", 4);
}


//reverse rotate b
void    ps_rrb(s_list **stack_b)
{
	s_list	*prev;
	s_list	*last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;

	prev = NULL;
	last = *stack_b;

	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;

	last->next = *stack_b;
	*stack_b = last;

	write(1, "rrb\n", 4);
}

//reverse rotate both a and b
void ps_rrr(s_list **stack_a, s_list **stack_b)
{
	ps_rra(stack_a);
	ps_rrb(stack_b);
	write(1, "rrr\n", 4);
}