/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:04:10 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

static void		unsign_arg(t_printf *pf, va_list ap)
{
	if (pf->type.hh == 1)
		pf->nb.oux = (unsigned char)va_arg(ap, int);
	else if (pf->type.h == 1)
		pf->nb.oux = (unsigned short)va_arg(ap, int);
	else if (pf->type.l == 1)
		pf->nb.oux = va_arg(ap, unsigned long);
	else if (pf->type.ll == 1)
		pf->nb.oux = va_arg(ap, unsigned long long);
	else if (pf->type.j == 1)
		pf->nb.oux = va_arg(ap, uintmax_t);
	else if (pf->type.z == 1)
		pf->nb.oux = va_arg(ap, size_t);
	else
		pf->nb.oux = va_arg(ap, unsigned int);
}

static void		sign_arg(t_printf *pf, va_list ap)
{
	if (pf->type.hh == 1)
		pf->nb.d_i = (char)va_arg(ap, int);
	else if (pf->type.h == 1)
		pf->nb.d_i = (short)va_arg(ap, int);
	else if (pf->type.l == 1)
		pf->nb.d_i = va_arg(ap, long);
	else if (pf->type.ll == 1)
		pf->nb.d_i = va_arg(ap, long long);
	else if (pf->type.j == 1)
		pf->nb.d_i = va_arg(ap, intmax_t);
	else if (pf->type.z == 1)
		pf->nb.d_i = va_arg(ap, ssize_t);
	else
		pf->nb.d_i = va_arg(ap, int);
}

void			good_arg(char *format, va_list ap, t_printf *pf)
{
	if (ft_strchr("sSpdDioOuUxXcC", *format))
	{
		if (*format == 'u' || *format == 'o' || *format == 'x' ||
				*format == 'X')
			unsign_arg(pf, ap);
		else if (*format == 'd' || *format == 'i')
			sign_arg(pf, ap);
		else if (*format == 'c' && pf->type.l != 1)
			pf->nb.c = (char)va_arg(ap, int);
		else if (*format == 's' && pf->type.l != 1)
			pf->nb.s = va_arg(ap, char *);
		else if (*format == 'p')
			pf->nb.p = va_arg(ap, void *);
		else if (*format == 'S' || (*format == 's' && pf->type.l == 1))
			pf->nb.s = va_arg(ap, wchar_t *);
		else if (*format == 'U')
			pf->nb.oux = (unsigned long)va_arg(ap, unsigned long);
		else if (*format == 'O')
			pf->nb.oux = (unsigned long)va_arg(ap, unsigned long);
		else if (*format == 'D')
			pf->nb.d_i = (long)va_arg(ap, long);
		else if (*format == 'C' || (*format == 'c' && pf->type.l == 1))
			pf->nb.wc = va_arg(ap, unsigned);
	}
}
