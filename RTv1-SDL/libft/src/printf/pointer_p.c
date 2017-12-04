/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:33:21 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_vectorer_get_central_len(unsigned long int lx, t_format *format)
{
	if (lx == 0 && IS_PRECISION)
		LEN = 0;
	else
	{
		LEN = ft_put_hex_long(lx, 0, format);
		if (IS_PRECISION && PRECISION > LEN)
		{
			PRECISION_TO_FILL = (PRECISION - LEN);
			LEN += PRECISION_TO_FILL;
		}
	}
}

int		ft_handle_pointer(va_list arg, t_format *format)
{
	unsigned long int	p;
	int					count;

	p = va_arg(arg, unsigned long int);
	HEX_TYPE = 39;
	FLAG[0] = '#';
	count = 0;
	ft_init_len_count(format);
	ft_vectorer_get_central_len(p, format);
	ft_hex_get_fill_left(format);
	ft_hex_get_fill_right(format);
	if (IS_PRECISION && p == 0)
	{
		count += ft_put_blanks(FILL_BLANKS_LEFT);
		count += ft_putchar_count('0', 1);
		count += ft_putchar_count('x', 1);
		count += ft_put_zeros(PRECISION);
		return (count);
	}
	count += ft_hex_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_hex_long(p, 1, format);
	count += ft_hex_write_right(format);
	return (count);
}
