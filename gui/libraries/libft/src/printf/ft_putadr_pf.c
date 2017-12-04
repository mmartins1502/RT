/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:32:17 by qselle            #+#    #+#             */
/*   Updated: 2017/05/07 15:32:17 by qselle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putadr_pf(char const *s, t_printf *pf)
{
	unsigned long	adr;
	char const		*base;
	char			res[9];
	int				i;

	adr = (unsigned long)s;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	ft_putchar_pf('0', pf);
	ft_putchar_pf('x', pf);
	while (i < 9)
	{
		ft_putchar_pf(res[i], pf);
		i++;
	}
}
