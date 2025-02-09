/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcos <aarcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:54:34 by aarcos            #+#    #+#             */
/*   Updated: 2025/02/09 09:56:17 by aarcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *i)
{
	write (1, &c, 1);
	(*i)++;
}

void	ft_putnbr_unsigned(unsigned int n, int *i)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10, i);
	ft_putchar((n % 10) + '0', i);
}

void	ft_putstr(const char *str, int *i)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (0);
	}
	while (*str)
		ft_putchar(*str++, i);
}

void	ft_putnbr(int n, int *i)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", i);
		return (0);
	}
	if (n < 0)
	{
		ft_putchar('-', i);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, i);
	ft_putchar((n % 10) + '0', i);
}

void	ft_putptr(unsigned long long ptr, int *i)
{
	if (ptr == 0)
	{
		ft_putstr("(null)", i);
		return (0);
	}
	ft_putstr("0x", i);
	ft_puthex(ptr, 'x', i);
}
