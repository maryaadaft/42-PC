#include "push_swap.h"

// ====== push operations
// ====== only reverse rotate

//reverse rotate a
void    ps_rra(s_list **stack_a)
{
    s_list	*first;
    s_list	*last;
    s_list	*second_last;

    if (ft_listsize(*stack_a) < 2)
        return ;
    first = *stack_a;
    last = *stack_a;
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = first;
    *stack_a = last;
    write(1, "rra\n", 4);
}

//reverse rotate b
void    ps_rrb(s_list **stack_b)
{
    s_list	*first;
    s_list	*last;
    s_list	*second_last;

    if (ft_listsize(*stack_b) < 2)
        return ;
    first = *stack_b;
    last = *stack_b;
    while (last->next != NULL)
    {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = first;
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