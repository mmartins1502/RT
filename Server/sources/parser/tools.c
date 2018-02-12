/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:52:18 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	remove_ws(char **str)
{
	int i;

	i = 0;
	while ((*str)[i])
	{
		if (ft_is_whitespace((*str)[i]))
			ft_memcpy(*str + i, *str + i + 1, ft_strlen(*str + i));
		else
			i++;
	}
}

char	*get_xml_opening_tag(char *line)
{
	int i;

	if (!line || !*line)
		return (NULL);
	if (line[0] != '<')
		return (NULL);
	i = 1;
	while (line[i])
	{
		if (line[i] == '>')
			return (ft_strndup(line, i + 1));
		i++;
	}
	return (NULL);
}

char	*get_xml_closing_tag(char *line)
{
	int i;

	i = (int)ft_strlen(line) - 1;
	if (line[i] != '>')
		return (NULL);
	i--;
	while (i >= 0)
	{
		if (line[i] == '<')
			return (ft_strndup(line + i, ft_strlen(line) - i));
		i--;
	}
	return (NULL);
}

char	*closing_tag(char *opening)
{
	char *closing;

	if (!opening)
		return (NULL);
	closing = ft_strnew(ft_strlen(opening) + 2);
	closing[0] = '<';
	closing[1] = '/';
	ft_strcpy(closing + 2, opening + 1);
	return (closing);
}
