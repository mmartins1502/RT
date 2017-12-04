/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cones.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 08:57:35 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:11:01 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	cone_normal(t_obj *closest_obj)
{
	double		k;
	double		m;
	t_vector	a;
	t_vector	b;
	t_vector	c;

	a = vector_sub(closest_obj->cross, closest_obj->ori);
	m = vector_dot(a, closest_obj->dir);
	c = vector_add(closest_obj->ori, vector_scale(closest_obj->dir, m));
	k = vector_magnitude(vector_sub(closest_obj->cross, c)) / m;
	b = vector_scale(closest_obj->dir, m * (1 + k * k));
	return (vector_normalize(vector_sub(a, b)));
}

static void	cone_intersection_distance(t_obj *obj, t_ray ray)
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

static void	decompose_a_coef(t_obj *obj, t_ray ray, t_cone_coef *c)
{
	c->dot_a = vector_dot(obj->dir, ray.dir);
	c->sca_a = vector_scale(obj->dir, c->dot_a);
	c->sub_a = vector_sub(ray.dir, c->sca_a);
	obj->a = c->csq * vector_dot(c->sub_a, c->sub_a);
	obj->a -= c->ssq * c->dot_a * c->dot_a;
}

static void	decompose_b_coef(t_obj *obj, t_vector v, t_cone_coef *c)
{
	c->dot_b = vector_dot(obj->dir, v);
	c->sca_b = vector_scale(obj->dir, c->dot_b);
	c->sub_b = vector_sub(v, c->sca_b);
	obj->b = 2.0 * c->csq * vector_dot(c->sub_a, c->sub_b);
	obj->b -= 2.0 * c->ssq * c->dot_a * c->dot_b;
}

void		cone_distance(t_obj *obj, t_ray ray)
{
	t_vector	v;
	t_cone_coef	c;

	c.csq = cos(obj->radius) * cos(obj->radius);
	c.ssq = sin(obj->radius) * sin(obj->radius);
	v = vector_sub(ray.ori, obj->ori);
	decompose_a_coef(obj, ray, &c);
	decompose_b_coef(obj, v, &c);
	obj->c = c.csq * vector_dot(c.sub_b, c.sub_b);
	obj->c -= c.ssq * c.dot_b * c.dot_b;
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0)
		cone_intersection_distance(obj, ray);
	else
		obj->cross_distance = -1;
}
