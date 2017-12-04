/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_char_hhu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:30:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_unsigned_char(unsigned char nb, int display)
{
	int				count;
	unsigned char	width_nb;
	unsigned char	nb_bis;

	width_nb = 1;
	nb_bis = nb;
	while ((nb_bis /= 10) > 0)
		width_nb *= 10;
	count = 0;
	while (width_nb != 0)
	{
		count += ft_putchar_count((nb / width_nb) % 10 + '0', display);
		width_nb /= 10;
	}
	return (count);
}

void	ft_hhu_get_central_len(unsigned char hhu, t_format *format)
{
	LEN = ft_put_unsigned_char(hhu, 0);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_unsigned_char(va_list arg, t_format *format)
{
	unsigned char	hhu;
	int				count;

	hhu = va_arg(arg, int);
	if (IS_PRECISION && PRECISION == 0 && hhu == 0)
		return (ft_put_blanks(WIDTH));
	ft_init_len_count(format);
	ft_hhu_get_central_len(hhu, format);
	ft_uint_get_fill_left(format);
	ft_uint_get_fill_right(format);
	count = 0;
	count += ft_uint_write_left(format);
	count += ft_put_precision(format);
	count += ft_put_unsigned_char(hhu, 1);
	count += ft_uint_write_right(format);
	return (count);
}
