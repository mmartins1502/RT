/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_obj_content(t_env *e, t_obj *obj, char *tag, char *content)
{
	if (ft_strequ(tag, "<type>"))
		obj->type = parse_type(content);
	else if (ft_strequ(tag, "<origin>"))
		obj->ori = parse_origin(content);
	else if (ft_strequ(tag, "<direction>"))
		obj->dir = vector_normalize(parse_direction(content));
	else if (ft_strequ(tag, "<radius>"))
		obj->radius = parse_radius(content);
	else if (ft_strequ(tag, "<angle>"))
		obj->radius = parse_angle(content);
	else if (ft_strequ(tag, "<color>"))
		obj->color = parse_color(content);
	else if (ft_strequ(tag, "<reflection>"))
		obj->reflection = parse_double(content);
	else if (ft_strequ(tag, "<refraction>"))
		obj->refraction = parse_double(content);
	else if (ft_strequ(tag, "<fuzz>"))
		obj->fuzz = parse_double(content);
	else if (ft_strequ(tag, "<marblesize>"))
		obj->marblesize = parse_double(content);
	else if (ft_strequ(tag, "<marblecolor>"))
		obj->marblecolor = parse_color(content);
	else if (ft_strequ(tag, "<damier>"))
		obj->damier = ft_atoi(content);
	else if (ft_strequ(tag, "<damier1>"))
		obj->damier1 = parse_color(content);
	else if (ft_strequ(tag, "<damier2>"))
		obj->damier2 = parse_color(content);
	else if (ft_strequ(tag, "<light>"))
	{
		obj->emit = 1;
		obj->light = parse_origin(content);
	}
	else
		parse_error("Unknown attribute.", tag, content);
}

void	parse_object(t_env *e, t_obj *obj, char *object_tag, char *line)
{
	char *input;
	char *content;
	char *ptr;
	char *tag;

	input = line;
	tag = NULL;
	while ((content = get_xml_tag(input, &ptr, &tag)))
	{
		input = ptr;
		if (!*content)
			break ;
		add_obj_content(e, obj, tag, content);
		ft_strdel(&tag);
		ft_strdel(&content);
	}
	if (content != NULL)
		parse_error("Invalid object tag.", tag, content);
}
