/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:10:49 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/10 21:12:49 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	scale_ori(t_env *e, t_obj *obj)
{
	obj->ori.x += e->camera.ori.x - (5.0 * MOVE_SPEED * cos(PITCH) * sin(YAW));
	obj->ori.y += e->camera.ori.y + (5.0 * MOVE_SPEED * sin(PITCH));
	obj->ori.z += e->camera.ori.z + (5.0 * MOVE_SPEED * cos(PITCH) * cos(YAW));
}

void	face_f(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){42, 42, 42};
	scale_ori(e, obj);
	obj->dir = (t_vector){0, -1, 0};
	obj->dir2 = (t_vector){0, 0, -1};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

void	face_e(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){42, 42, 42};
	scale_ori(e, obj);
	obj->dir = (t_vector){-1, 0, 0};
	obj->dir2 = (t_vector){0, 0, -1};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

void	face_d(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){42, 42, 42};
	scale_ori(e, obj);
	obj->dir = (t_vector){0, -1, 0};
	obj->dir2 = (t_vector){-1, 0, 0};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}
