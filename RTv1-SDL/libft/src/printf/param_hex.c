/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:30:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_hex_get_fill_left(t_format *format)
{
	if (FLAG[1] == '-')
	{
		if (FLAG[0] == '#')
			LEN_FILL_LEFT += 2;
	}
	else
	{
		if (FLAG[0] == '#')
		{
			LEN_FILL_LEFT += 2;
			if (FLAG[4] == '0' && WIDTH > LEN + 2)
				FILL_ZEROS_LEFT = WIDTH - LEN - 2;
			else if (WIDTH > LEN + 2)
				FILL_BLANKS_LEFT = WIDTH - LEN - 2;
		}
		else
		{
			if (FLAG[4] == '0' && WIDTH > LEN)
				FILL_ZEROS_LEFT = WIDTH - LEN;
			else if (WIDTH > LEN)
				FILL_BLANKS_LEFT = WIDTH - LEN;
		}
	}
	LEN_FILL_LEFT += FILL_ZEROS_LEFT;
	LEN_FILL_LEFT += FILL_BLANKS_LEFT;
}

void	ft_hex_get_fill_right(t_format *format)
{
	if (WIDTH > 0)
		LEN_FILL_RIGHT = WIDTH - LEN - LEN_FILL_LEFT;
	else
		LEN_FILL_RIGHT = 0;
	FILL_BLANKS_RIGHT = LEN_FILL_RIGHT;
}

int		ft_write_hex_flag(t_format *format)
{
	int count;

	count = 0;
	if (HEX_TYPE == 7)
	{
		count += ft_putchar_count('0', 1);
		count += ft_putchar_count('X', 1);
	}
	else
	{
		count += ft_putchar_count('0', 1);
		count += ft_putchar_count('x', 1);
	}
	return (count);
}

int		ft_hex_write_left(t_format *format, int count)
{
	count = 0;
	if (FLAG[0] == '#')
	{
		if (FLAG[4] == '0' && FLAG[1] != '-')
		{
			count += ft_write_hex_flag(format);
			count += ft_put_zeros(FILL_ZEROS_LEFT);
		}
		else if (FLAG[1] == '-')
		{
			count += ft_write_hex_flag(format);
			count += ft_put_blanks(FILL_BLANKS_LEFT);
		}
		else
		{
			count += ft_put_blanks(FILL_BLANKS_LEFT);
			count += ft_write_hex_flag(format);
		}
	}
	else if (FILL_BLANKS_LEFT)
		count += ft_put_blanks(FILL_BLANKS_LEFT);
	else if (FILL_ZEROS_LEFT)
		count += ft_put_zeros(FILL_ZEROS_LEFT);
	return (count);
}

int		ft_hex_write_right(t_format *format)
{
	int count;

	count = 0;
	if (FILL_BLANKS_RIGHT)
		count += ft_put_blanks(FILL_BLANKS_RIGHT);
	return (count);
}
