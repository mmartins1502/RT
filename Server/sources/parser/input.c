/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 18:29:47 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	get_input(t_env *e)
{
	int			fd;
	char		*line;
	struct stat	file;

	if (!(!stat(e->scene_file, &file) && file.st_mode & S_IFREG
									&& file.st_mode & S_IRUSR))
		parse_error("Can't open file", NULL, NULL);
	fd = open(e->scene_file, O_RDONLY);
	if (fd > 0)
	{
		e->input = ft_strdup("");
		line = NULL;
		while (get_next_line(fd, &line) == 1)
		{
			if (!ft_strstr(line, "<!--"))
				e->input = ft_post_realloc_str(e->input, line);
			free(line);
		}
		ft_strdel(&line);
		remove_ws(&e->input);
		close(fd);
	}
	else
		parse_error("Can't open file", NULL, NULL);
}
