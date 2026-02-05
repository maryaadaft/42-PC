#include "push_swap.h"

// ====== push operations
// only rotate fn for a and b and both

//rotate a
void	ps_ra(s_list **stack_a)
{
	s_list	*first;
	s_list	*last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;

	first = *stack_a;
	last = *stack_a;

	while (last->next)
		last = last->next;

	*stack_a = first->next;
	first->next = NULL;
	last->next = first;

	write(1, "ra\n", 3);
 }

//rotate b
void    ps_rb(s_list **stack_b)
{
    s_list	*first;
    s_list	*last;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;

    first = *stack_b;
    last = *stack_b;

    while (last->next)
        last = last->next;

    *stack_b = first->next;
    first->next = NULL;
    last->next = first;

    write(1, "rb\n", 3);
}
//rotate both a and b
void    ps_rr(s_list **stack_a, s_list **stack_b)
{
    ps_ra(stack_a);
    ps_rb(stack_b);
    write(1, "rr\n", 3);
}

