/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_dist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:10:46 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/10 14:11:49 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

double		dist_priority(t_env *e, t_obj *obj, t_ray ray, double t)
{
	if (t > e->t_min && t < e->t_max)
	{
		obj->t = t;
		obj->cross = vector_factor(ray.ori, t, ray.dir);
		obj->normal = normal_cone(obj);
		return (t);
	}
	return (-1);
}
