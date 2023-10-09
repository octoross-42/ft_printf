/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:41:03 by octoross          #+#    #+#             */
/*   Updated: 2023/10/09 14:20:40 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long	ft_cast_hex(int n)
{
	unsigned int	u;
	long			nbr;

	u = n;
	nbr = u;
	return (nbr);
}

int	ft_putnbr(long n, int uppercase, long base, int p)
{
	int			len;

	len = 0;
	if (p && n == 0)
		return (write(1, "(nil)", 5));
	if (p)
		len += write(1, "0x", 2);
	if (n < 0 && base == 10)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n < 0 && base == 16)
		n = ft_cast_hex(n);
	if (n >= base)
		len += ft_putnbr(n / base, uppercase, base, 0);
	if ((n % base) < 10)
		ft_putchar('0' + (n % base));
	else
		ft_putchar(('a' + (n % base - 10) + uppercase * ('A' - 'a')));
	len ++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
