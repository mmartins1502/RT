/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t count;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (dst_len > size)
		return (size + src_len);
	count = 0;
	while ((dst_len + count < size - 1) && src[count] != '\0')
	{
		dst[dst_len + count] = src[count];
		count++;
	}
	dst[dst_len + count] = '\0';
	return (dst_len + src_len);
}
