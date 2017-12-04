/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:16:43 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 18:26:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	*loop_time(void *data)
{
	t_env			*e;
	struct timeval	t;
	double			secs;

	e = (t_env *)data;
	while (42)
	{
		gettimeofday(&t, NULL);
		secs = (double)(t.tv_usec - e->last_event.tv_usec) / (double)1000000.0;
		secs += (double)(t.tv_sec - e->last_event.tv_sec);
		if (secs > e->wait)
			keyboard(SDLK_f, e);
	}
	return (NULL);
}

void		init_render(t_env *e, int argc, char **argv)
{
	pthread_t t;

	init_render_env(e);
	init_skyboxes_tx_sources(e);
	init_color_tx_sources(e);
	init_transparency_tx_sources(e);
	if (argc == 2)
	{
		e->scene_file = argv[1];
		parser(e);
	}
	else
		random_spheres(e);
	if (pthread_create(&t, NULL, loop_time, e) != 0)
	{
		printf("FATAL ERROR : Failed to create thread\n");
		exit(EXIT_FAILURE);
	}
}
