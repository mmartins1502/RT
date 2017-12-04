/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:38:04 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t len_src;
	size_t len_dest;
	size_t count;
	size_t count2;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen((char *)src);
	count = 0;
	count2 = 0;
	while ((count < len_src) && (count2 < nb))
	{
		dest[len_dest] = src[count];
		count++;
		count2++;
		len_dest++;
	}
	dest[len_dest] = '\0';
	return (dest);
}
