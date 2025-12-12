/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:46:38 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/04 10:19:00 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cop;
	t_list	*tempo;
	void	*hold;

	if (lst == NULL || f == NULL)
		return (NULL);
	cop = NULL;
	tempo = NULL;
	while (lst != NULL)
	{
		hold = f(lst->content);
		tempo = ft_lstnew(hold);
		if (tempo == NULL)
		{
			del(hold);
			ft_lstclear(&cop, del);
			return (NULL);
		}
		ft_lstadd_back(&cop, tempo);
		lst = lst->next;
	}
	return (cop);
}
