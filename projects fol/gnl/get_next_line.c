/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:05:01 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/30 11:52:13 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	if_error(char **buffy, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (0);
	*buffy = malloc(BUFFER_SIZE + 1);
	if (*buffy == NULL)
		return (0);
	return (1);
}

int	all_read(char **buffy, char **rem_file, ssize_t *rytes, int fd)
{
	char	*temp;

	temp = NULL;
	*rytes = read(fd, *buffy, BUFFER_SIZE);
	if (*rytes < 0)
		return (end_this(buffy), end_this(rem_file), 0);
	(*buffy)[*rytes] = '\0';
	if (*rytes == 0 && !(*rem_file))
		return (end_this(buffy), 0);
	if (*rem_file)
	{
		temp = ft_strjoin(*rem_file, *buffy);
		end_this(rem_file);
		end_this(buffy);
		*buffy = temp;
	}
	return (1);
}

char	*newl_ptr(char *nl_ptr, char **rem_file, char **buffy)
{
	char	*temp;

	temp = NULL;
	if (nl_ptr)
	{
		*rem_file = ft_strdup(nl_ptr + 1);
		*(nl_ptr + 1) = '\0';
		if (*rem_file && **rem_file == '\0')
			end_this(rem_file);
		temp = *buffy;
		return (temp);
	}
	return (NULL);
}

char	*reach_end(char **rem_file)
{
	char	*temp;

	temp = NULL;
	if (*rem_file)
	{
		temp = ft_strdup(*rem_file);
		end_this(rem_file);
		return (temp);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*rem_file;
	char		*buffy;
	char		*nl_ptr;
	ssize_t		rytes;

	if (!if_error(&buffy, fd))
		return (NULL);
	rytes = 1;
	while (rytes > 0)
	{
		if (!(all_read(&buffy, &rem_file, &rytes, fd)))
			return (NULL);
		nl_ptr = ft_strchr(buffy, '\n');
		if (nl_ptr)
			return (newl_ptr(nl_ptr, &rem_file, &buffy));
		else
			rem_file = ft_strdup(buffy);
	}
	end_this(&buffy);
	if (rem_file)
		return (reach_end(&rem_file));
	return (NULL);
}
