/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:30:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_uint_get_fill_left(t_format *format)
{
	if (FLAG[1] != '-')
	{
		if (FLAG[4] == '0' && WIDTH > 0 && IS_PRECISION == 0)
			FILL_ZEROS_LEFT = WIDTH - LEN;
		else if (WIDTH > 0)
			FILL_BLANKS_LEFT = WIDTH - LEN;
	}
	LEN_FILL_LEFT += FILL_ZEROS_LEFT;
	LEN_FILL_LEFT += FILL_BLANKS_LEFT;
}

void	ft_uint_get_fill_right(t_format *format)
{
	if (WIDTH > 0)
		LEN_FILL_RIGHT = WIDTH - LEN - LEN_FILL_LEFT;
	else
		LEN_FILL_RIGHT = 0;
	FILL_BLANKS_RIGHT = LEN_FILL_RIGHT;
}

int		ft_uint_write_left(t_format *format)
{
	int count;

	count = 0;
	if (FILL_BLANKS_LEFT)
		count += ft_put_blanks(FILL_BLANKS_LEFT);
	else if (FILL_ZEROS_LEFT)
		count += ft_put_zeros(FILL_ZEROS_LEFT);
	return (count);
}

int		ft_uint_write_right(t_format *format)
{
	int count;

	count = 0;
	if (FILL_BLANKS_RIGHT)
		count += ft_put_blanks(FILL_BLANKS_RIGHT);
	return (count);
}
