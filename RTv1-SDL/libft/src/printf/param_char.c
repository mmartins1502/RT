/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:30:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_char_get_fill_left(t_format *format)
{
	if (FLAG[1] == '-')
		LEN_FILL_LEFT = 0;
	else
	{
		if (FLAG[4] == '0')
		{
			if (WIDTH > LEN)
				FILL_ZEROS_LEFT = WIDTH - LEN;
		}
		else
		{
			if (WIDTH > LEN)
				FILL_BLANKS_LEFT = WIDTH - LEN;
		}
	}
}

void		ft_char_get_fill_right(t_format *format)
{
	if (FLAG[1] != '-')
	{
		LEN_FILL_RIGHT = 0;
	}
	else
	{
		if (WIDTH > LEN)
			FILL_BLANKS_RIGHT = WIDTH - LEN;
	}
}

int			ft_char_write_left(t_format *format)
{
	int count;

	count = 0;
	count += ft_put_blanks(FILL_BLANKS_LEFT);
	count += ft_put_zeros(FILL_ZEROS_LEFT);
	return (count);
}

int			ft_char_write_right(t_format *format)
{
	return (ft_put_blanks(FILL_BLANKS_RIGHT));
}
