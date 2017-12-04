/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:11:08 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	get_distance(t_obj *obj, t_ray ray)
{
	if (obj->type == OBJ_SPHERE)
		sphere_distance(obj, ray);
	else if (obj->type == OBJ_PLANE)
		plane_distance(obj, ray);
	else if (obj->type == OBJ_CYL)
		cyl_distance(obj, ray);
	else if (obj->type == OBJ_CONE)
		cone_distance(obj, ray);
	else
		quit("Unexpected object type. Aborting.");
}

void		compute_objects(t_env *e, t_ray ray)
{
	t_obj		*obj;
	t_obj		*closest_obj;
	double		distance_min;

	obj = e->objects;
	closest_obj = NULL;
	distance_min = INT_MAX;
	while (obj)
	{
		get_distance(obj, ray);
		if (obj->cross_distance > 0 && obj->cross_distance < distance_min)
		{
			distance_min = obj->cross_distance;
			closest_obj = obj;
		}
		obj = obj->next;
	}
	if (closest_obj)
	{
		compute_closest_obj(e, closest_obj);
	}
}