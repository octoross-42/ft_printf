/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:41:03 by octoross          #+#    #+#             */
/*   Updated: 2023/05/16 20:18:56 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(long n, int lowercase, long base)
{
	char	hexa_base[17] = "0123456789abcdef";
	int		len;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len ++;
	}
	if (n >= base)
		len += ft_putnbr(n / base, lowercase, base);
	if (lowercase || (n % base < 10))
		ft_putchar(hexa_base[n % base]);
	else
		ft_putchar(ft_lowercasetouppercase(hexa_base[n % base]));
	len ++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
