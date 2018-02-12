/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:04:07 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void			pointer_bis(t_printf *pf, intmax_t without, intmax_t a, char *s)
{
	pf->flag.diez == 1 ? a += 1 : 0;
	pf->nb_z = calcul_zero_u(pf, a, without);
	pf->nb_s = calcul_space_u(pf, a, without, pf->nb_z);
	pf->nb_s > 0 && pf->flag.minus == 0 ?
		ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
	ft_putstr_pf("0x", pf);
	pf->flag.diez == 1 && pf->nb.p != 0 ? ft_putstr_pf("0", pf) : 0;
	pf->nb_z > 0 ? ft_putnchar_pf('0', pf->nb_z, pf) : 0;
	if (pf->nb.p == 0 && (pf->precision == 0 || pf->precision == -1) &&
			pf->flag.point == 1)
		return ;
	else if (pf->nb.p == 0 && pf->precision >= 1)
		ft_putstr_pf("0", pf);
	else
		ft_putstr_pf(s, pf);
}

void			read_pointer(t_printf *pf)
{
	intmax_t	a;
	intmax_t	without;
	char		*s;

	pf->nb_s = 0;
	pf->nb_z = 0;
	if (pf->flag.diez == 0)
	{
		if (check_nothing_u(pf) == 1)
			return ;
	}
	s = ft_itoa_base((intmax_t)pf->nb.p, 16);
	a = ft_strlen(s) + 2;
	without = ft_strlen(s);
	pointer_bis(pf, without, a, s);
	free(s);
	s = NULL;
	pf->nb_s > 0 && pf->flag.minus == 1 ?
		ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
}

void			read_percent(t_printf *pf)
{
	while ((pf->size_len - 1) > 0 && pf->flag.minus == 0)
	{
		pf->flag.zero == 1 || pf->flag.zero_percent == 1 ?
			ft_putchar_pf('0', pf) : ft_putchar_pf(' ', pf);
		pf->size_len--;
	}
	ft_putchar_pf('%', pf);
	while (pf->size_len - 1 > 0 && pf->flag.minus == 1)
	{
		pf->flag.zero == 0 ? ft_putchar_pf(' ', pf) : 0;
		pf->size_len--;
	}
}

void			read_null(t_printf *pf, char c)
{
	intmax_t	a;
	intmax_t	without;

	pf->nb_s = 0;
	pf->nb_z = 0;
	a = 1;
	without = 1;
	pf->nb_z = calcul_zero_u(pf, a, without);
	pf->flag.space == 1 && pf->flag.zero == 1 ? pf->nb_z-- : 0;
	pf->nb_s = calcul_space_u(pf, a, without, pf->nb_z);
	pf->nb_s > 0 && pf->flag.minus == 0 ?
		ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
	pf->nb_z > 0 ? ft_putnchar_pf('0', pf->nb_z, pf) : 0;
	ft_putchar_pf(c, pf);
	pf->nb_s > 0 && pf->flag.minus == 1 ?
		ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
}

void			wildcard_bonus(t_printf *p, va_list ap)
{
	int			tmp;

	tmp = va_arg(ap, int);
	if (tmp < 0)
	{
		p->flag.minus = 1;
		tmp = ft_abs(tmp);
	}
	if (p->flag.point == 0)
		p->size_len = tmp;
	else
	{
		if (p->flag.minus == 0)
			p->precision = tmp;
		else
		{
			p->precision = -1;
			p->flag.point = 0;
		}
	}
}
