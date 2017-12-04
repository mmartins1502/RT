/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_add_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:52:51 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void	add_light_content(t_light *light, char *tag, char *content)
{
	if (ft_strequ(tag, "<origin>"))
		light->ori = parse_origin(content);
	else if (ft_strequ(tag, "<color>"))
		light->color = parse_color(content);
	else
		quit("Parser : Unknown attribute.");
}

void		parse_light(t_light *light, char *line)
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
		add_light_content(light, tag, content);
		free(tag);
		free(content);
	}
	if (content != NULL)
		quit("Parser : Unvalid XML structure.");
}
