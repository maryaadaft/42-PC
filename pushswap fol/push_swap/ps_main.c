#include "push_swap.h"

//for debug printing
void print_stack(s_list *stack)
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
}

//re writing fns

//pass split args or argv
void    make_stack(char **args, s_list **stack_a)
{
    int i;
    int over;
    int data;

    i = 0;
    while(args[i] != NULL)
    {
        if (arg_is_num(args[i]) == 0) //check dups in args
            err_ret();
        
        over = 0;
        data = to_num(args[i], &over);
        if (over == 1)
            err_ret();
            
        //check dups in stack
        if (arg_is_dup(*stack_a, data) == 1)
            err_ret();

        ft_listadd_back(stack_a, ft_listnew(data));
        i++;
    }
}

void parse_args(int argc, char **argv, s_list **stack_a)
{
    int i;
	char **split_args;

    if (argc < 2)
        return ;

	//add to stack both split args and argv++ ..
    i = 1;
    while (i < argc)
    {
        split_args = ft_split(argv[i], ' ');
        if (!split_args || !split_args[0])
            return (free_split_args(split_args), err_ret());
        make_stack(split_args, stack_a);
        free_split_args(split_args);
        i++;
    }
}


int main(int argc, char **argv)
{
    s_list *stack_a = NULL;
    // s_list *stack_b = NULL;

    parse_args(argc, argv, &stack_a);   // your atoi + push
    // reset_rank(stack_a);
    // node_rank(&stack_a);
	if (ft_listsize(stack_a) == 2)
		sort_two(&stack_a);
	else if (ft_listsize(stack_a) == 3)
		sort_three(&stack_a);
	// else if (argc > 4)
    	// sort_turk(&stack_a, &stack_b);

    print_stack(stack_a); // verify sorted
    free_all_stack(&stack_a);
}
