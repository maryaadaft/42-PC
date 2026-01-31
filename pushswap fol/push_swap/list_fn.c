/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:55:55 by maryaada          #+#    #+#             */
/*   Updated: 2025/12/10 18:12:16 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_listadd_back(s_list **lst, s_list *new)
{
	s_list	*last;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

s_list	*ft_listnew(int data)
{
	s_list	*create_list;

	create_list = malloc(sizeof(s_list));
	if (create_list == NULL)
		return (NULL);
	create_list->data = data;
	create_list->next = NULL;
	return (create_list);
}

int	ft_listsize(s_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
