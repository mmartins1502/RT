/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace_once.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:32:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace_once(char *orig, char *rep, char *with)
{
	char			*result;
	char			*ins;
	char			*tmp;
	t_strreplace	index;

	index.len_rep = (int)ft_strlen(rep);
	index.len_with = (int)ft_strlen(with);
	index.count = 1;
	result = (char *)ft_memalloc(ft_strlen(orig) + \
							(index.len_with - index.len_rep) * index.count + 1);
	tmp = result;
	while (index.count--)
	{
		ins = ft_strstr(orig, rep);
		index.len_front = (int)ins - (int)orig;
		tmp = ft_strncpy(tmp, orig, index.len_front) + index.len_front;
		tmp = ft_strcpy(tmp, with) + index.len_with;
		orig += index.len_front + index.len_rep;
	}
	ft_strcpy(tmp, orig);
	return (result);
}
