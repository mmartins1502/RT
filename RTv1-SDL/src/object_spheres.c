/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_spheres.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 08:51:23 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector		sphere_normal(t_obj *closest_obj)
{
	t_vector n;

	n = vector_sub(closest_obj->cross, closest_obj->ori);
	n = vector_normalize(n);
	return (n);
}

static	void	sphere_intersection_distance(t_obj *obj, t_ray ray)
{
	double		distance;

	obj->t1 = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
	obj->t2 = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
	if (obj->t1 > 0.000001)
		obj->t = obj->t1;
	else if (obj->t2 > 0.000001)
		obj->t = obj->t2;
	else
	{
		obj->cross_distance = -1;
		return ;
	}
	obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
	distance = vector_magnitude(vector_sub(ray.ori, obj->cross));
	obj->cross_distance = distance;
}

void			sphere_distance(t_obj *obj, t_ray ray)
{
	t_vector	v;

	v = vector_sub(ray.ori, obj->ori);
	obj->a = vector_dot(ray.dir, ray.dir);
	obj->b = 2.0 * vector_dot(ray.dir, v);
	obj->c = vector_dot(v, v) - obj->radius;
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0)
		sphere_intersection_distance(obj, ray);
	else
		obj->cross_distance = -1;
}
