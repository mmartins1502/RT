/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:36:27 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_handle_args(va_list arg, t_format *format)
{
	if (ft_strnequ("@", TYPE, 1))
		return (ft_handle_no_format(format));
	if (ft_strnequ("p", TYPE, 1) || ft_strnequ("lp", TYPE, 2))
		return (ft_handle_pointer(arg, format));
	if (ft_strnequ("%", TYPE, 1))
		return (ft_handle_percent(format));
	if (ft_strnequ("c", TYPE, 1))
		return (ft_handle_char(arg, format));
	if (ft_strnequ("s", TYPE, 1))
		return (ft_handle_str(arg, format));
	if (ft_strnequ("d", TYPE, 1))
		return (ft_handle_int(arg, format));
	if (ft_strnequ("u", TYPE, 1))
		return (ft_handle_unsigned_int(arg, format));
	if (ft_strnequ("x", TYPE, 1))
		return (ft_handle_hex_min(arg, format));
	if (ft_strnequ("X", TYPE, 1))
		return (ft_handle_hex_maj(arg, format));
	if (ft_strnequ("o", TYPE, 1))
		return (ft_handle_octal(arg, format));
	return (ft_handle_args_part_two(arg, format));
}

int		ft_handle_args_part_two(va_list arg, t_format *format)
{
	if (ft_strnequ("lc", TYPE, 2) || ft_strnequ("C", TYPE, 1))
		return (ft_handle_wchar(arg, format));
	if (ft_strnequ("ls", TYPE, 2) || ft_strnequ("S", TYPE, 1))
		return (ft_handle_wstr(arg, format));
	if (ft_strnequ("ld", TYPE, 2) || ft_strnequ("D", TYPE, 1))
		return (ft_handle_long(arg, format));
	if (ft_strnequ("lD", TYPE, 2))
		return (ft_handle_long(arg, format));
	if (ft_strnequ("lu", TYPE, 2) || ft_strnequ("U", TYPE, 1))
		return (ft_handle_unsigned_long(arg, format));
	if (ft_strnequ("lU", TYPE, 2))
		return (ft_handle_unsigned_long(arg, format));
	if (ft_strnequ("lo", TYPE, 2) || ft_strnequ("O", TYPE, 1))
		return (ft_handle_octal_long(arg, format));
	if (ft_strnequ("lO", TYPE, 2))
		return (ft_handle_octal_long(arg, format));
	if (ft_strnequ("lx", TYPE, 2))
		return (ft_handle_hex_min_long(arg, format));
	if (ft_strnequ("lX", TYPE, 2))
		return (ft_handle_hex_maj_long(arg, format));
	return (ft_handle_args_part_three(arg, format));
}

int		ft_handle_args_part_three(va_list arg, t_format *format)
{
	if (ft_strnequ("hd", TYPE, 2))
		return (ft_handle_short(arg, format));
	if (ft_strnequ("hD", TYPE, 2))
		return (ft_handle_unsigned_short(arg, format));
	if (ft_strnequ("hu", TYPE, 2))
		return (ft_handle_unsigned_short(arg, format));
	if (ft_strnequ("hU", TYPE, 2))
		return (ft_handle_unsigned_long(arg, format));
	if (ft_strnequ("ho", TYPE, 2))
		return (ft_handle_octal_short(arg, format));
	if (ft_strnequ("hO", TYPE, 2))
		return (ft_handle_octal_long(arg, format));
	if (ft_strnequ("hx", TYPE, 2))
		return (ft_handle_hex_min_short(arg, format));
	if (ft_strnequ("hX", TYPE, 2))
		return (ft_handle_hex_maj_short(arg, format));
	return (ft_handle_args_part_four(arg, format));
}

int		ft_handle_args_part_four(va_list arg, t_format *format)
{
	if (ft_strnequ("jd", TYPE, 2))
		return (ft_handle_intmax_t(arg, format));
	if (ft_strnequ("jD", TYPE, 2))
		return (ft_handle_unsigned_short(arg, format));
	if (ft_strnequ("jo", TYPE, 2))
		return (ft_handle_octal_long_long(arg, format));
	if (ft_strnequ("jO", TYPE, 2))
		return (ft_handle_octal_short(arg, format));
	if (ft_strnequ("ju", TYPE, 2))
		return (ft_handle_uintmax_t(arg, format));
	if (ft_strnequ("jU", TYPE, 2))
		return (ft_handle_unsigned_short(arg, format));
	if (ft_strnequ("jx", TYPE, 2))
		return (ft_handle_hex_min_long_long(arg, format));
	if (ft_strnequ("jX", TYPE, 2))
		return (ft_handle_hex_maj_long_long(arg, format));
	return (ft_handle_args_part_five(arg, format));
}
