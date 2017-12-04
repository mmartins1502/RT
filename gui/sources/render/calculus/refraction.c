/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		schlick(double cosine, double index)
{
	double r;

	r = (1.0 - index) / (double)(1 + index);
	r = r*r;
	r = (r + ((1 - r) * pow((1 - cosine), 5.0)));
	return (r);
}


t_vector	refraction(t_env *e, t_ray ray, t_obj *closest_obj)
{
	t_vector	v;
	t_vector	n;
	t_vector	uv;
	t_vector	outward_normal;
	t_vector	color;
	double		cosine;
	double		reflect_probe;

	if (closest_obj->fuzz)
	{
		ray.dir = vector_add(ray.dir, vector_scale(random_unit_sphere(), closest_obj->fuzz));
	}

	v = ray.dir;
	n = closest_obj->normal;

	if (vector_dot(ray.dir, n) > (double)0.0)
	{
		outward_normal = vector_negative(n);
		e->ni_nt = closest_obj->refraction;
		cosine = closest_obj->refraction * vector_dot(v, n) / vector_magnitude(v);
	}
	else
	{
		outward_normal = n;
		e->ni_nt = 1.0 / (double)closest_obj->refraction;
		cosine = -vector_dot(v, n) / vector_magnitude(v);
	}

	uv = vector_normalize(v);
	double dt = vector_dot(uv, n);
	double discriminant = 1.0 - (e->ni_nt * e->ni_nt * (1 - (dt * dt)));

	e->avoid = closest_obj;

	if (discriminant > (double)0.0)
		reflect_probe = schlick(cosine, closest_obj->refraction);
	else
		reflect_probe = 1.0;

	if (randb() > reflect_probe)
	{
		//true, refract

		ray.dir = vector_sub(
							 vector_scale(vector_sub(v, vector_scale(n, dt)), e->ni_nt),
							 vector_scale(n, sqrt(discriminant))
							 );
		ray.ori = closest_obj->cross;

		color = compute_objects(e, ray);

		color.x *= closest_obj->color.x;
		color.y *= closest_obj->color.y;
		color.z *= closest_obj->color.z;
	}
	else
	{
		//false, reflect

		ray.dir = vector_sub(v, vector_scale(n, 2.0 * vector_dot(v, n)));
		ray.ori = closest_obj->cross;

		color = compute_objects(e, ray);

		color.x *= closest_obj->color.x;
		color.y *= closest_obj->color.y;
		color.z *= closest_obj->color.z;
	}

	return (color);
}

