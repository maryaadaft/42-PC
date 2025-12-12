/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:19:41 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/03 10:14:58 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*abdu_the_kiddo;

	abdu_the_kiddo = malloc(sizeof(t_list));
	if (abdu_the_kiddo == NULL)
		return (NULL);
	abdu_the_kiddo->content = content;
	abdu_the_kiddo->next = NULL;
	return (abdu_the_kiddo);
}
