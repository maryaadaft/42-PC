/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:02:31 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/11 13:13:12 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_un_nbr(unsigned int num)
{
	int	p_counter;
	int	ret_count;

	ret_count = 0;
	p_counter = 0;
	if (num > 9)
	{
		ret_count = ft_un_nbr(num / 10);
		if (ret_count == -1)
			return (-1);
		p_counter += ret_count;
	}
	if (write(1, &"0123456789"[num % 10], 1) == -1)
		return (-1);
	p_counter++;
	return (p_counter);
}
