/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:14 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_handle_percent(t_format *format)
{
	char	p;
	int		count;

	p = '%';
	count = 0;
	if (ft_strchr(FLAG, '-'))
	{
		count += ft_putchar_count(p, 1);
		count += ft_put_blanks(WIDTH - 1);
	}
	else if (ft_strchr(FLAG, '0'))
	{
		count += ft_put_zeros(WIDTH - 1);
		count += ft_putchar_count(p, 1);
	}
	else if (WIDTH > 0)
	{
		count += ft_put_blanks(WIDTH - 1);
		count += ft_putchar_count(p, 1);
	}
	else
		count += ft_putchar_count(p, 1);
	return (count);
}
