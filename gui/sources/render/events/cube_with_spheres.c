/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_with_spheres.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:14:17 by mmartins          #+#    #+#             */
/*   Updated: 2017/12/04 17:08:59 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	create_random_sphere(t_env *e, int i, int j, int k)
{
	t_obj	*obj;
	double	mat;

	obj = new_obj();
	obj->type = OBJ_SPHERE;
	// obj->ori = (t_vector){k, i, j};
	obj->radius = 3.33;
	// obj->ori.y = i;
    obj->ori.x = e->camera.ori.x - (k + 7.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (i + 7.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (j + 7.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->color = (t_vector){randb(), randb(), randb()};
	mat = randb();
	if (mat < 0.33)
		;
	else if (mat < 0.66)
		obj->reflection = 2.00;
	else
		obj->refraction = 2.00;
	if (randb() < 0.1)
		obj->fuzz = randb();
	// if (randb() < 0.1)
	// {
	// 	obj->marblesize = randb() / (double)1000.0;
	// 	obj->marblecolor = (t_vector){255.0 * randb(), 255.0 * randb(), 255.0 * randb()};
	// }
	obj_push_back(&e->objects, obj);
}

void		cube_with_spheres(t_env *e)
{
	int		i;
	int		j;
	int		k;
	int		total = 0;

	k = 0;
	// basics(e);
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
	e->b_actif = -1;
}