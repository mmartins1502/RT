/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 18:32:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/08/17 06:21:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_escape(char *line, char escape, char real_value)
{
	char	*save;

	if (!line || !*line)
		return ;
	save = line;
	while (*(line + 1))
	{
		if (*line == '\\' && *(line + 1) == escape)
		{
			*line = real_value;
			ft_memmove(line + 1, line + 2, ft_strlen(line));
			ft_escape(save, escape, real_value);
			return ;
		}
		line++;
	}
}
