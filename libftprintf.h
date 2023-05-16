/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:18:02 by octoross          #+#    #+#             */
/*   Updated: 2023/05/16 19:29:06 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putnbr(long n, int lowercase, long base);
int		ft_putstr(char *s);
int		ft_putchar(char c);

char	ft_lowercasetouppercase(char c);
size_t	ft_strlen(char *s);
int		ft_strcmp(const char *s1, char *s2);

#endif