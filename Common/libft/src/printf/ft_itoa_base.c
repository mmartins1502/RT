/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:03:23 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		conversion(uintmax_t nb)
{
	if (nb >= 10)
		return ((int)nb - 10 + 'a');
	else
		return ((int)nb + '0');
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
		return ((int)nb - 10 + 'A');
	else
		return ((int)nb + '0');
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
