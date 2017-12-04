/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:13 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isflag(char c)
{
	if (c == '#')
		return (1);
	if (c == '+')
		return (1);
	if (c == '-')
		return (1);
	if (c == ' ')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

int		ft_isconv(char c)
{
	if (c == 'h')
		return (1);
	if (c == 'l')
		return (1);
	if (c == 'j')
		return (1);
	if (c == 'z')
		return (1);
	return (0);
}

int		ft_istype(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (1);
	if (c == 'u' || c == 'U')
		return (1);
	if (c == 'o' || c == 'O')
		return (1);
	if (c == 'x' || c == 'X')
		return (1);
	if (c == 'c' || c == 'C')
		return (1);
	if (c == 's' || c == 'S')
		return (1);
	if (c == 'p' || c == '%')
		return (1);
	if (c == 'b' || c == 'B')
		return (1);
	return (0);
}

int		ft_is_precision(char *s)
{
	int i;

	i = -1;
	while (!ft_istype(s[++i]))
		if (s[i] == '.')
			return (1);
	return (0);
}
