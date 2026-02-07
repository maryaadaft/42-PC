void	push_swap(s_list **stack_a, s_list **stack_b)
{
    int	size;

    size = ft_listsize(*stack_a);
    
    // Handle small cases
    if (size == 2)
    {
        sort_two(stack_a);
        return ;
    }
    if (size == 3)
    {
        sort_three(stack_a);
        return ;
    }
    
    // Rank all elements in stack_a
    node_rank(stack_a);
    
    // Push all but 3 elements to stack_b
    while (ft_listsize(*stack_a) > 3)
        ps_pb(stack_a, stack_b);
    
    // Sort remaining 3 in stack_a
    sort_three(stack_a);
    
    // Push elements back from stack_b to stack_a
    while (*stack_b)
    {
        set_pos(*stack_a);
        set_pos(*stack_b);
        calculate_costs(*stack_a, *stack_b);
        execute_moves(stack_a, stack_b, find_cheapest(*stack_b));
    }
    
    // Rotate stack_a so minimum is at top
    set_pos(*stack_a);
    while ((*stack_a)->rank != 0)
    {
        if ((*stack_a)->pos <= ft_listsize(*stack_a) / 2)
            ps_ra(stack_a);
        else
            ps_rra(stack_a);
        set_pos(*stack_a);
    }
}


int	main(int argc, char **argv)
{
    s_list	*stack_a;
    s_list	*stack_b;

    stack_a = NULL;
    stack_b = NULL;
    
    // Parse input and build stack_a
    // ...your parsing code...
    
    push_swap(&stack_a, &stack_b);
    
    // Free stacks
    // ...cleanup code...
    
    return (0);
}




