/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_pf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:03:51 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
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
