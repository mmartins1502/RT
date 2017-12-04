/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_long_long_llu.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:16 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_put_unsigned_long_long(unsigned long long int nb, int display)
{
	int						count;
	unsigned long long int	width_nb;
	unsigned long long int	nb_bis;

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

void	ft_lluint_get_central_len(unsigned long long int llu, t_format *format)
{
	LEN = ft_put_unsigned_long_long(llu, 0);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_unsigned_long_long(va_list arg, t_format *format)
{
	unsigned long long int	llu;
	int						count;

	llu = va_arg(arg, unsigned long long int);
	if (IS_PRECISION && PRECISION == 0 && llu == 0)
		return (ft_put_blanks(WIDTH));
	ft_init_len_count(format);
	ft_lluint_get_central_len(llu, format);
	ft_uint_get_fill_left(format);
	ft_uint_get_fill_right(format);
	count = 0;
	count += ft_uint_write_left(format);
	count += ft_put_precision(format);
	count += ft_put_unsigned_long_long(llu, 1);
	count += ft_uint_write_right(format);
	return (count);
}
