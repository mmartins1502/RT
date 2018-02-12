/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char *str1_bis;
	unsigned char *str2_bis;

	str1_bis = (unsigned char *)str1;
	str2_bis = (unsigned char *)str2;
	while (n--)
	{
		if (*str1_bis != *str2_bis)
			return (*str1_bis - *str2_bis);
		str1_bis++;
		str2_bis++;
	}
	return (0);
}
