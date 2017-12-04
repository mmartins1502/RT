/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 13:56:56 by qselle            #+#    #+#             */
/*   Updated: 2017/05/08 15:32:40 by qselle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		read_char(t_printf *pf)
{
	while (pf->size_len - 1 > 0 && pf->flag.minus == 0)
	{
		pf->flag.zero == 1 ? ft_putchar_pf('0', pf) : ft_putchar_pf(' ', pf);
		pf->size_len--;
	}
	ft_putchar_pf(pf->nb.c, pf);
	while (pf->size_len - 1 > 0 && pf->flag.minus == 1)
	{
		ft_putchar_pf(' ', pf);
		pf->size_len--;
	}
}

void		read_wchar(t_printf *pf)
{
	while (pf->size_len - 1 > 0 && pf->flag.minus == 0)
	{
		pf->flag.zero == 1 ? ft_putchar_pf('0', pf) : ft_putchar_pf(' ', pf);
		pf->size_len--;
	}
	ft_putwchar_pf(pf->nb.wc, pf);
	while (pf->size_len - 1 > 0 && pf->flag.minus == 1)
	{
		ft_putwchar_pf(' ', pf);
		pf->size_len--;
	}
}

static void	string_bis(t_printf *pf)
{
	if (!pf->nb.s)
	{
		pf->nb.s = ft_strdup("(null)");
		pf->count++;
	}
}

void		read_string(t_printf *pf)
{
	int		a;

	pf->count = 0;
	pf->precision == -1 && pf->flag.point == 1 ? pf->precision = 0 : 0;
	string_bis(pf);
	a = ft_strlen(pf->nb.s);
	pf->precision < a && pf->precision >= 0 ? a = pf->precision : 0;
	while (pf->size_len - a > 0 && pf->flag.minus == 0)
	{
		pf->flag.zero == 1 ? ft_putchar_pf('0', pf) : ft_putchar_pf(' ', pf);
		pf->size_len--;
	}
	pf->precision < (int)ft_strlen(pf->nb.s) && pf->precision >= 0 ?
		ft_putstr_lim_pf(pf->nb.s, pf->precision, pf) :
		ft_putstr_pf(pf->nb.s, pf);
	if (pf->count == 1)
	{
		free(pf->nb.s);
		pf->nb.s = NULL;
	}
	while (pf->size_len - a > 0 && pf->flag.minus == 1)
	{
		ft_putchar_pf(' ', pf);
		pf->size_len--;
	}
}

void		read_wstring(t_printf *pf)
{
	int		a;

	pf->precision == -1 && pf->flag.point == 1 ? pf->precision = 0 : 0;
	if (pf->nb.s == NULL)
	{
		read_string(pf);
		return ;
	}
	a = ft_strwlen(pf->nb.s);
	pf->precision < a && pf->precision >= 0 ? a = pf->precision : 0;
	while (pf->size_len - a > 0 && pf->flag.minus == 0)
	{
		pf->flag.zero == 1 ? ft_putchar_pf('0', pf) : ft_putchar_pf(' ', pf);
		pf->size_len--;
	}
	pf->precision < ((int)ft_strwlen(pf->nb.s)) && pf->precision >= 0 ?
		ft_putwstr_lim_pf(pf->nb.s, pf->precision, pf) :
		ft_putwstr_pf(pf->nb.s, pf);
	while (pf->size_len - a > 0 && pf->flag.minus == 1)
	{
		ft_putchar_pf(' ', pf);
		pf->size_len--;
	}
}
