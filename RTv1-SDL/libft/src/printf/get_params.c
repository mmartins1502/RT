/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_get_flags(char *s, char flag)
{
	int i;

	i = 0;
	while (ft_isflag(s[i]) != 0)
	{
		if (s[i] == flag)
			return (flag);
		i++;
	}
	return ('X');
}

int		ft_get_width(char *s)
{
	int i;
	int width;

	i = 0;
	width = 0;
	while (ft_isflag(s[i]))
		i++;
	if (s[i] == '*')
		return (-1);
	while (s[i] != '.' && !ft_isconv(s[i]) && \
		!ft_istype(s[i]) && ft_isdigit(s[i]))
	{
		width *= 10;
		width += s[i] - '0';
		i++;
	}
	return (width);
}

int		ft_get_precision(char *s)
{
	int i;
	int precision;

	i = 0;
	precision = 0;
	while (ft_istype(s[i]) == 0 && ft_isconv(s[i]) == 0 && s[i])
	{
		if (s[i] == '.')
		{
			i++;
			if (s[i] == '*')
				return (-1);
			while ((ft_isdigit(s[i]) || s[i] == '*') && !ft_istype(s[i]) && \
					!ft_isconv(s[i]))
			{
				precision *= 10;
				precision += s[i] - '0';
				i++;
			}
			return (precision);
		}
		i++;
	}
	return (0);
}

char	*ft_get_convertion(char *s)
{
	int i;

	i = 0;
	while (!ft_isconv(s[i]) && !ft_istype(s[i]) && s[i])
		i++;
	if (s[i] == 'h' && s[i + 1] == 'h')
		return ("hh");
	if (s[i] == 'h' && s[i + 1] != 'h')
		return ("h");
	if (s[i] == 'l' && s[i + 1] == 'l')
		return ("ll");
	if (s[i] == 'l' && s[i + 1] != 'l')
		return ("l");
	if (s[i] == 'j')
		return ("j");
	if (s[i] == 'z')
		return ("z");
	return ("");
}

char	*ft_get_type(char *s, t_format *format)
{
	int i;

	i = 0;
	while (!ft_istype(s[i]) && s[i])
	{
		if (ft_isflag(s[i]) || ft_isconv(s[i]) || (ft_isdigit(s[i]) || \
			s[i] == '*') || (ft_is_precision(&s[i]) || s[i] == '*'))
			i++;
		else if (ft_isalpha(s[i]))
		{
			NO_FORMAT = s[i];
			return ("@");
		}
		else
		{
			NO_FORMAT = 0;
			return ("@");
		}
	}
	if (s[i] == 'd' || s[i] == 'i')
		return ("d");
	if (s[i] == '\0')
		return ("@");
	return (&s[i]);
}
