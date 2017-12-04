/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:05 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_count_flag(char *s)
{
	int i;

	i = 0;
	while (ft_isflag(s[i]))
		i++;
	return (i);
}

int		ft_count_width(char *s)
{
	int i;

	i = 0;
	if (s[i] == '*')
		return (1);
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int		ft_count_precision(char *s)
{
	int i;

	i = 0;
	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
			return (2);
		while (ft_isdigit(s[i]))
			i++;
	}
	return (i);
}

int		ft_count_conversion(char *s)
{
	if (s[0] == 'h' && s[1] == 'h')
		return (2);
	if (s[0] == 'l' && s[1] == 'l')
		return (2);
	if (s[0] == 'h' && s[1] != 'h')
		return (1);
	if (s[0] == 'l' && s[1] != 'l')
		return (1);
	if (s[0] == 'j')
		return (1);
	if (s[0] == 'z')
		return (1);
	return (0);
}

int		ft_get_count(char *s)
{
	int	count;

	count = 0;
	count += ft_count_flag(s);
	count += ft_count_width(&s[count]);
	count += ft_count_precision(&s[count]);
	count += ft_count_conversion(&s[count]);
	if (ft_isalpha(s[count]) || s[count] == '%')
		count += 1;
	return (count);
}
