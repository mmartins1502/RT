/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 11:44:56 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	tag_pack_three(t_obj *obj, char *tag, char *content)
{
	if (ft_strequ(tag, "<height>"))
		obj->height = parse_radius(content);
	else if (ft_strequ(tag, "<light>"))
	{
		obj->emit = 1;
		obj->light = parse_double(content);
	}
	else if (ft_strequ(tag, "<texture>"))
		obj->texture_index = parse_texture(content);
	else if (ft_strequ(tag, "<transparent>"))
		obj->tsp_index = parse_tsp(content);
	else if (ft_strequ(tag, "<small_radius>"))
		obj->small_r = parse_radius(content);
	else if (ft_strequ(tag, "<radius>"))
		obj->radius = parse_radius(content);
	else
		parse_error("Unknown attribute.", tag, content);
}

void	tag_pack_two(t_obj *obj, char *tag, char *content)
{
	if (ft_strequ(tag, "<color>"))
	{
		obj->color = parse_color(content);
		obj->color_backup = obj->color;
	}
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
	else
		tag_pack_three(obj, tag, content);
}

void	tag_pack_one(t_obj *obj, char *tag, char *content)
{
	if (ft_strequ(tag, "<type>"))
		obj->type = parse_type(content);
	else if (ft_strequ(tag, "<origin>"))
		obj->ori = parse_origin(content);
	else if (ft_strequ(tag, "<direction>"))
		obj->dir = vector_normalize(parse_direction(content));
	else if (ft_strequ(tag, "<direction2>"))
		obj->dir2 = vector_normalize(parse_direction(content));
	else if (ft_strequ(tag, "<lenght1>"))
		obj->len1 = parse_double(content);
	else if (ft_strequ(tag, "<lenght2>"))
		obj->len2 = parse_double(content);
	else if (ft_strequ(tag, "<radius>"))
		obj->radius = parse_radius(content);
	else if (ft_strequ(tag, "<angle>"))
		obj->radius = parse_angle(content);
	else
		tag_pack_two(obj, tag, content);
}

void	parse_object(t_obj *obj, char *line)
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
		tag_pack_one(obj, tag, content);
		ft_strdel(&tag);
		ft_strdel(&content);
	}
	if (content != NULL)
		parse_error("Invalid object tag.", tag, content);
}
