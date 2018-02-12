/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content_one.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:10:07 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 15:10:07 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			parse_type(char *content)
{
	if (ft_strequ(content, "sphere"))
		return (OBJ_SPHERE);
	else if (ft_strequ(content, "plane"))
		return (OBJ_PLANE);
	else if (ft_strequ(content, "cylinder"))
		return (OBJ_CYL);
	else if (ft_strequ(content, "cone"))
		return (OBJ_CONE);
	else if (ft_strequ(content, "triangle"))
		return (OBJ_TRI);
	else if (ft_strequ(content, "square"))
		return (OBJ_SQUARE);
	else if (ft_strequ(content, "torus"))
		return (OBJ_TORUS);
	else
		parse_error("Unknown type object.", NULL, content);
	return (-1);
}

t_vector	parse_origin(char *content)
{
	t_vector	v;
	char		**split;

	split = ft_strsplit(content, ',');
	if (ft_array_len(split) != 3)
		parse_error("Bad direction - origin", NULL, content);
	v.x = ft_atod(split[0]);
	v.y = ft_atod(split[1]);
	v.z = ft_atod(split[2]);
	ft_free_array(split);
	return (v);
}

t_vector	parse_direction(char *content)
{
	t_vector v;

	v = parse_origin(content);
	return (v);
}

double		parse_radius(char *content)
{
	double r;

	r = ft_atod(content);
	return (r * r);
}

double		parse_angle(char *content)
{
	double a;

	a = ft_atod(content);
	a = (a * M_PI) / (double)180.0;
	return (a);
}
