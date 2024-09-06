/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:06:07 by lrafael           #+#    #+#             */
/*   Updated: 2024/05/25 17:52:23 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	check_format(va_list args, char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, const char *));
	else if (format == 'p')
		ft_putptr(va_arg(args, unsigned long), &count);
	else if (format == 'd' || format == 'i')
		ft_putnbr((int)va_arg(args, int), &count);
	else if (format == 'u')
		ft_unsigned_putnbr(va_arg(args, unsigned int), &count);
	else if (format == 'x' || format == 'X')
		ft_hex_putnbr(va_arg(args, unsigned int), format, &count);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += check_format(args, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
