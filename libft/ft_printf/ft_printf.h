/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrafael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:43:33 by lrafael           #+#    #+#             */
/*   Updated: 2024/05/25 18:43:38 by lrafael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(const char *str);
int		ft_putchar(char c);

void	ft_putnbr(int nbr, int *count);
void	ft_unsigned_putnbr(unsigned int nbr, int *count);
void	ft_hex_putnbr(unsigned int nbr, char c, int *count);
void	ft_putptr(unsigned long long p, int *count);
void	ft_printxp(unsigned long long nbr, int *count);

#endif
