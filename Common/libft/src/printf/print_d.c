/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:04:00 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		calcul_zero_int(t_printf *pf, intmax_t a, intmax_t without)
{
	long	nb_zero;

	nb_zero = 0;
	if (pf->flag.zero == 1 && pf->size_len > a && pf->size_len > pf->precision)
		nb_zero = pf->size_len - a;
	else if (pf->precision > without)
		nb_zero = pf->precision - without;
	return ((int)nb_zero);
}

static int		calcul_space_int(t_printf *pf, intmax_t a, intmax_t without,
		int nb_zero)
{
	long	nb_space;

	(void)without;
	nb_space = pf->size_len - nb_zero - a;
	if (pf->flag.space == 1 && nb_space <= 0)
	{
		pf->nb.d_i >= 0 ? nb_space = 1 : 0;
	}
	return ((int)nb_space);
}

static void		print_sign_int(t_printf *pf)
{
	if (pf->flag.plus == 1 && pf->nb.d_i >= 0)
		ft_putchar_pf('+', pf);
	else if (pf->nb.d_i < 0)
		ft_putchar_pf('-', pf);
}

static int		check_nothing_int(t_printf *pf)
{
	int			index;

	if ((pf->precision == 0 || pf->precision == -1) &&
			pf->nb.d_i == 0 && pf->flag.point == 1)
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

void			read_d_i(t_printf *pf)
{
	intmax_t	a;
	intmax_t	without;
	int			nb_space;
	int			nb_zero;
	char		*s;

	if (check_nothing_int(pf) == 1)
		return ;
	s = ft_itoa_pf(pf->nb.d_i);
	a = ft_strlen(s);
	without = ft_strlen(s);
	pf->nb.d_i < 0 || (pf->flag.plus == 1 && pf->nb.d_i >= 0) ? a++ : 0;
	nb_zero = calcul_zero_int(pf, a, without);
	pf->flag.space == 1 && pf->flag.zero == 1 ? nb_zero-- : 0;
	nb_space = calcul_space_int(pf, a, without, nb_zero);
	nb_space > 0 && pf->flag.minus == 0 ? ft_putnchar_pf(' ', nb_space, pf) : 0;
	print_sign_int(pf);
	nb_zero > 0 ? ft_putnchar_pf('0', nb_zero, pf) : 0;
	ft_putstr_pf(s, pf);
	free(s);
	s = NULL;
	nb_space > 0 && pf->flag.minus == 1 ? ft_putnchar_pf(' ', nb_space, pf) : 0;
}
