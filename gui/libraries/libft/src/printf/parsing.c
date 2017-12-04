/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:28:52 by qselle            #+#    #+#             */
/*   Updated: 2017/05/08 17:22:44 by quentinselle     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_precision(char *format, t_printf *pf)
{
	pf->flag.zero_percent = 0;
	if (*format == '.')
	{
		pf->flag.point = 1;
		++format;
		if (ft_strchr("0123456789", *format))
			pf->precision = ft_atoi(format);
		while (ft_strchr("0123456789", *format))
			++format;
	}
	pf->flag.zero == 1 ? pf->flag.zero_percent = 1 : 0;
	pf->precision > 0 ? pf->flag.zero = 0 : 0;
	return (format);
}

char	*check_convert(char *format, t_printf *pf)
{
	pf->type.h = 0;
	pf->type.hh = 0;
	pf->type.l = 0;
	pf->type.ll = 0;
	pf->type.j = 0;
	pf->type.z = 0;
	while (ft_strchr("hljz", *format))
	{
		if (*format == 'j')
			pf->type.j = 1;
		else if (*format == 'z')
			pf->type.z = 1;
		else if (*format == 'h')
			converth_bis(pf, format);
		else if (*format == 'l')
			convertl_bis(pf, format);
		++format;
	}
	return (format);
}

char	*check_len(char *format, t_printf *pf)
{
	if (ft_strchr("123456789", *format))
	{
		pf->size_len = ft_atoi(format);
		while (ft_strchr("0123456789", *format))
			++format;
	}
	return (format);
}

char	*check_flag(char *format, t_printf *pf)
{
	while (ft_strchr("-+ #0", *format))
	{
		if (*format == '-')
			pf->flag.minus = 1;
		else if (*format == '+')
			pf->flag.plus = 1;
		else if (*format == ' ')
			pf->flag.space = 1;
		else if (*format == '#')
			pf->flag.diez = 1;
		else if (*format == '0')
			pf->flag.zero = 1;
		++format;
	}
	(pf->flag.zero == 1 && pf->flag.minus == 1) ? pf->flag.zero = 0 : 0;
	(pf->flag.space == 1 && pf->flag.plus == 1) ? pf->flag.space = 0 : 0;
	return (format);
}

char	*parsing(char *format, t_printf *pf, va_list ap)
{
	pf->flag.minus = 0;
	pf->flag.plus = 0;
	pf->flag.space = 0;
	pf->flag.diez = 0;
	pf->flag.zero = 0;
	pf->size_len = 0;
	pf->precision = -1;
	pf->flag.percent = 1;
	pf->flag.point = 0;
	if (*format == '*')
	{
		wildcard_bonus(pf, ap);
		++format;
	}
	format = check_flag(format, pf);
	format = check_len(format, pf);
	format = check_precision(format, pf);
	format = check_convert(format, pf);
	format = check_flag(format, pf);
	if (*format == '*')
	{
		wildcard_bonus(pf, ap);
		++format;
	}
	return (format);
}
