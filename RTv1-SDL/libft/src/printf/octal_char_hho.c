/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_char_hho.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:30:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_octal_char(unsigned char octal, int display)
{
	unsigned char	width_nb;
	unsigned char	octal_bis;
	int				count;

	width_nb = 1;
	octal_bis = octal;
	while ((octal_bis /= 8) > 0)
		width_nb *= 8;
	count = 0;
	while (width_nb != 0)
	{
		count += ft_putchar_count((octal / width_nb) % 8 + '0', display);
		width_nb /= 8;
	}
	return (count);
}

void	ft_char_octal_get_central_len(unsigned char hho, t_format *format)
{
	LEN = ft_put_octal_char(hho, 0);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_octal_char(va_list arg, t_format *format)
{
	unsigned char	hho;
	int				count;

	hho = va_arg(arg, int);
	count = 0;
	if (IS_PRECISION && PRECISION == 0 && hho == 0)
	{
		count += ft_put_blanks(WIDTH);
		if (FLAG[0] == '#')
			count += ft_putchar_count('0', 1);
		return (count);
	}
	if (hho == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_char_octal_get_central_len(hho, format);
	ft_octal_get_fill_left(format);
	ft_octal_get_fill_right(format);
	count += ft_octal_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_octal_char(hho, 1);
	count += ft_octal_write_right(format);
	return (count);
}
