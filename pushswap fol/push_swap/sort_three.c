#include "push_swap.h"

void	sort_two(s_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
		ps_sa(stack_a);
}


void	sort_three(s_list **stack_a)
{
	s_list *max;
	s_list *head;

	head = *stack_a; //keeping the head
	max = max_num(*stack_a);
	
	if ((*stack_a)->data == max->data)
		ps_ra(stack_a);
	else if ((*stack_a)->next->data == max->data)
		ps_rra(stack_a);
	if ((*stack_a)->data > (*stack_a)->next->data)
		ps_sa(stack_a);
}

