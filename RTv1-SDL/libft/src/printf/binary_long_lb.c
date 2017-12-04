/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_long_lb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 21:29:16 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:27 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_binary_long(unsigned long int binary, int display)
{
	unsigned long int	width_nb;
	unsigned long int	binary_bis;
	int					count;

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

void	ft_lb_get_central_len(unsigned long int lb, t_format *format)
{
	LEN = ft_put_binary_long(lb, 0);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_binary_long(va_list arg, t_format *format)
{
	unsigned long int	lb;
	int					count;

	lb = va_arg(arg, unsigned long int);
	count = 0;
	if (IS_PRECISION && PRECISION == 0 && lb == 0)
	{
		count += ft_put_blanks(WIDTH);
		if (FLAG[0] == '#')
			count += ft_putchar_count('0', 1);
		return (count);
	}
	if (lb == 0)
		return (ft_putchar_count('0', 1));
	ft_init_len_count(format);
	ft_lb_get_central_len(lb, format);
	ft_octal_get_fill_left(format);
	ft_octal_get_fill_right(format);
	count += ft_octal_write_left(format, 0);
	count += ft_put_precision(format);
	count += ft_put_binary_long(lb, 1);
	count += ft_octal_write_right(format);
	return (count);
}
