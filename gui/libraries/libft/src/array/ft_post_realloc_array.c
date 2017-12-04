/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_post_realloc_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 05:12:11 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_post_realloc_array(char **array, char *new_line)
{
	char	**new_array;
	int		i;
	int		len;

	len = (sizeof(char *) * (ft_array_len(array) + 2));
	new_array = (char **)ft_memalloc(len);
	i = 0;
	while (array && array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[i] = ft_strdup(new_line);
	new_array[i + 1] = NULL;
	ft_free_array(array);
	return (new_array);
}
