/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:57:01 by maryaada          #+#    #+#             */
/*   Updated: 2025/11/07 22:36:48 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	int	p_counter;
	int	ret_count;

	ret_count = 0;
	p_counter = 0;
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	if (num < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		p_counter += 1;
		num = -num;
	}
	if (num > 9)
	{
		ret_count = ft_putnbr(num / 10);
		if (ret_count == -1)
			return (-1);
		p_counter += ret_count;
	}
	if (write(1, &"0123456789"[num % 10], 1) == -1)
		return (-1);
	p_counter++;
	return (p_counter);
}
