/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:35:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 18:29:57 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	init_render_env(t_env *e)
{
	int	i;

	e->objects = NULL;
	e->avoid = NULL;
	perlin_generate(e);
	perlin_generate_perm((int *)&e->perm_x);
	perlin_generate_perm((int *)&e->perm_y);
	perlin_generate_perm((int *)&e->perm_z);
	e->color_array = (t_vector **)ft_memalloc(
										sizeof(t_vector *) * (F_HEIGHT + 1));
	e->frame_array = (int **)ft_memalloc(sizeof(t_vector *) * (F_HEIGHT + 1));
	i = -1;
	while (++i < (int)F_HEIGHT)
	{
		e->color_array[i] = (t_vector *)ft_memalloc(sizeof(t_vector) * F_WIDTH);
		e->frame_array[i] = (int *)ft_memalloc(sizeof(int) * F_WIDTH);
	}
	e->wait = 0;
	e->increment = 4;
	e->recursion = 2;
	e->sum = 1;
	e->threads = 32;
}
