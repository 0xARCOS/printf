/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarcos <aarcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:33:06 by aarcos            #+#    #+#             */
/*   Updated: 2025/02/09 09:56:52 by aarcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h> // Necesario para va_list, va_arg, va_start, va_end
# include <unistd.h> // Neccesario para write

//Funciones auxiliares
void	ft_putchar(char c, int *i);
void	ft_putnbr(int n, int *i);
void	ft_putstr(const char *str, int *i);
void	ft_puthex(unsigned long long n, char format, int *i);
void	ft_putptr(unsigned long long ptr, int *i);
void	ft_putnbr_unsigned(unsigned int n, int *i);

//Funciones principales
int		ft_printf(const char *fmt, ...);

#endif
