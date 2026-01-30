#include "push_swap.h"

//push a and push b operations

//push a (push from b to a)
void	ps_pa(s_list **stack_list_a, s_list **stack_list_b)
{
	s_list	*temp;

	if (!*stack_list_b)
		return ;
	temp = *stack_list_b;
	*stack_list_b = (*stack_list_b)->next;
	temp->next = *stack_list_a;
	*stack_list_a = temp;
	write(1, "pa\n", 3);	
}