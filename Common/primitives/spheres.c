/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

int				check_tsp(t_obj *obj)
{
	int			i;
	int			j;
	uint32_t	*pixel_array;
	double		color[3];

	i = obj->u * obj->current_tsp->w;
	j = (double)(1.0 - obj->v) * obj->current_tsp->h;
	if (i > obj->current_tsp->w / 2.0)
		i -= obj->current_tsp->w / 2.0;
	else
		i += obj->current_tsp->w / 2.0;
	(i < 0) ? i = 0 : 0;
	(j < 0) ? j = 0 : 0;
	if (i > obj->current_tsp->w - 1.0)
		i = obj->current_tsp->w - 1.0;
	if (j > obj->current_tsp->h - 1.0)
		j = obj->current_tsp->h - 1.0;
	pixel_array = (uint32_t *)obj->current_tsp->pixels;
	color[0] = ((pixel_array[j * obj->current_tsp->w + i] >> 16) & 255);
	color[1] = ((pixel_array[j * obj->current_tsp->w + i] >> 8) & 255);
	color[2] = ((pixel_array[j * obj->current_tsp->w + i] >> 0) & 255);
	if (color[0] > 1 && color[1] > 1 & color[2] > 1)
		return (-1);
	return (0);
}

static double	solution(t_obj *obj, t_ray ray, double t)
{
	double		phi;
	double		theta;
	t_vector	v;

	obj->t = t;
	obj->cross = vector_factor(ray.ori, obj->t, ray.dir);
	obj->normal = normal_sphere(obj);
	phi = atan2(obj->normal.x, obj->normal.z);
	theta = asin(obj->normal.y);
	obj->u = 1.0 - (phi + M_PI) / (double)(2.0 * M_PI);
	obj->v = (theta + M_PI / 2.0) / (double)M_PI;
	v = vector_sub(obj->cross, obj->ori);
	v.y += sqrt(obj->radius);
	if (v.y > obj->height && obj->height > 0)
		return (-1);
	if (obj->current_tsp && check_tsp(obj) == -1)
		return (-1);
	return (obj->t);
}

double			hit_sphere(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;
	double		t;
	double		s1;
	double		s2;

	ray.dir = vector_normalize(ray.dir);
	v = vector_sub(ray.ori, obj->ori);
	obj->a = vector_dot(ray.dir, ray.dir);
	obj->b = 2.0 * vector_dot(ray.dir, v);
	obj->c = vector_dot(v, v) - obj->radius;
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0.00001)
	{
		t = (-obj->b - sqrt(obj->d)) / (double)(2.0 * obj->a);
		if (t > e->t_min && t < e->t_max)
			if ((s1 = solution(obj, ray, t)) != -1)
				return (s1);
		t = (-obj->b + sqrt(obj->d)) / (double)(2.0 * obj->a);
		if (t > e->t_min && t < e->t_max)
			if ((s2 = solution(obj, ray, t)) != -1)
				return (s2);
	}
	return (-1);
}
