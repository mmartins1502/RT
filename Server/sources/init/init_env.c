/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:35:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 15:02:29 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	count(const t_texture_sources t[])
{
	int	i;

	i = 0;
	while (t[i].name)
		i++;
	return (i);
}

void		init_render_env(t_env *e)
{
	e->avoid = NULL;
	perlin_generate(e);
	perlin_generate_perm((int *)&e->perm_x);
	perlin_generate_perm((int *)&e->perm_y);
	perlin_generate_perm((int *)&e->perm_z);
	e->increment = 4;
	e->recursion = 2;
	e->rot_speed = (double)0.1;
	e->move_speed = (double)10.0;
	e->rebond = 0.8;
	e->sum = 1;
	e->live = 1;
	e->threads = 32;
	e->local_compute = 1;
	e->magic = MAGIC;
	e->help_actif = 0;
	e->credit_actif = 0;
	e->skybox_index = -1;
	e->skybox_total = count(g_skybox_sources);
	e->obj_tx_total = count(g_color_sources);
	e->tsp_tx_total = count(g_tsp_sources);
}
