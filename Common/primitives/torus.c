/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 11:45:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 13:31:36 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

static void		set_obj(t_obj *obj, t_ray ray, double u, double v)
{
	t_vector a;
	t_vector q;

	a = vector_normalize(obj->dir);
	ray.dir = vector_normalize(ray.dir);
	q = vector_sub(ray.ori, obj->ori);
	u = vector_dot(a, q);
	v = vector_dot(a, ray.dir);
	obj->a = 1.0 - (v * v);
	obj->b = 2.0 * (vector_dot(q, ray.dir) - (u * v));
	obj->c = vector_dot(q, q) - (u * u);
	obj->d = vector_dot(q, q)
			+ (obj->radius * obj->radius) - (obj->small_r * obj->small_r);
}

static void		quartic_coefs(t_obj *obj, t_ray ray, double q[5], double r[4])
{
	q[4] = 1.0;
	q[3] = 4.0 * (vector_dot(vector_sub(ray.ori, obj->ori),
								vector_normalize(ray.dir)));
	q[2] = (2.0 * obj->d) + (0.25 * q[3] * q[3])
			- (4.0 * obj->radius * obj->radius * obj->a);
	q[1] = (q[3] * obj->d) - (4.0 * obj->radius * obj->radius * obj->b);
	q[0] = (obj->d * obj->d) - (4.0 * obj->radius * obj->radius * obj->c);
	r[0] = -1;
	r[1] = -1;
	r[2] = -1;
	r[3] = -1;
}

static double	solution(t_env *e, t_obj *obj, t_ray ray, double r[4])
{
	double	best;
	double	found;
	int		i;

	best = e->t_max;
	found = 0;
	i = -1;
	while (++i < 4)
	{
		if (r[i] > e->t_min && r[i] < best)
		{
			best = r[i];
			found = 1;
		}
	}
	if (!found)
		return (-1);
	obj->t = best;
	obj->cross = vector_factor(ray.ori, best, vector_normalize(ray.dir));
	obj->normal = normal_torus(obj);
	return (best);
}

double			hit_torus(t_env *e, t_obj *obj, t_ray ray)
{
	double	q[5];
	double	r[4];
	int		roots;

	set_obj(obj, ray, 0, 0);
	quartic_coefs(obj, ray, q, r);
	roots = solve_quartic(q, r);
	if (!roots)
		return (-1);
	return (solution(e, obj, ray, r));
}
