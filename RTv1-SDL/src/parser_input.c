/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:51:42 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	get_input(t_env *e)
{
	int		fd;
	char	*line;

	fd = open(e->scene_file, O_RDONLY);
	if (fd > 0 && read(fd, NULL, 0) > -1)
	{
		e->input = ft_strdup("\0");
		line = NULL;
		while (get_next_line(fd, &line) == 1)
		{
			if (ft_strstr(line, "<!--") != line)
				e->input = ft_post_realloc_str(e->input, line);
			free(line);
		}
		free(line);
		remove_ws(&e->input);
		close(fd);
	}
	else
		quit("Can't open file\n");
}
