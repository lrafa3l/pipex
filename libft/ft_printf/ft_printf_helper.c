/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:04:55 by lrafael           #+#    #+#             */
/*   Updated: 2024/05/25 18:04:59 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	count;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

void	ft_putnbr(int nbr, int *count)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		(*count)++;
		ft_putnbr(147483648, count);
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1, count);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
		ft_putchar(nbr % 10 + '0');
	}
	else
	{
		ft_putchar(nbr + '0');
	}
	(*count)++;
}
