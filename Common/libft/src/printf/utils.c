/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:04:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*converth_bis(t_printf *pf, char *format)
{
	if (*(format + 1) == 'h')
	{
		pf->type.hh = 1;
		++format;
	}
	else
		pf->type.h = 1;
	return (format);
}

char	*convertl_bis(t_printf *pf, char *format)
{
	if (*(format + 1) == 'l')
	{
		pf->type.ll = 1;
		++format;
	}
	else
		pf->type.l = 1;
	return (format);
}

int		calcul_zero_u(t_printf *pf, intmax_t a, intmax_t without)
{
	long	nb_zero;

	nb_zero = 0;
	if (pf->flag.zero == 1 && pf->size_len > a && pf->size_len > pf->precision)
	{
		nb_zero = pf->size_len - a;
	}
	else if (pf->precision > without)
	{
		nb_zero = pf->precision - without;
	}
	return ((int)nb_zero);
}

int		calcul_space_u(t_printf *pf, intmax_t a,
		intmax_t without, int nb_zero)
{
	long	nb_space;

	(void)without;
	nb_space = pf->size_len - nb_zero - a;
	return ((int)nb_space);
}

int		check_nothing_u(t_printf *pf)
{
	int			index;

	if ((pf->precision == 0 || pf->precision == -1) &&
			pf->nb.oux == 0 && pf->flag.point == 1)
	{
		index = pf->size_len;
		while (index > 0)
		{
			ft_putchar_pf(' ', pf);
			index--;
		}
		return (1);
	}
	return (0);
}
