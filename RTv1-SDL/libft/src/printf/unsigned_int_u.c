/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:15 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_unsigned(unsigned int nb, int display)
{
	int				count;
	unsigned int	width_nb;
	unsigned int	nb_bis;

	width_nb = 1;
	nb_bis = nb;
	count = 0;
	while ((nb_bis /= 10) > 0)
		width_nb *= 10;
	while (width_nb != 0)
	{
		count += ft_putchar_count((nb / width_nb) % 10 + '0', display);
		width_nb /= 10;
	}
	return (count);
}

void	ft_uint_get_central_len(unsigned int u, t_format *format)
{
	LEN = ft_put_unsigned(u, 0);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_unsigned_int(va_list arg, t_format *format)
{
	unsigned int	u;
	int				count;

	u = va_arg(arg, unsigned int);
	if (IS_PRECISION && PRECISION == 0 && u == 0)
		return (ft_put_blanks(WIDTH));
	ft_init_len_count(format);
	ft_uint_get_central_len(u, format);
	ft_uint_get_fill_left(format);
	ft_uint_get_fill_right(format);
	count = 0;
	count += ft_uint_write_left(format);
	count += ft_put_precision(format);
	count += ft_put_unsigned(u, 1);
	count += ft_uint_write_right(format);
	return (count);
}
