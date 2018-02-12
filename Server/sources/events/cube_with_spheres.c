/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_with_spheres.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:14:17 by mmartins          #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	create_random_sphere(t_env *e, int i, int j, int k)
{
	t_obj	*obj;
	double	mat;

	obj = new_obj();
	obj->type = OBJ_SPHERE;
	obj->radius = 3.33;
	obj->ori.x = e->camera.ori.x - (k + 7 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (i + 7 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (j + 7 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->color_backup = obj->color;
	mat = randb();
	if (mat < 0.33)
		;
	else if (mat < 0.66)
		obj->reflection = 1;
	else
		obj->refraction = 2.00;
	if (randb() < 0.1)
		obj->fuzz = randb();
	obj_push_back(&e->objects, obj);
}

void		cube_with_spheres(t_env *e)
{
	int		i;
	int		j;
	int		k;
	int		total;

	total = 0;
	k = 0;
	while (k < 10)
	{
		i = 0;
		while (i < 10)
		{
			j = 0;
			while (j < 10)
			{
				create_random_sphere(e, i, j, k);
				total++;
				j += 3;
			}
			i += 3;
		}
		k += 3;
	}
}
