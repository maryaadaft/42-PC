/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 15:13:21 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/11 13:13:51 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_point(void *p)
{
	int	p_counter;
	int	put_counter;

	p_counter = 0;
	put_counter = ft_putstr("0x");
	if (put_counter == -1)
		return (-1);
	p_counter += ft_lower_hex((uintptr_t)p);
	if (p_counter == -1)
		return (-1);
	p_counter += put_counter;
	return (p_counter);
}
