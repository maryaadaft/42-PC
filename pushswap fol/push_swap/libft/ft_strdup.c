/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:03:02 by maryaada          #+#    #+#             */
/*   Updated: 2025/07/19 13:27:32 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*destiny;

	i = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	destiny = malloc((sizeof(char) * i) + 1);
	if (destiny == NULL)
	{
		return (NULL);
	}
	else
	{
		i = 0;
		while (s1[i] != '\0')
		{
			destiny[i] = s1[i];
			i++;
		}
		destiny[i] = '\0';
	}
	return (destiny);
}
