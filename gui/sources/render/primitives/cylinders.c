/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

static double	solution(t_env *e, t_obj *obj, t_ray ray)
{
	double t;

	t = (-obj->b - sqrt(obj->d)) / (2.0 * obj->a);
	if (t > e->t_min && t < e->t_max && t)
	{
		obj->t = t;
		obj->cross = vector_factor(ray.ori, t, ray.dir);
		obj->normal = normal_cyl(obj);
		return (t);
	}
	t = (-obj->b + sqrt(obj->d)) / (2.0 * obj->a);
	if (t > e->t_min && t < e->t_max)
	{
		obj->t = t;
		obj->cross = vector_factor(ray.ori, t, ray.dir);
		obj->normal = normal_cyl(obj);
		return (t);
	}
	return (-1);
}

double			hit_cyl(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v;
	t_cone_coef c;

	v = vector_sub(ray.ori, obj->ori);
	decompose_a_coef(obj, ray, &c);
	decompose_b_coef(obj, v, &c);
	decompose_c_coef(obj, &c);
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0.00001)
		return (solution(e, obj, ray));
	return (-1);
}
