/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:30:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_int_get_fill_left(t_format *format)
{
	if (FLAG[1] == '-')
	{
		if (FLAG[2] == '+' || FLAG[3] == ' ' || IS_NEGATIVE)
			LEN_FILL_LEFT++;
	}
	else
	{
		if (FLAG[2] == '+' || FLAG[3] == ' ' || IS_NEGATIVE)
		{
			LEN_FILL_LEFT++;
			if (FLAG[4] == '0')
				FILL_ZEROS_LEFT = WIDTH - LEN - 1;
			else if (WIDTH > 0)
				FILL_BLANKS_LEFT = WIDTH - LEN - 1;
		}
		else
		{
			if (FLAG[4] == '0' && WIDTH > 0 && IS_PRECISION == 0)
				FILL_ZEROS_LEFT = WIDTH - LEN;
			else if (WIDTH > 0)
				FILL_BLANKS_LEFT = WIDTH - LEN;
		}
	}
	LEN_FILL_LEFT += FILL_ZEROS_LEFT;
	LEN_FILL_LEFT += FILL_BLANKS_LEFT;
}

void	ft_int_get_fill_right(t_format *format)
{
	if (WIDTH > 0)
		LEN_FILL_RIGHT = WIDTH - LEN - LEN_FILL_LEFT;
	else
		LEN_FILL_RIGHT = 0;
	FILL_BLANKS_RIGHT = LEN_FILL_RIGHT;
}

int		ft_int_write_sign(t_format *format)
{
	int count;

	count = 0;
	if (IS_NEGATIVE)
		count += ft_putchar_count('-', 1);
	else if (FLAG[2] == '+')
		count += ft_putchar_count('+', 1);
	else if (FLAG[3] == ' ')
		count += ft_putchar_count(' ', 1);
	return (count);
}

int		ft_int_write_left(t_format *format)
{
	int count;

	count = 0;
	if (FILL_BLANKS_LEFT)
	{
		count += ft_put_blanks(FILL_BLANKS_LEFT);
		count += ft_int_write_sign(format);
	}
	else if (FILL_ZEROS_LEFT)
	{
		count += ft_int_write_sign(format);
		count += ft_put_zeros(FILL_ZEROS_LEFT);
	}
	else
	{
		count += ft_int_write_sign(format);
	}
	return (count);
}

int		ft_int_write_right(t_format *format)
{
	int count;

	count = 0;
	if (FILL_BLANKS_RIGHT)
		count += ft_put_blanks(FILL_BLANKS_RIGHT);
	return (count);
}
