/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 14:12:09 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

static void		decompose_a_coef(t_obj *obj, t_ray ray, t_cone_coef *c)
{
	c->dot_a = vector_dot(ray.dir, obj->dir);
	c->sca_a = vector_scale(obj->dir, c->dot_a);
	c->sub_a = vector_sub(ray.dir, c->sca_a);
	obj->a = vector_dot(c->sub_a, c->sub_a);
}

static void		decompose_b_coef(t_obj *obj, t_vector v, t_cone_coef *c)
{
	c->dot_b = vector_dot(v, obj->dir);
	c->sca_b = vector_scale(obj->dir, c->dot_b);
	c->sub_b = vector_sub(v, c->sca_b);
	obj->b = 2 * vector_dot(c->sub_a, c->sub_b);
}

static void		decompose_c_coef(t_obj *obj, t_cone_coef *c)
{
	obj->c = vector_dot(c->sub_b, c->sub_b) - obj->radius;
}

static double	solution(t_env *e, t_obj *obj, t_ray ray, t_vector v)
{
	double	t;
	double	x;

	t = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
	x = vector_dot(ray.dir, obj->dir) * t + vector_dot(v, obj->dir);
	if (((x > 0 && x < obj->height) || obj->height <= 0) &&
		dist_priority(e, obj, ray, t) == t)
	{
		obj->alpha_cross = x;
		return (t);
	}
	t = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
	x = vector_dot(ray.dir, obj->dir) * t + vector_dot(v, obj->dir);
	if (((x > 0 && x < obj->height) || obj->height <= 0) &&
		dist_priority(e, obj, ray, t) == t)
	{
		obj->alpha_cross = x;
		return (t);
	}
	return (-1);
}

double			hit_cyl(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;
	t_cone_coef c;

	ray.dir = vector_normalize(ray.dir);
	v = vector_sub(ray.ori, obj->ori);
	decompose_a_coef(obj, ray, &c);
	decompose_b_coef(obj, v, &c);
	decompose_c_coef(obj, &c);
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0.00001)
		return (solution(e, obj, ray, v));
	return (-1);
}
