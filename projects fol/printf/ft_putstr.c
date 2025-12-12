/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:52:15 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/11 12:51:30 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *string)
{
	int	i;

	i = 0;
	if (!string)
		return (ft_putstr("(null)"));
	while (string[i] != '\0')
	{
		if (write(1, &string[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}
