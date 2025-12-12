/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:21:12 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/29 09:58:27 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*car;

	if (!s)
		return (NULL);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	joined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (joined == NULL)
		return (NULL);
	i = 0;
	while ((s1[i]))
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined[i++] = s2[j++];
	}
	joined[i] = '\0';
	return (joined);
}

void	end_this(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
