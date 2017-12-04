/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_cylinders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:10:03 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:10:26 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	cyl_normal(t_obj *closest_obj)
{
	t_vector	a;
	t_vector	b;

	a = vector_sub(closest_obj->cross, closest_obj->ori);
	b = vector_scale(closest_obj->dir, vector_dot(a, closest_obj->dir));
	return (vector_normalize(vector_sub(a, b)));
}

static void	cyl_intersection_distance(t_obj *obj, t_ray ray)
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
	c->dot_a = vector_dot(ray.dir, obj->dir);
	c->sca_a = vector_scale(obj->dir, c->dot_a);
	c->sub_a = vector_sub(ray.dir, c->sca_a);
	obj->a = vector_dot(c->sub_a, c->sub_a);
}

static void	decompose_b_coef(t_obj *obj, t_vector v, t_cone_coef *c)
{
	c->dot_b = vector_dot(v, obj->dir);
	c->sca_b = vector_scale(obj->dir, c->dot_b);
	c->sub_b = vector_sub(v, c->sca_b);
	obj->b = 2 * vector_dot(c->sub_a, c->sub_b);
}

void		cyl_distance(t_obj *obj, t_ray ray)
{
	t_vector	v;
	t_cone_coef	c;

	v = vector_sub(ray.ori, obj->ori);
	decompose_a_coef(obj, ray, &c);
	decompose_b_coef(obj, v, &c);
	obj->c = vector_dot(c.sub_b, c.sub_b) - obj->radius;
	obj->d = obj->b * obj->b - (4.0 * obj->a * obj->c);
	if (obj->d > 0) //normalement quand discriminant = 0 le polynome admet une unique solution qui est x = - b/2a mais comme apres on fait x1 = (-b-sqrtD)/2a ou x2 = (-b+sqrtD)/2a si D valait 0, sqrtD = 0 donc x1 = (-b+ ou - 0)/2a == x = -b / 2a
		cyl_intersection_distance(obj, ray);
	else
		obj->cross_distance = -1;
}
