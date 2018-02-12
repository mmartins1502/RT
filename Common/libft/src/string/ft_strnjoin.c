/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:34:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, ssize_t len)
{
	char	*s3;
	char	*temp;

	s3 = ft_strnew(ft_strlen(s1) + len);
	temp = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2 && len > 0)
	{
		*s3++ = *s2++;
		len--;
	}
	*s3 = '\0';
	return (s3 - (s3 - temp));
}
