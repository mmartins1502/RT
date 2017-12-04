/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:33:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_str_get_central_len(unsigned char *s, t_format *format)
{
	if (s)
		LEN = (int)ft_strlen((char *)s);
	else
		LEN = 0;
	if (IS_PRECISION == 1 && (PRECISION < LEN))
		LEN = PRECISION;
}

int		ft_handle_str(va_list arg, t_format *format)
{
	unsigned char	*s;
	int				count;
	int				i;

	s = va_arg(arg, unsigned char *);
	i = -1;
	if (s == NULL && !IS_PRECISION)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_init_len_count(format);
	ft_str_get_central_len(s, format);
	ft_char_get_fill_left(format);
	ft_char_get_fill_right(format);
	count = 0;
	count += ft_char_write_left(format);
	while (++i < LEN)
		count += ft_putchar_count(s[i], 1);
	count += ft_char_write_right(format);
	return (count);
}
