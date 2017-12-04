/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skyboxes_sources.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:12:02 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:21:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static const t_texture_sources g_skybox_sources[] =
{
	{"appartment", "./textures/skybox/appartment.jpg"},
	{"bar", "./textures/skybox/bar.jpg"},
	{"bedroom", "./textures/skybox/bedroom.jpg"},
	{"clouds", "./textures/skybox/clouds.jpg"},
	{"fractale", "./textures/skybox/fractale.jpg"},
	{"snow", "./textures/skybox/snow.jpg"},
	{"universe", "./textures/skybox/universe.png"},
	{NULL, NULL}
};

void	init_skyboxes_tx_sources(t_env *e)
{
	int i;

	e->skybox_index = 0;
	e->skybox_total = 0;
	i = 0;
	while (g_skybox_sources[i].file_address)
	{
		if (!(e->s_skybox[i] = IMG_Load(g_skybox_sources[i].file_address)))
		{
			printf("FATAL : Failed to load skybox texture %s\n",
					g_skybox_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		e->skybox_total++;
	}

	e->current_skybox = NULL;
	e->skybox_index = -1;
}
