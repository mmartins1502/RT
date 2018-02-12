/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

double	hit_plane(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;
	double		t;
	double		l;

	ray.dir = vector_normalize(ray.dir);
	obj->b = vector_dot(obj->dir, ray.dir);
	if (obj->b > 0.00001)
	{
		v = vector_sub(obj->ori, ray.ori);
		obj->a = vector_dot(obj->dir, v);
		t = obj->a / obj->b;
		if (t > e->t_min && t < e->t_max)
		{
			obj->t = t;
			obj->cross = vector_factor(ray.ori, t, ray.dir);
			obj->normal = normal_plane(obj, ray);
			l = vector_magnitude(vector_sub(obj->cross, obj->ori));
			if ((l > 0 && l < obj->height) || obj->height <= 0)
				return (t);
		}
	}
	return (-1);
}
