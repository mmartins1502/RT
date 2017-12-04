/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:30:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_handle_args_part_five(va_list arg, t_format *format)
{
	if (ft_strnequ("zd", TYPE, 2))
		return (ft_handle_long_long(arg, format));
	if (ft_strnequ("zD", TYPE, 2))
		return (ft_handle_unsigned_short(arg, format));
	if (ft_strnequ("zu", TYPE, 2))
		return (ft_handle_unsigned_long_long(arg, format));
	if (ft_strnequ("zU", TYPE, 2))
		return (ft_handle_unsigned_short(arg, format));
	if (ft_strnequ("zo", TYPE, 2))
		return (ft_handle_octal_long_long(arg, format));
	if (ft_strnequ("zO", TYPE, 2))
		return (ft_handle_octal_short(arg, format));
	if (ft_strnequ("zx", TYPE, 2))
		return (ft_handle_hex_min_long_long(arg, format));
	if (ft_strnequ("zX", TYPE, 2))
		return (ft_handle_hex_maj_long_long(arg, format));
	return (ft_handle_args_part_six(arg, format));
}

int		ft_handle_args_part_six(va_list arg, t_format *format)
{
	if (ft_strnequ("lld", TYPE, 3))
		return (ft_handle_long_long(arg, format));
	if (ft_strnequ("llD", TYPE, 3))
		return (ft_handle_long_long(arg, format));
	if (ft_strnequ("llu", TYPE, 3))
		return (ft_handle_unsigned_long_long(arg, format));
	if (ft_strnequ("llU", TYPE, 3))
		return (ft_handle_unsigned_long_long(arg, format));
	if (ft_strnequ("llx", TYPE, 3))
		return (ft_handle_hex_min_long_long(arg, format));
	if (ft_strnequ("llX", TYPE, 3))
		return (ft_handle_hex_maj_long_long(arg, format));
	if (ft_strnequ("llo", TYPE, 3))
		return (ft_handle_octal_long_long(arg, format));
	if (ft_strnequ("llO", TYPE, 3))
		return (ft_handle_octal_long_long(arg, format));
	return (ft_handle_args_part_seven(arg, format));
}

int		ft_handle_args_part_seven(va_list arg, t_format *format)
{
	if (ft_strnequ("hhC", TYPE, 3))
		return (ft_handle_wchar(arg, format));
	if (ft_strnequ("hhS", TYPE, 3))
		return (ft_handle_wstr(arg, format));
	if (ft_strnequ("hhd", TYPE, 3))
		return (ft_handle_signed_char(arg, format));
	if (ft_strnequ("hhD", TYPE, 3))
		return (ft_handle_unsigned_short(arg, format));
	if (ft_strnequ("hho", TYPE, 3))
		return (ft_handle_octal_char(arg, format));
	if (ft_strnequ("hhO", TYPE, 3))
		return (ft_handle_octal_short(arg, format));
	if (ft_strnequ("hhu", TYPE, 3))
		return (ft_handle_unsigned_char(arg, format));
	if (ft_strnequ("hhU", TYPE, 3))
		return (ft_handle_unsigned_short(arg, format));
	if (ft_strnequ("hhx", TYPE, 3))
		return (ft_handle_hex_min_char(arg, format));
	if (ft_strnequ("hhX", TYPE, 3))
		return (ft_handle_hex_maj_char(arg, format));
	return (ft_handle_args_part_eight(arg, format));
}

int		ft_handle_args_part_eight(va_list arg, t_format *format)
{
	if (ft_strnequ("b", TYPE, 1))
		return (ft_handle_binary(arg, format));
	if (ft_strnequ("lb", TYPE, 2) || ft_strnequ("B", TYPE, 1))
		return (ft_handle_binary_long(arg, format));
	if (ft_strnequ("llb", TYPE, 3))
		return (ft_handle_binary_long_long(arg, format));
	if (ft_strnequ("hb", TYPE, 2))
		return (ft_handle_binary_short(arg, format));
	if (ft_strnequ("hhb", TYPE, 3))
		return (ft_handle_binary_char(arg, format));
	return (0);
}
