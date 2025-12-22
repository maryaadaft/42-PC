/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:17:42 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/04 14:47:03 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*bee;
	size_t			i;

	bee = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bee[i] = c;
		i++;
	}
	return (b);
}
