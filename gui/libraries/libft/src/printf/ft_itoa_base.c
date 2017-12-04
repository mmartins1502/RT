/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qselle <qselle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 15:24:08 by qselle            #+#    #+#             */
/*   Updated: 2017/05/07 15:24:10 by qselle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		conversion(uintmax_t nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char			*ft_itoa_base(uintmax_t nb, unsigned int base)
{
	int			index;
	char		*str;
	uintmax_t	tmp;

	index = 0;
	tmp = nb;
	while (tmp >= base)
	{
		tmp = tmp / base;
		index++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	str[index + 1] = '\0';
	while (index >= 0)
	{
		tmp = nb % base;
		str[index] = conversion(tmp);
		nb /= base;
		index--;
	}
	return (str);
}

static int		conversion_x(uintmax_t nb)
{
	if (nb >= 10)
		return (nb - 10 + 'A');
	else
		return (nb + '0');
}

char			*ft_itoa_base_x(uintmax_t nb, unsigned int base)
{
	int					index;
	char				*str;
	uintmax_t			tmp;

	index = 0;
	tmp = nb;
	while (tmp >= base)
	{
		tmp = tmp / base;
		index++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	str[index + 1] = '\0';
	while (index >= 0)
	{
		tmp = nb % base;
		str[index] = conversion_x(tmp);
		nb /= base;
		index--;
	}
	return (str);
}
