/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src_bis;
	unsigned char	*dest_bis;
	size_t			i;

	if (src == dest)
		return (dest);
	src_bis = (unsigned char *)src;
	dest_bis = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dest_bis[i] = src_bis[i];
		i++;
	}
	return (dest_bis);
}
