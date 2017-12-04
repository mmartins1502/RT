/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	reflection(t_env *e, t_ray ray, t_obj *closest_obj)
{
	t_vector	color;
	t_vector	v;
	t_vector	n;
	t_vector	r;

	v = ray.dir;
	n = closest_obj->normal;

	r = vector_sub(v, vector_scale(n, 2.0 * vector_dot(v, n)));

	ray.dir = r;
	ray.ori = closest_obj->cross;

	vector_add(ray.ori, e->camera.ori);

	e->avoid = closest_obj;

	if (closest_obj->fuzz)
	{
		ray.dir = vector_add(ray.dir, vector_scale(random_unit_sphere(), closest_obj->fuzz));
		ray.dir = vector_normalize(ray.dir);
	}

	if ((double)vector_dot(ray.dir, n) > (double)0.0)
		color = compute_objects(e, ray);
	else
		color = closest_obj->color;

	if (closest_obj->marblesize)
		marble(e, &color, closest_obj);

	color.x *= closest_obj->color.x;
	color.y *= closest_obj->color.y;
	color.z *= closest_obj->color.z;

	return (color);
}

