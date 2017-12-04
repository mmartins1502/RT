/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:42:58 by qselle            #+#    #+#             */
/*   Updated: 2017/05/08 15:27:13 by qselle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlenlen(const char **s)
{
	size_t		index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

static size_t	ft_wcharlen(unsigned wc)
{
	if (wc < 0x80)
		return (1);
	else if (wc < 0x800)
		return (2);
	else if (wc < 0x10000)
		return (3);
	else
		return (4);
}

size_t			ft_strwlen(unsigned *s)
{
	size_t		len;

	len = 0;
	while (*s != L'\0')
	{
		len += ft_wcharlen(*s);
		++s;
	}
	return (len);
}
