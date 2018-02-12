/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscelaneous.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 19:58:38 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

double		randb(void)
{
	return (rand() / (double)RAND_MAX);
}

t_vector	random_unit_sphere(void)
{
	t_vector p;

	p = vector_scale((t_vector){randb(), randb(), randb()}, 2.0);
	p = vector_sub(p, (t_vector){1.0, 1.0, 1.0});
	while (vector_dot(p, p) >= 1.0)
	{
		p = vector_scale((t_vector){randb(), randb(), randb()}, 2.0);
		p = vector_sub(p, (t_vector){1.0, 1.0, 1.0});
	}
	return (p);
}

t_vector	adjust_color(t_vector c)
{
	((int)c.x > 255.0) ? c.x = 255.0 : 0;
	((int)c.y > 255.0) ? c.y = 255.0 : 0;
	((int)c.z > 255.0) ? c.z = 255.0 : 0;
	((int)c.x < 0.0) ? c.x = 0.0 : 0;
	((int)c.y < 0.0) ? c.y = 0.0 : 0;
	((int)c.z < 0.0) ? c.z = 0.0 : 0;
	return (c);
}

t_vector	diffuse_sky(t_env *e, double t)
{
	t_vector	sky;
	t_vector	a;
	t_vector	b;

	t = 0.5 * (double)(e->vpos + 0.5);
	a = (t_vector){0.5, 0.7, 1.0};
	b = (t_vector){1.0, 1.0, 1.0};
	a = vector_scale(a, t);
	b = vector_scale(b, 1.0 - t);
	sky = vector_add(a, b);
	sky.x = fabs(sky.x / 2.0);
	sky.y = fabs(sky.y / 2.0);
	sky.z = fabs(sky.z);
	(sky.x > 1.0) ? sky.x = 1.0 : 0;
	(sky.y > 1.0) ? sky.y = 1.0 : 0;
	(sky.z > 1.0) ? sky.z = 1.0 : 0;
	return (sky);
}

void		damier(t_obj *closest_obj)
{
	double sines;

	sines = sin(closest_obj->cross.x / closest_obj->damier) *
			sin(closest_obj->cross.y / closest_obj->damier) *
			sin(closest_obj->cross.z / closest_obj->damier);
	if (sines < (double)0.0)
		closest_obj->color = closest_obj->damier1;
	else
		closest_obj->color = closest_obj->damier2;
}
