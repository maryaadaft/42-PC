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
	s_list	*abdu_the_kiddo;

	abdu_the_kiddo = malloc(sizeof(s_list));
	if (abdu_the_kiddo == NULL)
		return (NULL);
	abdu_the_kiddo->data = data;
	abdu_the_kiddo->next = NULL;
	return (abdu_the_kiddo);
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
