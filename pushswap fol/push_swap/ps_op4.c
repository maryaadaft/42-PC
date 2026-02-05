#include "push_swap.h"

//push a and push b operations

//push a (push from b to a)
void	ps_pa(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp;

	if (!stack_b || !*stack_b)
		return ;

	temp = *stack_b;
	*stack_b = temp->next;

	temp->next = *stack_a;
	*stack_a = temp;

	write(1, "pa\n", 3);
}

//push b (push from a to b)
void	ps_pb(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp;

	if (!stack_a || !*stack_a)
		return ;

	temp = *stack_a;
	*stack_a = temp->next;

	temp->next = *stack_b;
	*stack_b = temp;

	write(1, "pb\n", 3);
}
