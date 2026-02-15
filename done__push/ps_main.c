/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:49:22 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/15 17:02:05 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(char	**args, t_list	**stack_a)
{
	int	i;
	int	over;
	int	data;

	i = 0;
	while (args[i] != NULL)
	{
		if (arg_is_num(args[i]) == 0)
			return (free_split_args(args), free_all_stack(stack_a), err_ret());
		over = 0;
		data = to_num(args[i], &over);
		if (over == 1)
			return (free_split_args(args), free_all_stack(stack_a), err_ret());
		if (arg_is_dup(*stack_a, data) == 1)
		{
			free_split_args(args);
			free_all_stack(stack_a);
			err_ret();
		}
		ft_listadd_back(stack_a, ft_listnew(data));
		i++;
	}
}

void	parse_args(int argc, char **argv, t_list	**stack_a)
{
	int		i;
	char	**split_args;

	if (argc < 2)
		return ;
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		list_size;

	stack_a = NULL;
	stack_b = NULL;
	parse_args(argc, argv, &stack_a);
	list_size = ft_listsize(stack_a);
	if (list_size == 2 && !is_list_sorted(&stack_a))
		sort_two(&stack_a);
	else if (list_size == 3 && !is_list_sorted(&stack_a))
		sort_three(&stack_a);
	else if (list_size > 3 && !is_list_sorted(&stack_a))
		sort_turk(&stack_a, &stack_b);
	free_all_stack(&stack_a);
	free_all_stack(&stack_b);
}
