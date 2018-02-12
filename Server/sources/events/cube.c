/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:41:45 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		face_c(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){0, 0, 0};
	scale_ori(e, obj);
	obj->dir = (t_vector){0, 1, 0};
	obj->dir2 = (t_vector){0, 0, 1};
	obj->len2 = size;
	obj->len1 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

static void		face_b(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){0, 0, 0};
	scale_ori(e, obj);
	obj->dir = (t_vector){1, 0, 0};
	obj->dir2 = (t_vector){0, 0, 1};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

static void		face_a(t_env *e, double size)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SQUARE;
	obj->ori = (t_vector){0, 0, 0};
	scale_ori(e, obj);
	obj->dir = (t_vector){0, 1, 0};
	obj->dir2 = (t_vector){1, 0, 0};
	obj->len1 = size;
	obj->len2 = size;
	obj->color = (t_vector){randb(), randb(), randb()};
	obj_push_back(&e->objects, obj);
}

void			create_cube(t_env *e)
{
	double	size;

	size = 42;
	face_a(e, size);
	face_b(e, size);
	face_c(e, size);
	face_d(e, size);
	face_e(e, size);
	face_f(e, size);
}
