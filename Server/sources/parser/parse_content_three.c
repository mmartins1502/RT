/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 15:11:12 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		parse_skybox(t_env *e, char *content)
{
	int	i;

	i = 0;
	while (g_skybox_sources[i].name)
	{
		if (ft_strequ(content, g_skybox_sources[i].name))
		{
			e->skybox_index = i;
			e->skybox = 1;
			break ;
		}
		i++;
	}
}

int			parse_texture(char *content)
{
	int i;

	i = 0;
	while (g_color_sources[i].name)
	{
		if (ft_strequ(content, g_color_sources[i].name))
			return (i);
		i++;
	}
	return (-1);
}

int			parse_tsp(char *content)
{
	int i;

	i = 0;
	while (g_tsp_sources[i].name)
	{
		if (ft_strequ(content, g_tsp_sources[i].name))
			return (i);
		i++;
	}
	return (-1);
}

int			parse_filter(char *content)
{
	if (ft_strequ(content, "sepia"))
		return (1);
	if (ft_strequ(content, "greyscale"))
		return (2);
	if (ft_strequ(content, "negative"))
		return (3);
	return (0);
}
