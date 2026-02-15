/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:44:33 by maryaada          #+#    #+#             */
/*   Updated: 2026/02/14 19:53:06 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_is_num(char *argv)
{
	int	i;

	i = 0;
	if (!argv || !argv[0])
		return (0);
	if (argv[i] == '+' || argv[i] == '-')
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	arg_is_dup(t_list *stack, int data)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		if (current->data == data)
			return (1);
		current = current->next;
	}
	return (0);
}

void	err_ret(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split_args(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i] != NULL)
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	free_all_stack(t_list	**stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		free(tmp);
		head = head->next;
	}
	free(head);
}
