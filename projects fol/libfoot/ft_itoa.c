/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:13:53 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/04 14:21:20 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	dig_counter(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count = 1;
		n = -n;
	}
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*arr;

	nbr = (long)n;
	len = dig_counter(nbr);
	arr = malloc(len + 1);
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	if (nbr == 0)
	{
		arr[0] = '0';
	}
	if (nbr < 0)
	{
		arr[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		arr[--len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (arr);
}
