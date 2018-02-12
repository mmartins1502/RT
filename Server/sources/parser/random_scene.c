/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 15:03:53 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	basics(t_env *e)
{
	t_obj *obj;

	e->camera.ori = (t_vector){0, 100, 0};
	e->camera.dir = (t_vector){0, -0.8, 0};
	obj = new_obj();
	obj->type = OBJ_PLANE;
	obj->ori = (t_vector){0, -10, 0};
	obj->dir = (t_vector){0, -1, 0};
	obj->damier = 1;
	obj->damier1 = (t_vector){randb(), randb(), randb()};
	obj->damier2 = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

static void	create_random_sphere(t_env *e, int i, int j)
{
	t_obj	*obj;
	double	mat;

	obj = new_obj();
	obj->type = OBJ_SPHERE;
	obj->ori = (t_vector){i + (15.0 * randb()), 0, j + (15.0 * randb())};
	obj->radius = 100.0 * randb() + 50;
	obj->ori.y = sqrt(obj->radius) - 10;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj->color_backup = obj->color;
	mat = randb();
	if (mat < 0.33)
		;
	else if (mat < 0.66)
		obj->reflection = 2.00;
	else
		obj->refraction = 2.00;
	if (randb() < 0.1)
		obj->fuzz = randb();
	if (randb() < 0.1)
	{
		obj->marblesize = randb() / (double)1000.0;
		obj->marblecolor = (t_vector){randb(), randb(), randb()};
	}
	obj_push_back(&e->objects, obj);
}

void		random_spheres(t_env *e)
{
	int		i;
	int		j;

	basics(e);
	i = -300;
	while (i < 300)
	{
		j = 0;
		while (j < 300)
		{
			create_random_sphere(e, i, j);
			j += 40;
		}
		i += 40;
	}
}
