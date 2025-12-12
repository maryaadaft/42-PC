/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maryaada <maryaada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:38:36 by maryaada          #+#    #+#             */
/*   Updated: 2025/08/10 19:02:11 by maryaada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *p_s, ...);
int	ft_putstr(char *string);
int	ft_putchar(char c);
int	ft_putnbr(int num);
int	ft_un_nbr(unsigned int num);
int	ft_lower_hex(unsigned long hex);
int	ft_upper_hex(unsigned long hex);
int	ft_point(void *p);

#endif