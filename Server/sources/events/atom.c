/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solar_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 05:31:51 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:50:43 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_obj	*new_torus(t_env *e)
{
	t_obj	*obj;

	obj = new_obj();
	obj->type = OBJ_TORUS;
	obj->small_r = 0.3;
	obj->radius = 10 + (randb() * 3);
	obj->ori.x = e->camera.ori.x - (5.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (5.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (5.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->dir = vector_normalize((t_vector){	2 * randb() - 0.5,
											2 * randb() - 0.5,
											2 * randb() - 0.5});
	return (obj);
}

void	three_rings(t_env *e)
{
	t_obj	*obj;

	obj = new_torus(e);
	obj->color = (t_vector){1, 0, 0};
	obj->color_backup = obj->color;
	obj_push_back(&e->objects, obj);
	obj = new_torus(e);
	obj->color = (t_vector){0, 1, 0};
	obj->color_backup = obj->color;
	obj_push_back(&e->objects, obj);
	obj = new_torus(e);
	obj->color = (t_vector){0, 0, 1};
	obj->color_backup = obj->color;
	obj_push_back(&e->objects, obj);
}

void	protons(t_env *e)
{
	t_obj	*obj;

	obj = new_obj();
	obj->type = OBJ_SPHERE;
	obj->radius = 10;
	obj->emit = 1.0;
	obj->light = 10.0;
	obj->ori.x = e->camera.ori.x - (5.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y = e->camera.ori.y + (5.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z = e->camera.ori.z + (5.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
	obj->color = (t_vector){1, 1, 1};
	obj->color_backup = obj->color;
	obj_push_back(&e->objects, obj);
}

void	atom(t_env *e)
{
	three_rings(e);
	protons(e);
}
