/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:21:22 by octoross          #+#    #+#             */
/*   Updated: 2023/05/16 20:28:30 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_format(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (2 + ft_putnbr(va_arg(*ap, unsigned long), 1, 16));
	}
	else if (c == 'd')
		return (ft_putnbr(va_arg(*ap, int), 1, 10));
	else if (c == 'i')
		return (ft_putnbr(va_arg(*ap, int), 1, 10));
	else if (c == 'u')
		return (ft_putnbr(va_arg(*ap, unsigned int), 1, 10));
	else if (c == 'x')
		return (ft_putnbr(va_arg(*ap, int), 1, 16));
	else if (c == 'X')
		return (ft_putnbr(va_arg(*ap, int), 0, 16));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		len;

	if (!format)
		return (-1);
	len = 0;
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '\\')
			ft_putchar(format[i + 1]);
		else if (format[i] == '%')
			len += ft_format(format[i + 1], &ap);
		else
			len += ft_putchar(format[i--]);
		i += 2;
	}
	va_end(ap);
	return (len);
}

int	main(int argc, char **argv)
{
	printf(NULL);
	ft_printf(NULL);

	ft_printf("caca furibond\n");
	printf("caca furibond\n");

	ft_printf("caca%p\n", argv[1]);
	printf("caca%p\n", argv[1]);

	ft_printf("caca%s\n", argv[1]);
	printf("caca%s\n", argv[1]);

	ft_printf("caca%c\n", argv[1][0]);
	printf("caca%c\n", argv[1][0]);

	return (0);
}
