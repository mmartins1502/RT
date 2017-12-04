/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 14:12:08 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_camera_content(t_env *e, char *tag, char *content)
{
	if (ft_strequ(tag, "<origin>"))
		e->camera.ori = parse_origin(content);
	else if (ft_strequ(tag, "<direction>"))
		e->camera.dir = parse_direction(content);
	else if (ft_strequ(tag, "<skybox>"))
		parse_skybox(e, content);
	else
		parse_error("Unknown attribute.", tag, content);
}

void	parse_camera(t_env *e, char *object_tag, char *line)
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
		add_camera_content(e, tag, content);
		ft_strdel(&tag);
		ft_strdel(&content);
	}
	if (content != NULL)
		parse_error("Invalid camera tag.", tag, content);
}
