/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:50:25 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:11:13 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	parse_origin(char *content)
{
	t_vector	v;
	char		**split;

	split = ft_strsplit(content, ',');
	if (ft_array_len(split) != 3)
		quit("Parser : Bad direction/origin.");
	if (!ft_str_is_number(split[0]))
		quit("Parser : Bad direction/origin.");
	if (!ft_str_is_number(split[1]))
		quit("Parser : Bad direction/origin.");
	if (!ft_str_is_number(split[2]))
		quit("Parser : Bad direction/origin.");
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
	return (vector_normalize(v));
}

double		parse_radius(char *content)
{
	double r;

	if (!ft_str_is_number(content))
		quit("Parser : Bad radius.");
	r = ft_atod(content);
	return (r * r);
}

double		parse_angle(char *content)
{
	double a;

	if (!ft_str_is_number(content))
		quit("Parser : Bad angle.");
	a = ft_atod(content);
	a = (a * M_PI) / 180;
	return (a);
}

t_color		parse_color(char *content)
{
	t_color c;
	char	**split;

	split = ft_strsplit(content, ',');
	if (ft_array_len(split) != 3)
		quit("Parser : Bad color.");
	if ((c.r = ft_xtoi(split[0])) == -1)
		quit("Parser : Bad color.");
	if ((c.g = ft_xtoi(split[1])) == -1)
		quit("Parser : Bad color.");
	if ((c.b = ft_xtoi(split[2])) == -1)
		quit("Parser : Bad color.");
	ft_free_array(split);
	return (c);
}
