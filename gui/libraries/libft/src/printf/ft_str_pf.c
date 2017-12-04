/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:26:30 by qselle            #+#    #+#             */
/*   Updated: 2017/05/08 15:32:50 by qselle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstr_pf(char const *s, t_printf *pf)
{
	int		index;

	index = 0;
	if (s)
	{
		while (s[index])
		{
			ft_putchar_pf(s[index], pf);
			index++;
		}
	}
}

void		ft_putwstr_pf(wchar_t *s, t_printf *pf)
{
	int		index;

	index = 0;
	if (s)
	{
		while (s[index])
		{
			ft_putwchar_pf(s[index], pf);
			index++;
		}
	}
}

void		ft_putstr_lim_pf(char const *str, int size, t_printf *pf)
{
	int		index;

	index = 0;
	if (str)
	{
		while (index != size && str[index])
		{
			ft_putchar_pf(str[index], pf);
			index++;
		}
	}
}

void		ft_putwstr_lim_pf(wchar_t *str, int size, t_printf *pf)
{
	int		index;

	index = 0;
	if (str)
	{
		while (index != size && str[index])
		{
			ft_putwchar_pf(str[index], pf);
			index++;
		}
	}
}
