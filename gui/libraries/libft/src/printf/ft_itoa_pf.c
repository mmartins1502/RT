/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 00:16:29 by qselle            #+#    #+#             */
/*   Updated: 2017/01/11 14:16:29 by qselle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_findsign(intmax_t n, uintmax_t sign)
{
	if (n < 0)
		sign = 1;
	return (sign);
}

static int			ft_findlen(intmax_t n, uintmax_t index)
{
	while (n /= 10)
		index++;
	return (index);
}

char				*ft_itoa_pf(intmax_t n)
{
	char			*dst;
	uintmax_t		sign;
	uintmax_t		index;
	uintmax_t		tmp;

	sign = ft_findsign(n, 0);
	if (sign == 1)
		n *= -1;
	tmp = n;
	index = ft_findlen(tmp, 0);
	dst = ft_strnew(index + 1);
	if (dst == NULL)
		return (NULL);
	dst[index + 1] = '\0';
	while (index > 0)
	{
		dst[index] = (tmp % 10) + 48;
		tmp /= 10;
		index--;
	}
	dst[index] = (tmp % 10) + 48;
	return (dst);
}
