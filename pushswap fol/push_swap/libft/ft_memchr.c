/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:07:41 by maryaada          #+#    #+#             */
/*   Updated: 2025/07/17 16:11:32 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*car;

	i = 0;
	car = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)c == car[i])
		{
			return (car + i);
		}
		i++;
	}
	return (NULL);
}
