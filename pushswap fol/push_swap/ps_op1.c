#include "push_swap.h"

// ====== push operations
// ====== only swaps for a. b or both

// swap a
void	ps_sa(s_list **stack_a)
{
	s_list	*first;
	s_list	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;

	first = *stack_a;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack_a = second;

	write(1, "sa\n", 3);
}

// swap b
void	ps_sb(s_list **stack_b)
{
    s_list	*first;
    s_list	*second;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return ;

    first = *stack_b;
    second = first->next;

    first->next = second->next;
    second->next = first;
    *stack_b = second;

    write(1, "sb\n", 3);
}

// swap both a and b
void	ps_ss(s_list **stack_a, s_list **stack_b)
{
    ps_sa(stack_a);
    ps_sb(stack_b);
    write(1, "ss\n", 3);
}