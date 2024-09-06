/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:05:05 by lrafael           #+#    #+#             */
/*   Updated: 2024/05/25 18:05:09 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printxp(unsigned long long nbr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr > 15)
		ft_printxp(nbr / 16, count);
	ft_putchar(base[nbr % 16]);
	(*count)++;
}

void	ft_putptr(unsigned long long p, int *count)
{
	if (p == 0)
	{
		ft_putstr("(nil)");
		(*count) += 5;
		return ;
	}
	ft_putstr("0x");
	(*count) += 2;
	ft_printxp(p, count);
}

void	ft_unsigned_putnbr(unsigned int nbr, int *count)
{
	if (nbr > 9)
	{
		ft_unsigned_putnbr(nbr / 10, count);
		ft_putchar(nbr % 10 + '0');
	}
	else
	{
		ft_putchar(nbr + '0');
	}
	(*count)++;
}

void	ft_hex_putnbr(unsigned int nbr, char c, int *count)
{
	char	*base;
	char	*base2;

	base = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (nbr > 15)
		ft_hex_putnbr(nbr / 16, c, count);
	if (c == 'X')
		ft_putchar(base2[nbr % 16]);
	else
		ft_putchar(base[nbr % 16]);
	(*count)++;
}
