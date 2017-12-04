/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:27 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_char_get_central_len(t_format *format)
{
	LEN = 1;
	if (IS_PRECISION && PRECISION > LEN)
		LEN += PRECISION;
}

int		ft_handle_char(va_list arg, t_format *format)
{
	unsigned char	c;
	int				count;

	c = va_arg(arg, int);
	ft_init_len_count(format);
	ft_char_get_central_len(format);
	ft_char_get_fill_left(format);
	ft_char_get_fill_right(format);
	count = 0;
	count += ft_char_write_left(format);
	count += ft_putchar_count(c, 1);
	count += ft_char_write_right(format);
	return (count);
}
