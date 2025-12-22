/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:08:55 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/03 23:11:31 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlength;

	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	dstlength = ft_strlen(dst);
	while (src[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0' && (dstlength + i + 1) < dstsize)
	{
		dst[dstlength + i] = src[i];
		i++;
	}
	if (dstlength + i < dstsize)
		dst[dstlength + i] = '\0';
	if (dstlength >= dstsize)
	{
		return (dstsize + j);
	}
	return (dstlength + j);
}
