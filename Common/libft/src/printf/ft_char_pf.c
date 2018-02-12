/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:03:20 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_pf(char c, t_printf *pf)
{
	write(pf->fd, &c, 1);
	pf->index++;
}

void	ft_putwchar_pf(wchar_t c, t_printf *pf)
{
	{
		if (c <= 0x7F)
			ft_putchar_pf((c), pf);
		else if (c <= 0x7FF)
		{
			ft_putchar_pf(((c >> 6) + 0xC0), pf);
			ft_putchar_pf(((c & 0x3F) + 0x80), pf);
		}
		else if (c <= 0xFFFF)
		{
			ft_putchar_pf(((c >> 12) + 0xE0), pf);
			ft_putchar_pf((((c >> 6) & 0x3F) + 0x80), pf);
			ft_putchar_pf(((c & 0x3F) + 0x80), pf);
		}
		else if (c <= 0x10FFFF)
		{
			ft_putchar_pf(((c >> 18) + 0xF0), pf);
			ft_putchar_pf((((c >> 12) & 0x3F) + 0x80), pf);
			ft_putchar_pf((((c >> 6) & 0x3F) + 0x80), pf);
			ft_putchar_pf(((c & 0x3F) + 0x80), pf);
		}
	}
}

void	ft_putnchar_pf(char c, int n, t_printf *pf)
{
	while (n > 0)
	{
		ft_putchar_pf(c, pf);
		n--;
	}
}
