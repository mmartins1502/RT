/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:30:40 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_no_format_get_central_len(t_format *format)
{
	if (NO_FORMAT > 0)
		LEN = 1;
	else
		LEN = 0;
}

int		ft_handle_no_format(t_format *format)
{
	int count;

	ft_init_len_count(format);
	ft_no_format_get_central_len(format);
	ft_char_get_fill_left(format);
	ft_char_get_fill_right(format);
	count = 0;
	count += ft_char_write_left(format);
	if (NO_FORMAT)
		count += ft_putchar_count(NO_FORMAT, 1);
	count += ft_char_write_right(format);
	return (count);
}
