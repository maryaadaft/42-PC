#include "push_swap.h"


int	main(int argc, char **argv)
{
	//make push fn to add things to list
	if (argc > 2)
	{
		int i = 2; //increment to go through the arguments, starts at 2 cause lstnew will take the 1st arg for the head of the list
		s_list *stack_a = NULL;

		stack_a = ft_listnew(mini_atoi(argv[1]));
		s_list *loop_list = stack_a;
		while (i < (argc))
		{
			//push arguments to the stack until no arg remain
			ft_listadd_back(&loop_list, ft_listnew(mini_atoi(argv[i])));
			loop_list = loop_list->next;
			i++;
		}
		s_list *head_ptr = stack_a; // to reset the position back to the 1st node
		while(head_ptr != NULL) 
		{
			printf("list has %d\n", head_ptr->data);
			head_ptr = head_ptr->next;
		}
		printf("lst size is: %d\n", ft_listsize(stack_a));
	}
	else if (argc == 2)
	{
		// if arg is inside a "" so time to call split fn *crying*

		//1st split √
		//then save them in a string √
		//then give them to mini_atoi √
		//then repeat above (so make it into its own fn) √

		char **split_num = ft_split(argv[1], ' '); //split the argument into strings
		int w = 0;
		s_list *stack_a = NULL; 

		stack_a = ft_listnew(mini_atoi(split_num[0])); //1st string inside split num is now inside the stack
		//using a different pointer to go through the stack list
		s_list *loop_list = stack_a;
		w = 1;
		while (split_num[w] != NULL)
		{
			ft_listadd_back(&loop_list, ft_listnew(mini_atoi(split_num[w])));
			loop_list = loop_list->next;
			w++;
		}
		s_list *head_ptr = stack_a; // to reset the position back to the 1st node
		while(head_ptr != NULL)
		{
			printf("\nsep list preview after split: %d\n", head_ptr->data);
			head_ptr = head_ptr->next;
		}
	}
	else
		printf("idk something is wrong with the code up there mate figure it out\n");

}