/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_long_long_llx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:33:23 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_hex_ll(unsigned long long int x, int d, t_format *format)
{
	unsigned long long int	width_nb;
	unsigned long long int	hex_bis;
	char					hex_letter;
	int						count;

	width_nb = 1;
	hex_bis = x;
	count = 0;
	while ((hex_bis /= 16) > 0)
		width_nb *= 16;
	while (width_nb != 0)
	{
		hex_letter = ((x / width_nb) % 16 + '0');
		if (hex_letter >= ':' && hex_letter <= '?')
			count += ft_putchar_count(hex_letter + HEX_TYPE, d);
		else
			count += ft_putchar_count(hex_letter, d);
		width_nb /= 16;
	}
	return (count);
}

void	ft_llx_get_central_len(unsigned long long int llx, t_format *format)
{
	LEN = ft_put_hex_ll(llx, 0, format);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_hex_min_long_long(va_list arg, t_format *format)
{
	unsigned long long int	llx_min;
	int						count;

	llx_min = va_arg(arg, unsigned long long int);
	HEX_TYPE = 39;
	if (IS_PRECISION && PRECISION == 0 && llx_min == 0)
		return (ft_put_blanks(WIDTH));
	if (llx_min == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_llx_get_central_len(llx_min, format);
	ft_hex_get_fill_left(format);
	ft_hex_get_fill_right(format);
	count = 0;
	count += ft_hex_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_hex_ll(llx_min, 1, format);
	count += ft_hex_write_right(format);
	return (count);
}

int		ft_handle_hex_maj_long_long(va_list arg, t_format *format)
{
	unsigned long long int	llx_maj;
	int						count;

	llx_maj = va_arg(arg, unsigned long long int);
	HEX_TYPE = 7;
	if (IS_PRECISION && PRECISION == 0 && llx_maj == 0)
		return (ft_put_blanks(WIDTH));
	if (llx_maj == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_llx_get_central_len(llx_maj, format);
	ft_hex_get_fill_left(format);
	ft_hex_get_fill_right(format);
	count = 0;
	count += ft_hex_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_hex_ll(llx_maj, 1, format);
	count += ft_hex_write_right(format);
	return (count);
}
