/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:03:34 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*run_type_bis(char *format, t_printf *pf)
{
	if (*format == 'X')
		read_hexx(pf);
	else if (*format == 'o' || *format == 'O')
		read_octal(pf);
	else if (*format == 'u' || *format == 'U')
		read_u(pf);
	else if ((*format == 'c' && pf->type.l == 1) || (*format == 'C'))
		read_wchar(pf);
	else if ((*format == 's' && pf->type.l == 1) || (*format == 'S'))
		read_wstring(pf);
	else if (*format == '%')
		read_percent(pf);
	return (format);
}

char			*run_type(char *format, t_printf *pf)
{
	if (ft_strchr("sSpdDioOuUxXcC%", *format))
	{
		if (*format == 'c' && pf->type.l == 0)
			read_char(pf);
		else if (*format == 's' && pf->type.l == 0)
			read_string(pf);
		else if (*format == 'd' || *format == 'i' || *format == 'D')
			read_d_i(pf);
		else if (*format == 'p')
			read_pointer(pf);
		else if (*format == 'x')
			read_hex(pf);
		format = run_type_bis(format, pf);
	}
	else
		read_null(pf, *format);
	return (format);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	t_printf	pf;

	va_start(ap, format);
	pf.fd = fd;
	pf.index = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (format[1] == 0 || (format[1] == ' ' && format[2] == 0) ||
				(format[1] == ' ' && format[2] == 'h' && format[3] == 0))
				break ;
			format = parsing((char *)++format, &pf, ap);
			good_arg((char *)format, ap, &pf);
			format = run_type((char *)format, &pf);
		}
		else
			ft_putchar_pf(*format, &pf);
		++format;
	}
	va_end(ap);
	return (pf.index);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printf	pf;

	va_start(ap, format);
	pf.fd = STDOUT_FILENO;
	pf.index = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (format[1] == 0 || (format[1] == ' ' && format[2] == 0) ||
					(format[1] == ' ' && format[2] == 'h' && format[3] == 0))
				break ;
			format = parsing((char *)++format, &pf, ap);
			good_arg((char *)format, ap, &pf);
			format = run_type((char *)format, &pf);
		}
		else
			ft_putchar_pf(*format, &pf);
		++format;
	}
	va_end(ap);
	return (pf.index);
}
