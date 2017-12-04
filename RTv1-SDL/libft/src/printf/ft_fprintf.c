/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 02:08:13 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_fprintf(int fd, char *s, ...)
{
	int			i;
	va_list		arg;
	t_format	format;
	int			count;

	g_format_derivate = &format;
	g_format_derivate->fd = fd;
	i = -1;
	va_start(arg, s);
	count = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			ft_get_params(&format, &s[++i], arg);
			count += ft_handle_args(arg, &format);
			i += format.count - 1;
		}
		else
			count += ft_putchar_count(s[i], 1);
	}
	va_end(arg);
	return (count);
}
