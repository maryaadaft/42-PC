/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lower_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:09:07 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/11 13:13:42 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lower_hex(unsigned long hex)
{
	int	p_counter;
	int	ret_count;

	ret_count = 0;
	p_counter = 0;
	if (hex >= 16)
	{
		ret_count = ft_lower_hex(hex / 16);
		if (ret_count == -1)
			return (-1);
		p_counter += ret_count;
	}
	if (write(1, &"0123456789abcdef"[hex % 16], 1) == -1)
		return (-1);
	p_counter++;
	return (p_counter);
}
