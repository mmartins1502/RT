/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:44:13 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	*g_format_derivate;

void		ft_init_len_count(t_format *format)
{
	LEN = 0;
	LEN_WIDE = 0;
	LEN_FILL_LEFT = 0;
	LEN_FILL_RIGHT = 0;
	PRECISION_TO_FILL = 0;
	FILL_BLANKS_LEFT = 0;
	FILL_BLANKS_RIGHT = 0;
	FILL_ZEROS_LEFT = 0;
	IS_OCTOTHORP = 0;
}

void		ft_modular_precision(t_format *format, va_list arg)
{
	if (format->precision == -1)
	{
		format->precision = va_arg(arg, int);
		if (format->precision < 0)
			format->is_precision = 0;
	}
}

void		ft_modular_width(t_format *format, va_list arg)
{
	if (format->width == -1)
	{
		format->width = va_arg(arg, int);
		if (format->width < 0)
		{
			format->width = -format->width;
			format->flags[1] = '-';
		}
	}
}

void		ft_get_params(t_format *format, char *s, va_list arg)
{
	format->count = ft_get_count(s);
	format->flags[0] = ft_get_flags(s, '#');
	format->flags[1] = ft_get_flags(s, '-');
	format->flags[2] = ft_get_flags(s, '+');
	format->flags[3] = ft_get_flags(s, ' ');
	format->flags[4] = ft_get_flags(s, '0');
	format->flags[5] = '\0';
	format->width = ft_get_width(s);
	ft_modular_width(format, arg);
	format->is_precision = ft_is_precision(s);
	format->precision = ft_get_precision(s);
	ft_modular_precision(format, arg);
	ft_strncpy(format->type, "\0\0\0\0", 4);
	ft_strncat(format->type, ft_get_convertion(s), 3);
	ft_strncat(format->type, ft_get_type(s, format), 1);
}

int			ft_printf(char *s, ...)
{
	int			i;
	va_list		arg;
	t_format	format;
	int			count;

	g_format_derivate = &format;
	g_format_derivate->fd = STDOUT_FILENO;
	i = -1;
	va_start(arg, s);
	count = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			ft_get_params(&format, &s[++i], arg);
			count += ft_handle_args(arg, &format);
			i += format.count - 1;
		}
		else
			count += ft_putchar_count(s[i], 1);
	}
	va_end(arg);
	return (count);
}
