/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/01 16:00:20 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	basics(t_env *e)
{
	t_obj *obj;

	e->camera.ori = (t_vector){0, 100, 0};
	e->camera.dir = (t_vector){0, -0.8, 0};
	// obj = new_obj();
	// obj->type = OBJ_PLANE;
	// obj->ori = (t_vector){0, -10, 0};
	// obj->dir = (t_vector){0, -1, 0};
	// obj->damier = 1;
	// obj->damier1 = (t_vector){randb(), randb(), randb()};
	// obj->damier2 = (t_vector){randb(), randb(), randb()};
	// obj_push_back(&e->objects, obj);
}

static void	create_random_sphere(t_env *e, int i, int j, int k)
{
	t_obj	*obj;
	double	mat;

	obj = new_obj();
	obj->type = OBJ_SPHERE;
	obj->ori = (t_vector){k, i, j};
	obj->radius = 1.0 * randb() + 50;
	obj->ori.y = i;
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
//	if (randb() < 0.1)
//	{
//		obj->marblesize = randb() / (double)1000.0;
//		obj->marblecolor = (t_vector){255.0 * randb(), 255.0 * randb(), 255.0 * randb()};
//	}
	obj_push_back(&e->objects, obj);
}

void		random_spheres(t_env *e)
{
	int		i;
	int		j;
	int		k;
	int		total = 0;

	k = 0;
	basics(e);
	while (k < 50)
	{
		i = 0;
		while (i < 50)
		{
			j = 0;
			while (j < 50)
			{
				create_random_sphere(e, i, j, k);
				total++;
				j += 10;
			}
			i += 10;
		}
		k += 10;
	}
	ft_printf("total obj = %d\n", total);
}
