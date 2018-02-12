/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:45:09 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 21:21:39 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static t_obj	*search_obj(t_env *e, t_ray ray)
{
	t_obj		*obj;
	t_obj		*closest_obj;
	double		t;

	obj = e->objects;
	closest_obj = NULL;
	t = -1;
	e->t_min = 0.0;
	e->t_max = INT_MAX;
	while (obj)
	{
		t = get_distance(e, obj, ray);
		if (t > 0.0)
		{
			e->t_max = t;
			closest_obj = obj;
		}
		obj = obj->next;
	}
	return (closest_obj);
}

void			select_obj(int x, int y, t_env *e)
{
	e->depth = 0;
	if (e->help_actif != 1)
		e->selected = search_obj(e, cam_ray(e, x, y, F_WIDTH /
			(double)F_HEIGHT));
}
