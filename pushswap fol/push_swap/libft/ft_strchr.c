/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:20:35 by maryaada          #+#    #+#             */
/*   Updated: 2025/07/17 16:43:52 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*car;

	i = 0;
	car = (char *)s;
	while (car[i])
	{
		if ((char)c == car[i])
		{
			return (car + i);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return (car + i);
	}
	return (NULL);
}
