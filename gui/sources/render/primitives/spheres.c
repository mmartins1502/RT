/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		check_tsp(t_obj *closest_obj)
{
	if (!closest_obj->current_tsp)
		return (0);

	int i = closest_obj->u * closest_obj->current_tsp->w;
	int j = (double)(1.0 - closest_obj->v) * closest_obj->current_tsp->h;

	//tourner les textures par rapport aux poles
	if (i > closest_obj->current_tsp->w / 2)
		i -= closest_obj->current_tsp->w / 2;
	else
		i += closest_obj->current_tsp->w / 2;

	if (i < 0) i = 0;
	if (j < 0) j = 0;
	if (i > closest_obj->current_tsp->w - 1) i = closest_obj->current_tsp->w - 1;
	if (j > closest_obj->current_tsp->h - 1) j = closest_obj->current_tsp->h - 1;

	uint32_t *pixel_array = (uint32_t *)closest_obj->current_tsp->pixels;

	double r = ((pixel_array[j * closest_obj->current_tsp->w + i] >> 16) & 255);
	double g = ((pixel_array[j * closest_obj->current_tsp->w + i] >> 8) & 255);
	double b = ((pixel_array[j * closest_obj->current_tsp->w + i] >> 0) & 255);

	if (r > 1 && g > 1 & b > 1)
		return (-1);
	return (0);
}

static double	solution(t_obj *obj, t_ray ray, double t)
{
	double	phi;
	double	theta;

	obj->t = t;
	obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
	obj->normal = normal_sphere(obj);
	phi = atan2(obj->normal.x, obj->normal.z);
	theta = asin(obj->normal.y);
	obj->u = 1.0 - (phi + M_PI) / (2.0 * M_PI);
	obj->v = (theta + M_PI / 2.0) / M_PI;

	if (check_tsp(obj) == -1)
		return (-1);

	return (obj->t);
}

double			hit_sphere(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;
	double		t;
	double		s1 = -1;
	double		s2 = -1;

	v = vector_sub(ray.ori, obj->ori);
	obj->a = vector_dot(ray.dir, ray.dir);
	obj->b = 2.0 * vector_dot(ray.dir, v);
	obj->c = vector_dot(v, v) - obj->radius;
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0.00001)
	{
		t = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
		if (t > e->t_min && t < e->t_max)
		{
			s1 = solution(obj, ray, t);
			if (s1 != -1) return (s1);
		}
		t = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
		if (t > e->t_min && t < e->t_max)
		{
			s2 = solution(obj, ray, t);
			if (s2 != -1) return (s2);
		}
	}
	return (-1);
}
