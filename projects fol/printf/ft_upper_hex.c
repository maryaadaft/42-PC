/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upper_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:11:44 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/11 13:12:30 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upper_hex(unsigned long hex)
{
	int	p_counter;
	int	ret_count;

	ret_count = 0;
	p_counter = 0;
	if (hex >= 16)
	{
		ret_count = ft_upper_hex(hex / 16);
		if (ret_count == -1)
			return (-1);
		p_counter += ret_count;
	}
	if (write(1, &"0123456789ABCDEF"[hex % 16], 1) == -1)
		return (-1);
	p_counter++;
	return (p_counter);
}
