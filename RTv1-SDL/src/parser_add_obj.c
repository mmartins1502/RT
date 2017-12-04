/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:52:41 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	add_obj_content(t_obj *obj, char *tag, char *content)
{
	if (ft_strequ(tag, "<type>"))
		obj->type = parse_type(content);
	else if (ft_strequ(tag, "<origin>"))
		obj->ori = parse_origin(content);
	else if (ft_strequ(tag, "<direction>"))
		obj->dir = parse_direction(content);
	else if (ft_strequ(tag, "<radius>"))
		obj->radius = parse_radius(content);
	else if (ft_strequ(tag, "<angle>"))
		obj->radius = parse_angle(content);
	else if (ft_strequ(tag, "<color>"))
		obj->color = parse_color(content);
	else if (ft_strequ(tag, "<hauteur>"))
		obj->hauteur = parse_radius(content);
	else
		quit("Parser : Unknown attribute.");
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
		add_obj_content(obj, tag, content);
		free(tag);
		free(content);
	}
	if (content != NULL)
		quit("Parser : Unvalid XML structure.");
}
