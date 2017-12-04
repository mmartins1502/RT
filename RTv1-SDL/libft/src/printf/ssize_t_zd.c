/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssize_t_zd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:15 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_display_ssize_t(ssize_t nb, int display)
{
	int				count;
	ssize_t			width_nb;
	ssize_t			nb_bis;

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

int		ft_put_ssize_t(ssize_t nb, int display, t_format *format)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		IS_NEGATIVE = 1;
		nb = -nb;
	}
	else
		IS_NEGATIVE = 0;
	return (count += ft_display_ssize_t(nb, display));
}

void	ft_ssize_t_get_central_len(ssize_t zd, t_format *format)
{
	LEN = ft_put_ssize_t(zd, 0, format);
	if (IS_PRECISION && PRECISION > LEN)
	{
		PRECISION_TO_FILL = (PRECISION - LEN);
		LEN += PRECISION_TO_FILL;
	}
}

int		ft_handle_ssize_t(va_list arg, t_format *format)
{
	ssize_t	zd;
	int		count;

	zd = va_arg(arg, ssize_t);
	if (IS_PRECISION && PRECISION == 0 && zd == 0)
		return (ft_put_blanks(WIDTH));
	ft_init_len_count(format);
	ft_ssize_t_get_central_len(zd, format);
	ft_int_get_fill_left(format);
	ft_int_get_fill_right(format);
	count = 0;
	count += ft_int_write_left(format);
	count += ft_put_precision(format);
	count += ft_put_ssize_t(zd, 1, format);
	count += ft_int_write_right(format);
	return (count);
}
