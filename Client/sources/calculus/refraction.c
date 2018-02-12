/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 14:28:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

double		schlick(double cosine, double index)
{
	double r;

	r = (1.0 - index) / (double)(1 + index);
	r = r * r;
	r = (r + ((1 - r) * pow((1 - cosine), 5.0)));
	return (r);
}

t_ray		launch_ray(t_env *e, t_obj *closest_obj, t_vector v, double cosine)
{
	t_ray		ray;
	double		reflect_probe;
	double		dt;
	double		discriminant;

	dt = vector_dot(vector_normalize(v), closest_obj->normal);
	discriminant = 1.0 - (e->ni_nt * e->ni_nt * (1 - (dt * dt)));
	if (discriminant > (double)0.0)
		reflect_probe = schlick(cosine, closest_obj->refraction);
	else
		reflect_probe = 1.0;
	if (randb() > reflect_probe)
	{
		ray.dir = vector_sub(vector_scale(vector_sub(v,
						vector_scale(closest_obj->normal, dt)), e->ni_nt),
						vector_scale(closest_obj->normal, sqrt(discriminant)));
		ray.ori = closest_obj->cross;
	}
	else
	{
		ray.dir = vector_sub(v, vector_scale(closest_obj->normal, 2.0 *
						vector_dot(v, closest_obj->normal)));
		ray.ori = closest_obj->cross;
	}
	return (ray);
}

t_vector	refraction(t_env *e, t_ray ray, t_obj *closest_obj)
{
	t_vector	v;
	t_vector	n;
	double		cosine;

	e->avoid = closest_obj;
	if (closest_obj->fuzz)
		ray.dir = vector_add(ray.dir, vector_scale(random_unit_sphere(),
						closest_obj->fuzz));
	v = ray.dir;
	n = closest_obj->normal;
	if (vector_dot(ray.dir, n) > (double)0.0)
	{
		e->ni_nt = closest_obj->refraction;
		cosine = closest_obj->refraction * vector_dot(v, n) /
						vector_magnitude(v);
	}
	else
	{
		e->ni_nt = 1.0 / (double)closest_obj->refraction;
		cosine = -vector_dot(v, n) / vector_magnitude(v);
	}
	ray = launch_ray(e, closest_obj, ray.dir, cosine);
	(closest_obj->marblesize) ? marble(e, closest_obj) : 0;
	return (vector_mul(compute_objects(e, ray, -1), closest_obj->color));
}
