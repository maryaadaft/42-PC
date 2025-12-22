/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:00:44 by maryaada          #+#    #+#             */
/*   Updated: 2025/07/16 20:39:33 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pstr1;
	const unsigned char	*pstr2;
	size_t				i;

	i = 0;
	pstr1 = (const unsigned char *)s1;
	pstr2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (pstr1[i] > pstr2[i])
		{
			return (pstr1[i] - pstr2[i]);
		}
		else if (pstr1[i] < pstr2[i])
		{
			return (pstr1[i] - pstr2[i]);
		}
		i++;
	}
	return (0);
}
