/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:37:01 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int				len_s;
	char			*new_s;
	unsigned char	*s_bis;

	if (f == NULL || s == NULL)
		return (NULL);
	s_bis = (unsigned char *)s;
	len_s = (int)ft_strlen((char *)s_bis);
	new_s = (char *)ft_memalloc(sizeof(char) * (len_s + 1));
	new_s[len_s] = '\0';
	while (len_s--)
		new_s[len_s] = f(s_bis[len_s]);
	return (new_s);
}
