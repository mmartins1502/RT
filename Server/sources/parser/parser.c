/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:52:18 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	parse_error(char *msg, char *tag, char *content)
{
	ft_printf(RED "PARSE ERROR : " RESET);
	if (msg)
		ft_printf("%s\n", msg);
	if (tag)
		ft_printf(RED "TAG : " RESET "%s\n", tag);
	if (content)
		ft_printf(RED "CONTENT : " RESET "%s\n", content);
	exit(EXIT_FAILURE);
}

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
		ft_strdel(&opening);
		ft_strdel(&closing);
		return ("\0");
	}
	ft_strdel(&closing);
	*tag = opening;
	*ptr = line + (2 * ft_strlen(opening) + 1 + until - to);
	return (ft_strndup(line + ft_strlen(opening), until - to));
}

void	add_object(t_env *e, char *tag, char *content)
{
	t_obj	*obj;

	if (ft_strequ(tag, "<object>"))
	{
		obj = new_obj();
		parse_object(obj, content);
		obj_push_back(&e->objects, obj);
	}
	else if (ft_strequ(tag, "<camera>"))
		parse_camera(e, content);
	else
		parse_error("Unknown object !", NULL, NULL);
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
	ptr = NULL;
	while ((content = get_xml_tag(input, &ptr, &tag)))
	{
		input = ptr;
		if (!*content)
			break ;
		add_object(e, tag, content);
		ft_strdel(&tag);
		ft_strdel(&content);
	}
	if (content != NULL)
		parse_error("Invalid xml structure.", NULL, content);
}
