/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:12:36 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 17:59:39 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	get_port(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_strequ("-p", argv[i]) && ft_str_is_number(argv[i + 1]))
			return (ft_atoi(argv[i + 1]));
		i++;
	}
	ft_dprintf(2, "Please provide a port to listen : -p <port>\n");
	exit(EXIT_FAILURE);
	return (-1);
}

static char	*get_scene(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ("-p", argv[i]) && ft_str_is_number(argv[i + 1]))
			i += 2;
		else if (ft_strequ("--not-local", argv[i]))
			i++;
		else
			return (argv[i]);
	}
	return (NULL);
}

static void	get_local_compute(t_env *e, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ("-p", argv[i]) && ft_str_is_number(argv[i + 1]))
			i += 2;
		else if (ft_strequ("--not-local", argv[i]))
		{
			e->local_compute = 0;
			i++;
		}
		else
			i++;
	}
}

void		get_options(t_env *e, int argc, char **argv)
{
	g_port = get_port(argc, argv);
	get_local_compute(e, argc, argv);
	e->scene_file = get_scene(argc, argv);
	if (!e->scene_file)
		random_spheres(e);
	else
		parser(e);
}
