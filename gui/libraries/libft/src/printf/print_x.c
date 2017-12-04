/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:32:35 by qselle            #+#    #+#             */
/*   Updated: 2017/05/07 17:13:02 by qselle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			read_u(t_printf *pf)
{
	uintmax_t	a;
	uintmax_t	without;
	char		*s;

	pf->nb_s = 0;
	pf->nb_z = 0;
	if (check_nothing_u(pf) == 1)
		return ;
	s = ft_itoa_base(pf->nb.oux, 10);
	a = ft_strlen(s);
	without = ft_strlen(s);
	pf->nb_z = calcul_zero_u(pf, a, without);
	pf->nb_s = calcul_space_u(pf, a, without, pf->nb_z);
	pf->nb_s > 0 && pf->flag.minus == 0 ? ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
	pf->nb_z > 0 ? ft_putnchar_pf('0', pf->nb_z, pf) : 0;
	ft_putstr_pf(s, pf);
	free(s);
	s = NULL;
	pf->nb_s > 0 && pf->flag.minus == 1 ? ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
}

void			read_hex(t_printf *pf)
{
	uintmax_t	a;
	uintmax_t	without;
	char		*s;

	pf->nb_s = 0;
	pf->nb_z = 0;
	if (check_nothing_u(pf) == 1)
		return ;
	s = ft_itoa_base(pf->nb.oux, 16);
	a = ft_strlen(s);
	without = ft_strlen(s);
	pf->flag.diez == 1 ? a += 2 : 0;
	pf->nb_z = calcul_zero_u(pf, a, without);
	pf->nb_s = calcul_space_u(pf, a, without, pf->nb_z);
	pf->nb_s > 0 && pf->flag.minus == 0 ? ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
	pf->flag.diez == 1 && pf->nb.oux != 0 ? ft_putstr_pf("0x", pf) : 0;
	pf->nb_z > 0 ? ft_putnchar_pf('0', pf->nb_z, pf) : 0;
	ft_putstr_pf(s, pf);
	free(s);
	s = NULL;
	pf->nb_s > 0 && pf->flag.minus == 1 ? ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
}

static void		octal_bis(t_printf *pf, intmax_t a, intmax_t without, char *s)
{
	pf->nb_z = calcul_zero_u(pf, a, without);
	pf->nb_s = calcul_space_u(pf, a, without, pf->nb_z);
	pf->nb_s > 0 && pf->flag.minus == 0 ? ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
	if (pf->flag.diez == 1 && pf->nb.oux != 0)
	{
		ft_putstr_pf("0", pf);
		pf->nb_z--;
	}
	pf->nb_z > 0 ? ft_putnchar_pf('0', pf->nb_z, pf) : 0;
	ft_putstr_pf(s, pf);
}

void			read_octal(t_printf *pf)
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
	s = ft_itoa_base(pf->nb.oux, 8);
	a = ft_strlen(s);
	without = ft_strlen(s);
	pf->flag.diez == 1 ? a += 1 : 0;
	octal_bis(pf, a, without, s);
	free(s);
	s = NULL;
	pf->nb_s > 0 && pf->flag.minus == 1 ? ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
}

void			read_hexx(t_printf *pf)
{
	uintmax_t	a;
	uintmax_t	without;
	char		*s;

	pf->nb_s = 0;
	pf->nb_z = 0;
	if (check_nothing_u(pf) == 1)
		return ;
	s = ft_itoa_base_x(pf->nb.oux, 16);
	a = ft_strlen(s);
	without = ft_strlen(s);
	pf->flag.diez == 1 ? a += 2 : 0;
	pf->nb_z = calcul_zero_u(pf, a, without);
	pf->nb_s = calcul_space_u(pf, a, without, pf->nb_z);
	pf->nb_s > 0 && pf->flag.minus == 0 ? ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
	pf->flag.diez == 1 && pf->nb.oux != 0 ? ft_putstr_pf("0X", pf) : 0;
	pf->nb_z > 0 ? ft_putnchar_pf('0', pf->nb_z, pf) : 0;
	ft_putstr_pf(s, pf);
	free(s);
	s = NULL;
	pf->nb_s > 0 && pf->flag.minus == 1 ? ft_putnchar_pf(' ', pf->nb_s, pf) : 0;
}
