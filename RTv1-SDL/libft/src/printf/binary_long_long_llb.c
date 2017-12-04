/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_long_long_llb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:29:16 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:27 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_binary_long_long(unsigned long long int binary, int display)
{
	unsigned long long int	width_nb;
	unsigned long long int	binary_bis;
	int						count;

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

void	ft_llb_get_central_len(unsigned long long int llb, t_format *format)
{
	LEN = ft_put_binary_long_long(llb, 0);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_binary_long_long(va_list arg, t_format *format)
{
	unsigned long long int	llb;
	int						count;

	llb = va_arg(arg, unsigned long long int);
	count = 0;
	if (IS_PRECISION && PRECISION == 0 && llb == 0)
	{
		count += ft_put_blanks(WIDTH);
		if (FLAG[0] == '#')
			count += ft_putchar_count('0', 1);
		return (count);
	}
	if (llb == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_llb_get_central_len(llb, format);
	ft_octal_get_fill_left(format);
	ft_octal_get_fill_right(format);
	count += ft_octal_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_binary_long_long(llb, 1);
	count += ft_octal_write_right(format);
	return (count);
}
