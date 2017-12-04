/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:53:06 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:09:31 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	add_camera_content(t_env *e, char *tag, char *content)
{
	if (ft_strequ(tag, "<origin>"))
		e->camera.ori = parse_origin(content);
	else if (ft_strequ(tag, "<direction>"))
		e->camera.dir = parse_direction(content);
	else
		quit("Parser : Unknown attribute.");
}

void	parse_camera(t_env *e, char *line)
{
	char	*input;
	char	*content;
	char	*ptr;
	char	*tag;

	input = line;
	tag = NULL;
	while ((content = get_xml_tag(input, &ptr, &tag)))
	{
		input = ptr;
		if (!*content)
			break ;
		add_camera_content(e, tag, content);
		free(tag);
		free(content);
	}
	if (content != NULL)
		quit("Parser : Unvalid XML structure.");
}
