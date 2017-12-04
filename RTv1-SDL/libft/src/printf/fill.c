/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:10 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putchar_count(char c, int display)
{
	if (display)
		write(g_format_derivate->fd, &c, 1);
	return (1);
}

int		ft_put_precision(t_format *format)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (++i < PRECISION_TO_FILL)
		count += ft_putchar_count('0', 1);
	return (count);
}

int		ft_put_blanks(int total)
{
	int i;

	i = -1;
	while (++i < total)
		ft_putchar_count(' ', 1);
	return (i);
}

int		ft_put_zeros(int total)
{
	int i;

	i = -1;
	while (++i < total)
		ft_putchar_count('0', 1);
	return (i);
}
