/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:19:18 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/03 23:01:14 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*destiny;
	unsigned char	*source;
	size_t			i;

	destiny = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (destiny == 0 && source == 0)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		destiny[i] = source[i];
		i++;
	}
	return (destiny);
}
