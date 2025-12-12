/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:33:02 by maryaada          #+#    #+#             */
/*   Updated: 2025/11/07 22:30:53 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cs_dip(const char *p_str, int *in, va_list my_args)
{
	int	p_counter;

	p_counter = 0;
	if (p_str[*in + 1] == 'c')
		p_counter = ft_putchar(va_arg(my_args, int));
	else if (p_str[*in + 1] == 's')
		p_counter = ft_putstr(va_arg(my_args, char *));
	else if (p_str[*in + 1] == 'd' || p_str[*in + 1] == 'i')
		p_counter = ft_putnbr(va_arg(my_args, int));
	else if (p_str[*in + 1] == '%')
		p_counter = ft_putchar('%');
	(*in)++;
	if (p_counter < 0)
		return (-1);
	return (p_counter);
}

static int	up_xx(const char *p_str, int *in, va_list my_args)
{
	int	p_counter;

	p_counter = 0;
	if (p_str[*in + 1] == 'x')
		p_counter = ft_lower_hex(va_arg(my_args, unsigned int));
	else if (p_str[*in + 1] == 'X')
		p_counter = ft_upper_hex(va_arg(my_args, unsigned int));
	else if (p_str[*in + 1] == 'u')
		p_counter = ft_un_nbr(va_arg(my_args, unsigned int));
	else if (p_str[*in + 1] == 'p')
		p_counter = ft_point(va_arg(my_args, void *));
	(*in)++;
	if (p_counter < 0)
		return (-1);
	return (p_counter);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		p_counter;
	int		p_return;
	va_list	my_args;

	va_start(my_args, s);
	i = 0;
	p_counter = 0;
	p_return = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' && (s[i + 1] == 'c' || (s[i + 1] == 's')
				|| (s[i + 1] == 'd') || (s[i + 1] == 'i') || (s[i + 1] == '%')))
			p_counter = cs_dip(s, &i, my_args);
		else if (s[i] == '%' && (s[i + 1] == 'x' || (s[i + 1] == 'X')
				|| (s[i + 1] == 'u') || (s[i + 1] == 'p')))
			p_counter = up_xx(s, &i, my_args);
		else
			p_counter = ft_putchar(s[i]);
		i++;
		if (p_counter < 0)
			return (va_end(my_args), -1);
		p_return += p_counter;
	}
	return (va_end(my_args), p_return);
}
