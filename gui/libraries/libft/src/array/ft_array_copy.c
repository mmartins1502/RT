/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:32:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_copy(char **s)
{
	int		i;
	char	**array;

	array = (char **)ft_memalloc(sizeof(char *) * (ft_array_len(s) + 2));
	i = 0;
	while (s && s[i])
	{
		array[i] = ft_strdup(s[i]);
		i++;
	}
	array[i] = NULL;
	return (array);
}
