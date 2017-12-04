/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_planes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 08:52:17 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	plane_normal(t_obj *closest_obj, t_ray ray)
{
	double		dot;
	t_vector	n;

	dot = vector_dot(ray.dir, closest_obj->dir);
	if (dot < 0)
		n = vector_negative(closest_obj->dir);
	else
		n = closest_obj->dir;
	return (vector_normalize(n));
}

static void	plane_intersection_distance(t_obj *obj, t_ray ray)
{
	double		distance;

	obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
	distance = vector_magnitude(vector_sub(ray.ori, obj->cross));
	obj->cross_distance = distance;
}

void		plane_distance(t_obj *obj, t_ray ray)
{
	t_vector	v;

	obj->b = vector_dot(obj->dir, ray.dir);
	if (obj->b > 0.0001)
	{
		v = vector_sub(obj->ori, ray.ori);
		obj->a = vector_dot(obj->dir, v);
		obj->t = obj->a / obj->b;
		if (obj->t > 0.000001)
		{
			plane_intersection_distance(obj, ray);
			return ;
		}
	}
	obj->cross_distance = -1;
}
