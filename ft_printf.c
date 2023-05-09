/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:21:22 by octoross          #+#    #+#             */
/*   Updated: 2023/05/09 18:37:39 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '\\')
		{
			ft_putchar(format[i + 1]);
			i ++;
		}
		else if (format[i] == '%')
		{
			i ++;
			if (format[i] == 'c')
				ft_putchar((char)va_arg(ap, int));
			else if (format[i] == 's')
				ft_putstr(va_arg(ap, char *));
			else if (format[i] == 'p')
			{
				write(1, "0x", 2);
				ft_putnbr(va_arg(ap, unsigned long), 1, 16);
			}
			else if (format[i] == 'd')
				ft_putnbr(va_arg(ap, int), 1, 10);
			else if (format[i] == 'i')
				ft_putnbr(va_arg(ap, int), 1, 10);
			else if (format[i] == 'u')
				ft_putnbr(va_arg(ap, unsigned int), 1, 10);
			else if (format[i] == 'x')
				ft_putnbr(va_arg(ap, int), 1, 16);
			else if (format[i] == 'X')
				ft_putnbr(va_arg(ap, int), 0, 16);
			else if (format[i] == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(format[i]);
		i ++;
	}
	va_end(ap);
	return (0);
}

int	main(int argc, char **argv)
{
	ft_printf("caca\%\n");
	printf("\n\ncaca\%\n");
	return (0);
}
