/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:34:41 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/04 09:16:48 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*destiny;
	size_t	len;
	size_t	i;

	i = 0;
	if (count == 0)
		return (malloc(0));
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	len = count * size;
	destiny = malloc(count * size);
	if (destiny == NULL)
		return (NULL);
	if (destiny != NULL)
	{
		while (i < len)
		{
			destiny[i] = 0;
			i++;
		}
	}
	return ((void *)destiny);
}
