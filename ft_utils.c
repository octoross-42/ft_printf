/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:53:51 by octoross          #+#    #+#             */
/*   Updated: 2023/10/09 14:24:28 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len ++;
	return (len);
}

char	ft_lowercasetouppercase(char c)
{
	return (c + ('A' - 'a'));
}

int	ft_strcmp(const char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i ++;
	return (s1[i] - s2[i]);
}
