/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dna_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:47:13 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cyl_a(t_env *e, int row)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 3;
	obj->ori.x = 0;
	obj->ori.y = 0;
	obj->ori.z = (5 * row) + (15 * row);
	obj->dir.x = cos(row * 0.25);
	obj->dir.y = sin(row * 0.25);
	obj->dir.z = 0;
	obj->radius = 2 * 2;
	obj->height = 20;
	obj->color = (t_vector){1, 1, 1};
	obj->color_backup = obj->color;
	obj->light = 10;
	obj->emit = 1;
	obj_push_back(&e->objects, obj);
}

void	sphere_b(t_env *e, int row, double atcg)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 1;
	obj->ori.x = -20 * cos(row * 0.25);
	obj->ori.y = -20 * sin(row * 0.25);
	obj->ori.z = 5 * row + 15 * row;
	obj->radius = 7 * 7;
	if (atcg < 0.5)
	{
		obj->color.x = 0xff / (double)255.0;
		obj->color.y = 0x33 / (double)255.0;
		obj->color.z = 0xff / (double)255.0;
	}
	else
	{
		obj->color.x = 0x33 / (double)255.0;
		obj->color.y = 0xff / (double)255.0;
		obj->color.z = 0x33 / (double)255.0;
	}
	obj_push_back(&e->objects, obj);
}

void	sphere_a(t_env *e, int row, double atcg)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 1;
	obj->ori.x = 20 * cos(row * 0.25);
	obj->ori.y = 20 * sin(row * 0.25);
	obj->ori.z = (5 * row) + (15 * row);
	obj->radius = 7 * 7;
	if (atcg < 0.5)
	{
		obj->color.x = 0x33 / (double)255.0;
		obj->color.y = 0x33 / (double)255.0;
		obj->color.z = 0xff / (double)255.0;
	}
	else
	{
		obj->color.x = 0xff / (double)255.0;
		obj->color.y = 0x33 / (double)255.0;
		obj->color.z = 0x33 / (double)255.0;
	}
	obj_push_back(&e->objects, obj);
}

void	sphere_mid(t_env *e, int row)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = OBJ_SPHERE;
	obj->ori.x = 0;
	obj->ori.y = 0;
	obj->ori.z = (5 * row) + (15 * row);
	obj->radius = 3.5 * 3.5;
	obj->color.x = 0xFF / (double)255.0;
	obj->color.y = 0xFF / (double)255.0;
	obj->color.z = 0xFF / (double)255.0;
	obj->light = 10;
	obj->emit = 1;
	obj_push_back(&e->objects, obj);
}
