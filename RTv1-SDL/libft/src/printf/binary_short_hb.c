/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_short_hb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:29:16 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:27 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_binary_short(unsigned short binary, int display)
{
	unsigned short	width_nb;
	unsigned short	binary_bis;
	int				count;

	width_nb = 1;
	binary_bis = binary;
	while ((binary_bis /= 2) > 0)
		width_nb *= 2;
	count = 0;
	while (width_nb != 0)
	{
		count += ft_putchar_count((binary / width_nb) % 2 + '0', display);
		width_nb /= 2;
	}
	return (count);
}

void	ft_short_binary_get_central_len(unsigned short hb, t_format *format)
{
	LEN = ft_put_binary_short(hb, 0);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_binary_short(va_list arg, t_format *format)
{
	unsigned short	hb;
	int				count;

	hb = va_arg(arg, int);
	count = 0;
	if (IS_PRECISION && PRECISION == 0 && hb == 0)
	{
		count += ft_put_blanks(WIDTH);
		if (FLAG[0] == '#')
			count += ft_putchar_count('0', 1);
		return (count);
	}
	if (hb == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_short_binary_get_central_len(hb, format);
	ft_octal_get_fill_left(format);
	ft_octal_get_fill_right(format);
	count += ft_octal_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_binary_short(hb, 1);
	count += ft_octal_write_right(format);
	return (count);
}
