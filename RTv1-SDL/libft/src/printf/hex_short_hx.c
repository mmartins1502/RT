/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_short_hx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 02:37:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_hex_short(unsigned short hex, int display, t_format *format)
{
	unsigned short	width_nb;
	unsigned short	hex_bis;
	char			hex_letter;
	int				count;

	width_nb = 1;
	hex_bis = hex;
	count = 0;
	while ((hex_bis /= 16) > 0)
		width_nb *= 16;
	while (width_nb != 0)
	{
		hex_letter = ((hex / width_nb) % 16 + '0');
		if (hex_letter >= ':' && hex_letter <= '?')
			count += ft_putchar_count(hex_letter + HEX_TYPE, display);
		else
			count += ft_putchar_count(hex_letter, display);
		width_nb /= 16;
	}
	return (count);
}

void	ft_short_hex_get_central_len(unsigned short hx, t_format *format)
{
	LEN = ft_put_hex_short(hx, 0, format);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_hex_min_short(va_list arg, t_format *format)
{
	unsigned short	hx_min;
	int				count;

	hx_min = va_arg(arg, int);
	HEX_TYPE = 39;
	if (IS_PRECISION && PRECISION == 0 && hx_min == 0)
		return (ft_put_blanks(WIDTH));
	if (hx_min == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_short_hex_get_central_len(hx_min, format);
	ft_hex_get_fill_left(format);
	ft_hex_get_fill_right(format);
	count = 0;
	count += ft_hex_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_hex_short(hx_min, 1, format);
	count += ft_hex_write_right(format);
	return (count);
}

int		ft_handle_hex_maj_short(va_list arg, t_format *format)
{
	unsigned short	hx_maj;
	int				count;

	hx_maj = va_arg(arg, int);
	HEX_TYPE = 7;
	if (IS_PRECISION && PRECISION == 0 && hx_maj == 0)
		return (ft_put_blanks(WIDTH));
	if (hx_maj == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_short_hex_get_central_len(hx_maj, format);
	ft_hex_get_fill_left(format);
	ft_hex_get_fill_right(format);
	count = 0;
	count += ft_hex_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_hex_short(hx_maj, 1, format);
	count += ft_hex_write_right(format);
	return (count);
}
