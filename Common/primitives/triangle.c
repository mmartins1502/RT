/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:40:51 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/10 22:57:01 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

void			size_interpretor(t_obj *obj, t_vector *v1, t_vector *v2)
{
	*v1 = vector_sub(obj->ori, vector_scale(vector_negative(obj->dir),
	obj->len1));
	*v2 = vector_sub(obj->ori, vector_scale(vector_negative(obj->dir2),
	obj->len2));
}

static int		triangle_edge(t_vector a, t_vector b, t_vector p, t_vector n)
{
	t_vector		edge;
	t_vector		vp;
	t_vector		c;

	edge = vector_sub(a, b);
	vp = vector_sub(p, b);
	c = vector_cross(edge, vp);
	if (vector_dot(n, c) < 0)
		return (-1);
	return (1);
}

static double	ray_dist(t_vector n, t_ray ray, t_obj *obj)
{
	double	d;
	double	n_dot_raydir;
	double	t;

	n_dot_raydir = vector_dot(n, ray.dir);
	if (fabs(n_dot_raydir) < 0.00000001)
		return (-1);
	d = vector_dot(n, obj->ori);
	t = (vector_dot(n, ray.ori) - d) / -n_dot_raydir;
	if (t < 0)
		return (-1);
	return (t);
}

double			hit_tri(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	n;
	t_vector	p;
	double		t;

	size_interpretor(obj, &v1, &v2);
	n = normal_triangle(obj, v1, v2);
	if ((t = ray_dist(n, ray, obj)) < 0)
		return (-1);
	p = vector_factor(ray.ori, t, ray.dir);
	if (triangle_edge(v1, obj->ori, p, n) == -1 || triangle_edge(v2, v1, p, n)
		== -1 || triangle_edge(obj->ori, v2, p, n) == -1)
		return (-1);
	if (t < e->t_min || t > e->t_max)
		return (-1);
	obj->t = t;
	obj->cross = vector_factor(ray.ori, t, ray.dir);
	if (vector_dot(n, ray.dir) > 1)
		obj->normal = vector_normalize(vector_negative(n));
	else
		obj->normal = vector_normalize(n);
	return (t);
}
