/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:32:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:18:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cut_string(char *s, char c, int occu)
{
	char	**cut;
	char	*search;
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (s[++i] && count < occu)
		if (s[i] == c)
			count++;
	if (!count)
		return (NULL);
	search = s + i - 1;
	cut = (char **)ft_memalloc(sizeof(char *) * 3);
	cut[0] = ft_strndup(s, search - s);
	cut[1] = ft_strndup(search + 1, s + ft_strlen(s) - search - 1);
	cut[2] = NULL;
	return (cut);
}
