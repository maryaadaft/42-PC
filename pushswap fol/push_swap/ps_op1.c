#include "push_swap.h"

// ====== push operations
// ====== only swaps for a. b or both

// swap a
void	ps_sa(s_list **stack_a)
{
    s_list	*first;
    s_list	*sec;
    
    if (!*stack_a || !(*stack_a)->next || !stack_a ||ft_listsize(*stack_a) < 2)
        return ;
    first = *stack_a;
    sec = first->next;

    first->next = sec->next;
    if(sec->next)
        sec->next->prev = first;
    
    sec->prev = NULL;
    sec->next = first;
    first->prev = sec;

   *stack_a = sec;
    write(1, "sa\n", 3);
}

// swap b
void	ps_sb(s_list **stack_b)
{
    s_list	*first;
    s_list	*sec;
    
    if (!*stack_b || !(*stack_b)->next || !stack_b ||ft_listsize(*stack_b) < 2)
        return ;
    first = *stack_b;
    sec = first->next;

    first->next = sec->next;
    if(sec->next)
        sec->next->prev = first;
    
    sec->prev = NULL;
    sec->next = first;
    first->prev = sec;

   *stack_b = sec;
    write(1, "sb\n", 3);
}

// swap both a and b
void	ps_ss(s_list **stack_a, s_list **stack_b)
{
    ps_sa(stack_a);
    ps_sb(stack_b);
    write(1, "ss\n", 3);
}