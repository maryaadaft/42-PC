#include "push_swap.h"


int	main(int argc, char **argv)
{
	// 1st handle the parse of arguments without "" so no split
	// then add them into the stack ??? bismillah

	//make push fn to add things to list
	if (argc > 1)
	{
		int i = 1; //increment to go through the arguments
		s_list *stack_a = NULL;
		s_list *loop_list = stack_a;
		s_list *head_ptr = stack_a; // to reset the position back to the 1st node


		while (i < (argc))
		{
			//push arguments to the stack until argc goes into 1??
			loop_list = ft_lstnew(mini_atoi(argv[i]));
			printf("what are u: %d\n", loop_list->data);
			loop_list = loop_list->next;
			// argc--;
			i++;
		}
		loop_list = head_ptr;
		while(loop_list != NULL) 
		{
			printf("%d\n", loop_list->data);
			loop_list = loop_list->next;
		}
	}
	else
		printf("idk something is wrong with the code up there mate figure it out\n");

}