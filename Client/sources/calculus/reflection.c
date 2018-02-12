/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 13:46:49 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

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
	e->avoid = closest_obj;
	if (closest_obj->fuzz)
	{
		ray.dir = vector_add(ray.dir, vector_scale(random_unit_sphere(),
															closest_obj->fuzz));
		ray.dir = vector_normalize(ray.dir);
	}
	if ((double)vector_dot(ray.dir, n) > (double)0.0)
		color = compute_objects(e, ray, -1);
	else
		color = closest_obj->color;
	(closest_obj->marblesize) ? marble(e, closest_obj) : 0;
	return (vector_mul(color, closest_obj->color));
}
