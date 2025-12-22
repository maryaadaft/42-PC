/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:38:34 by maryaada          #+#    #+#             */
/*   Updated: 2025/07/17 16:51:09 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*rev;

	i = 0;
	rev = (char *) s;
	while (rev[i])
	{
		i++;
	}
	len = i;
	if ((char)c == '\0')
	{
		return (rev + len);
	}
	while (len > 0)
	{
		len--;
		if ((char)c == rev[len])
		{
			return (rev + len);
		}
	}
	return (NULL);
}
