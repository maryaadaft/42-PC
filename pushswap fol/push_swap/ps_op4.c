#include "push_swap.h"

//push a and push b operations

//push a (push from b to a)
void	ps_pa(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	*stack_b = (*stack_b)->next;

	temp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = temp;
	temp->prev = NULL;
	*stack_a = temp;
	write(1, "pa\n", 3);	
}