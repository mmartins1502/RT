/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:51:10 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:12:09 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

char	*get_xml_tag(char *line, char **ptr, char **tag)
{
	char *opening;
	char *closing;
	char *to;
	char *until;

	if (!line || !*line)
		return (NULL);
	if (!(opening = get_xml_opening_tag(line)))
		return ("\0");
	closing = closing_tag(opening);
	to = line + ft_strlen(opening);
	if (!(until = ft_strstr(to, closing)))
	{
		free(opening);
		free(closing);
		return ("\0");
	}
	free(closing);
	*tag = opening;
	*ptr = line + (2 * ft_strlen(opening) + 1 + until - to);
	return (ft_strndup(line + ft_strlen(opening), until - to));
}

int		parse_type(char *content)
{
	if (ft_strequ(content, "sphere"))
		return (OBJ_SPHERE);
	else if (ft_strequ(content, "plane"))
		return (OBJ_PLANE);
	else if (ft_strequ(content, "cylinder"))
		return (OBJ_CYL);
	else if (ft_strequ(content, "cone"))
		return (OBJ_CONE);
	else
		quit("Parser : Unknown object type.");
	return (EXIT_FAILURE);
}

void	add_object(t_env *e, char *tag, char *content)
{
	t_obj	*obj;
	t_light	*light;

	if (ft_strequ(tag, "<object>"))
	{
		obj = new_obj();
		parse_object(obj, content);
		obj_push_back(&e->objects, obj);
	}
	else if (ft_strequ(tag, "<light>"))
	{
		light = new_light();
		parse_light(light, content);
		light_push_back(&e->lights, light);
	}
	else if (ft_strequ(tag, "<camera>"))
		parse_camera(e, content);
	else
		quit("Parser : Unknown object.");
}

void	parser(t_env *e)
{
	char *input;
	char *content;
	char *ptr;
	char *tag;

	get_input(e);
	input = e->input;
	tag = NULL;
	while ((content = get_xml_tag(input, &ptr, &tag)))
	{
		input = ptr;
		if (!*content)
			break ;
		add_object(e, tag, content);
		free(tag);
		free(content);
	}
	if (content != NULL)
		quit("Parser : Unvalid XML structure.");
}
