/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:10:35 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 15:10:35 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_vector	parse_color(char *content)
{
	t_vector	c;
	char		**split;

	split = ft_strsplit(content, ',');
	if (ft_array_len(split) != 3)
		parse_error("Bad color\n", NULL, content);
	c.x = ft_xtoi(split[0]) / (double)255.0;
	c.y = ft_xtoi(split[1]) / (double)255.0;
	c.z = ft_xtoi(split[2]) / (double)255.0;
	ft_free_array(split);
	return (c);
}

double		parse_double(char *content)
{
	double	d;

	d = ft_atod(content);
	return (d);
}
