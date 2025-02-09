/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcos <aarcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:48:59 by aarcos            #+#    #+#             */
/*   Updated: 2025/02/09 10:00:43 by aarcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(va_list *args, const char *fmt, int *i)
{
	if (*fmt == 'c')
		ft_putchar(va_arg(*args, int), i);
	else if (*fmt == 's')
		ft_putstr(va_arg(*args, char *), i);
	else if (*fmt == 'd')
		ft_putnbr(va_arg(*args, int), i);
	else if (*fmt == 'i')
		ft_putnbr(va_arg(*args, int), i);
	else if (*fmt == '%')
		ft_putchar('%', i);
	else if (*fmt == 'p')
		ft_putptr(va_arg(*args, unsigned long long), i);
	else if (*fmt == 'u')
		ft_putnbr_unsigned(va_arg(*args, unsigned int), i);
	else if (*fmt == 'x' || *fmt == 'X')
		ft_puthex(va_arg(*args, unsigned int), *fmt, i);
	else
	{
		ft_putchar('%', i);
		ft_putchar(*fmt, i);
	}
}

int	ft_printf(const char *fmt, ...)
{
	int	i;

	va_list		args;

	va_start (args, fmt);
	i = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			print_format(&args, fmt, &i);			
		}
		else
			ft_putchar (*fmt, &i);
		fmt++;
	}
	va_end(args);
	return (i);
}
