/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:59:55 by maryaada          #+#    #+#             */
/*   Updated: 2025/07/24 11:12:26 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	finding_nemo(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copied;
	int		end;
	int		start;

	start = 0;
	while (s1[start] != '\0' && (finding_nemo(set, s1[start])))
	{
		start++;
	}
	end = ft_strlen(s1);
	while (end > start && (finding_nemo(set, s1[end - 1])))
	{
		end--;
	}
	copied = ft_substr(s1, start, (end - start));
	if (copied == NULL)
	{
		return (NULL);
	}
	return (copied);
}
