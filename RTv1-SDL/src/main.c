/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:39:04 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:08:44 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	quit(char *msg)
{
	if (msg)
	{
		ft_fprintf(STDERR_FILENO, "RTv1 | ERROR : %s\n", msg);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc < 2)
		quit("Usage : ./RTv1 scene.xml");
	e = (t_env *)ft_memalloc(sizeof(t_env));
	init_env(e, argv[1]);
	parser(e);
	init_sdl(e);
	draw_screen(e);
}
