#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		int i = 2; 
		s_list *stack_a = NULL;

		int num_flag = 0;
		stack_a = ft_listnew(to_num(argv[1], &num_flag));
		s_list *loop_list = stack_a; //loop through the list safely without losing pointer to head
		while (i < (argc))
		{
			if (arg_is_dup(argv) == 1 || arg_is_num(argv) == 1)
			{
				return (write(2, "Error\n", 6), 1);
			}
			ft_listadd_back(&loop_list, ft_listnew(to_num(argv[i], &num_flag)));
			if (num_flag == 1)
			{
				write(2, "Error\n", 6);
				return(1);
			}
			printf("flag is: %d\n", num_flag);
			loop_list = loop_list->next;
			i++;
		}
		s_list *head_ptr = stack_a;
		while(head_ptr != NULL)  //loop and print list before operations
		{
			printf("list has %d\n", head_ptr->data);
			head_ptr = head_ptr->next;
		}

		//make stack b
		// s_list	*stack_b;
		// stack_b = ft_listnew(5);
		// stack_b->next = ft_listnew(9);
		// s_list	*b_head = stack_b; //head of stack_b

		// printf("\n");
		// while(b_head != NULL)  //loop through b
		// {
		// 	printf("blist has %d\n", b_head->data);
		// 	b_head = b_head->next;
		// }

		//operation testing
		// if (stack_a)
		// {
		// 	printf("------after operations \n");
		// 	/* ps_ra(&stack_a);
		// 	ps_rb(&stack_b); */
		// 	// ps_rr(&stack_a, & stack_b);
		// 	// ps_pb(&stack_a, &stack_b);
		// 	s_list *op_a = stack_a;
		// 	while(op_a != NULL)  //loop and print list after operations
		// 	{
		// 		printf("list has %d\n", op_a->data);
		// 		op_a = op_a->next;
		// 	}
		// 	printf("\n");
		// 	b_head = stack_b;
		// 	while(b_head != NULL)  //loop through b
		// 	{
		// 		printf("blist has %d\n", b_head->data);
		// 		b_head = b_head->next;
		// 	}
		// }
	
	}
	else if (argc == 2 && is_it_space(argv) == 0)
	{
		int w;
		// if (has_space(argv) == 1)
		// {
		// 	if (arg_is_dup(argv) == 1 || arg_overflow(argv) == 1)
		// 	{
		// 		return (write(2, "Error\n", 6), 1);
		// 	}
		// }
		char **split_num = ft_split(argv[1], ' ');
		s_list *stack_a = NULL;

		int num_flag = 0;
		stack_a = ft_listnew(to_num(split_num[0], &num_flag));
		s_list *loop_list = stack_a; //link to list head
		w = 1;
		while (split_num[w] != NULL)
		{
			if (arg_is_dup(argv) == 1 || arg_is_num(argv) == 1)
			{
				return (write(2, "Error\n", 6), 1);
			}
			ft_listadd_back(&loop_list, ft_listnew(to_num(split_num[w], &num_flag)));
			if (num_flag == 1)
			{
				write(2, "Error\n", 6);
				return(1);
			}
			loop_list = loop_list->next;
			w++;
		}
		s_list *head_ptr = stack_a; // to reset the position back to list head
		while(head_ptr != NULL)
		{
			printf("-sep list preview after split: %d\n", head_ptr->data);
			head_ptr = head_ptr->next;
		}
	}
	else
	{
		// printf("idk something is wrong with the code up there mate figure it out\n");
		return (err_ret(), 1);
	}
}