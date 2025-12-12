/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:38:01 by maryaada          #+#    #+#             */
/*   Updated: 2025/07/23 15:44:48 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*source;
	unsigned char		*destiny;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	source = (const unsigned char *)src;
	destiny = (unsigned char *)dst;
	if (destiny == source || (len == 0))
		return (dst);
	if (destiny < source)
	{
		i = 0;
		while (i < len)
		{
			destiny[i] = source[i];
			i++;
		}
	}
	else
	{
		while (len--)
			destiny[len] = source[len];
	}
	return (dst);
}
