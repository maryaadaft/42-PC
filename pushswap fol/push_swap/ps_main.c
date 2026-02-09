#include "push_swap.h"



//for debug printing
/* void print_stack(s_list *stack)
{
    while (stack)
    {
        printf("data:%d   rank:%d   pos:%d   ca:%d   cb:%d   tc:%d\n",
            stack->data,
            stack->rank,
            stack->pos,
            stack->cost_a,
            stack->cost_b,
            stack->total_cost);
        stack = stack->next;
    }
    printf("----\n");
} */


void final_rotate(s_list **stack_a)
{
    s_list *min;
    int size;
    int pos;

    size = ft_listsize(*stack_a);
    set_pos(*stack_a);

    min = *stack_a;
    while (min && min->rank != 0)
        min = min->next;
    if (!min)
        return;

    pos = min->pos;

    if (pos <= size / 2)
    {
        while (pos--)
            ps_ra(stack_a);
    }
    else
    {
        pos = size - pos;
        while (pos--)
            ps_rra(stack_a);
    }
}


void	push_to_b(s_list **a, s_list **b)
{
	int	size;
	int	i;

	size = ft_listsize(*a);
	i = 0;

	while (size > 6 && i < size)
	{
		if ((*a)->rank <= size / 2)
		{
			ps_pb(a, b);
			size--;
		}
		else
			ps_ra(a);
		i++;
	}
	while (ft_listsize(*a) > 3)
		ps_pb(a, b);
}


void	sort_turk(s_list **stack_a, s_list **stack_b)
{
    s_list *cheapest;

    // 1. Push everything except 3 to B
    // while (ft_listsize(*stack_a) > 3)
    push_to_b(stack_a, stack_b);

    // 2. Sort remaining 3 in A
    sort_three(stack_a);

    // 3. Main Turk loop
    while (*stack_b)
    {
        set_pos(*stack_a);
        set_pos(*stack_b);
        calculate_costs(*stack_a, *stack_b);
        cheapest = find_cheapest(*stack_b);
        execute_moves(stack_a, stack_b, cheapest);
    }

    // 4. Final rotate
    final_rotate(stack_a);
}


//re writing fns

s_list  *push_to_list(s_list **stack, int data)
{
	s_list *new_node = ft_listnew(data);
	if (!new_node)
		return (err_ret(), NULL); 

	if (!*stack)
		*stack = new_node; //stack points to first node (new node)
	else
	{
		s_list *current = *stack;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return new_node;
}

void parse_args(int argc, char **argv, s_list **stack_a)
{
    int i;
    int data;
    int over;
	char **split_args;

	if (arg_is_num(argv) || arg_is_dup(argv))
		err_ret();
	if (argc == 2 && (has_space(argv[1]) || ft_strlen(argv[1] > 2)))
		split_args = ft_split(argv[1], ' ');

	//add to stack both split args and argv++ ..
    i = 1;
    while (i < argc)
    {
        over = 0;
        data = to_num(argv[i], &over);
        if (over == 1 || !push_to_list(stack_a, data))
            err_ret(); // your existing error handler
       ft_listadd_back(stack_a, ft_listnew(data));
        i++;
    }
	    // print_stack(stack_a);
}


int main(int argc, char **argv)
{
    s_list *stack_a = NULL;
    s_list *stack_b = NULL;

    parse_args(argc, argv, &stack_a);   // your atoi + push
    reset_rank(stack_a);
    node_rank(&stack_a);

	if (argc == 3)
		sort_two(&stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	else if (argc > 4)
    	sort_turk(&stack_a, &stack_b);

    // print_stack(stack_a); // verify sorted
}
