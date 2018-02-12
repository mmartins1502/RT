/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_bis;
	unsigned char	*src_bis;
	unsigned char	c_bis;
	size_t			i;

	i = 0;
	dest_bis = (unsigned char *)dest;
	src_bis = (unsigned char *)src;
	c_bis = (unsigned char)c;
	while (i < n)
	{
		dest_bis[i] = src_bis[i];
		if (dest_bis[i] == c_bis)
			return (dest_bis + i + 1);
		i++;
	}
	return (NULL);
}
