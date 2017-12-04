/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t_ls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:02:16 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/19 22:10:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

ssize_t	ft_wstrlen(wchar_t *ws)
{
	int i;

	i = -1;
	if (!ws)
		return (0);
	else
	{
		while (ws[++i])
			;
	}
	return (i);
}

void	ft_wstr_get_central_len(wchar_t *ws, t_format *format)
{
	int i;
	int j;
	int	len_wide_bis;

	i = -1;
	while (++i < LEN)
		LEN_WIDE += ft_put_wchar_count(ws[i], 0);
	if (IS_PRECISION == 1 && (PRECISION < LEN_WIDE))
	{
		len_wide_bis = 0;
		j = 0;
		while (len_wide_bis < PRECISION)
		{
			len_wide_bis += ft_put_wchar_count(ws[i], 0);
			j = PRECISION - ft_put_wchar_count(ws[i], 0);
		}
		LEN_WIDE = len_wide_bis - j;
	}
	if (IS_PRECISION == 1 && (PRECISION > WIDTH) && WIDTH)
		LEN_WIDE = PRECISION;
	if (IS_PRECISION == 1 && PRECISION == 0)
		LEN_WIDE = 0;
}

void	ft_wchar_get_fill_left(wchar_t *ws, t_format *format)
{
	int i;

	i = -1;
	while (++i < LEN && LEN_WIDE_PUT < LEN_WIDE)
		LEN_WIDE_PUT += ft_put_wchar_count(ws[i], 0);
	if (FLAG[1] == '-')
		LEN_FILL_LEFT = 0;
	else
	{
		if (FLAG[4] == '0')
		{
			if (WIDTH > LEN_WIDE_PUT)
				FILL_ZEROS_LEFT = WIDTH - LEN_WIDE_PUT;
		}
		else
		{
			if (WIDTH > LEN_WIDE_PUT)
				FILL_BLANKS_LEFT = WIDTH - LEN_WIDE_PUT;
		}
	}
}

void	ft_wchar_get_fill_right(t_format *format)
{
	if (FLAG[1] != '-')
	{
		LEN_FILL_RIGHT = 0;
	}
	else
	{
		if (WIDTH > LEN_WIDE)
			FILL_BLANKS_RIGHT = WIDTH - LEN_WIDE;
	}
}

int		ft_handle_wstr(va_list arg, t_format *format)
{
	wchar_t	*ws;
	int		count;
	int		i;
	int		j;

	ws = va_arg(arg, wchar_t *);
	i = -1;
	if (ws == NULL && !IS_PRECISION)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_init_len_count(format);
	LEN = (int)ft_wstrlen(ws);
	ft_wstr_get_central_len(ws, format);
	ft_wchar_get_fill_left(ws, format);
	ft_wchar_get_fill_right(format);
	count = 0;
	count += ft_char_write_left(format);
	j = count;
	while (++i < LEN && (count - j) < LEN_WIDE)
		count += ft_put_wchar_count(ws[i], 1);
	count += ft_char_write_right(format);
	return (count);
}
