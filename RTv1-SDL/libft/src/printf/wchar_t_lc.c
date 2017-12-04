/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t_lc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:16 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_wchar_count(wchar_t wc, int display)
{
	int count;

	count = 0;
	if (wc <= ft_pow(2, 7) - 1)
		count += ft_putchar_count(wc, display);
	else if (wc <= ft_pow(2, 11) - 1)
	{
		count += ft_putchar_count((wc >> 6) + 128 + 64, display);
		count += ft_putchar_count((wc & 63) + 128, display);
	}
	else if (wc <= ft_pow(2, 16) - 1)
	{
		count += ft_putchar_count((wc >> 12) + 128 + 64 + 32, display);
		count += ft_putchar_count(((wc >> 6) & 63) + 128, display);
		count += ft_putchar_count((wc & 63) + 128, display);
	}
	else if (wc <= 1114111)
	{
		count += ft_putchar_count((wc >> 18) + 128 + 64 + 32 + 16, display);
		count += ft_putchar_count((wc >> 12 & 63) + 128, display);
		count += ft_putchar_count((wc >> 6 & 63) + 128, display);
		count += ft_putchar_count((wc & 63) + 128, display);
	}
	return (count);
}

void	ft_wchar_get_central_len(wchar_t wc, t_format *format)
{
	(void)wc;
	LEN = 1;
	if (IS_PRECISION && PRECISION > LEN)
		LEN += PRECISION;
}

int		ft_handle_wchar(va_list arg, t_format *format)
{
	wchar_t	wc;
	int		count;

	wc = va_arg(arg, wchar_t);
	ft_init_len_count(format);
	ft_wchar_get_central_len(wc, format);
	ft_char_get_fill_left(format);
	ft_char_get_fill_right(format);
	count = 0;
	count += ft_char_write_left(format);
	count += ft_put_wchar_count(wc, 1);
	count += ft_char_write_right(format);
	return (count);
}
