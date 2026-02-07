void	free_stack(s_list *stack)
{
    s_list	*temp;

    while (stack)
    {
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}
