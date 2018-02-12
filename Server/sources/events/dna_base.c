/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dna_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:53:13 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	cyl_side_b(t_env *e, int row)
{
	double	tmp;
	double	tmp2;
	double	tmp3;
	t_obj	*obj;

	if (row == 0)
		return ;
	obj = new_obj();
	obj->type = 3;
	obj->ori.x = -20 * cos(row * 0.25);
	obj->ori.y = -20 * sin(row * 0.25);
	obj->ori.z = (5 * row) + (15 * row);
	tmp = (-20 * cos((row - 1) * 0.25)) - (-20 * cos(row * 0.25));
	obj->dir.x = tmp;
	tmp2 = (-20 * sin((row - 1) * 0.25)) - (-20 * sin(row * 0.25));
	obj->dir.y = tmp2;
	tmp3 = (5 * (row - 1) + 15 * (row - 1)) - (5 * row + 15 * row);
	obj->dir.z = tmp3;
	obj->dir = vector_normalize(obj->dir);
	obj->height = sqrt(tmp * tmp + tmp2 * tmp2 + tmp3 * tmp3);
	obj->radius = 4 * 4;
	obj->color.x = 0x33 / (double)255.0;
	obj->color.y = 0x33 / (double)255.0;
	obj->color.z = 0xff / (double)255.0;
	obj_push_back(&e->objects, obj);
}

void	cyl_side_a(t_env *e, int row)
{
	double	tmp;
	double	tmp2;
	double	tmp3;
	t_obj	*obj;

	if (row == 0)
		return ;
	obj = new_obj();
	obj->type = 3;
	obj->ori.x = 20 * cos(row * 0.25);
	obj->ori.y = 20 * sin(row * 0.25);
	obj->ori.z = (5 * row) + (15 * row);
	tmp = (20 * cos((row - 1) * 0.25)) - (20 * cos(row * 0.25));
	obj->dir.x = tmp;
	tmp2 = (20 * sin((row - 1) * 0.25)) - (20 * sin(row * 0.25));
	obj->dir.y = tmp2;
	tmp3 = (5 * (row - 1) + 15 * (row - 1)) - (5 * row + 15 * row);
	obj->dir.z = tmp3;
	obj->dir = vector_normalize(obj->dir);
	obj->height = sqrt(tmp * tmp + tmp2 * tmp2 + tmp3 * tmp3);
	obj->radius = 4 * 4;
	obj->color.x = 0x33 / (double)255.0;
	obj->color.y = 0x33 / (double)255.0;
	obj->color.z = 0xff / (double)255.0;
	obj_push_back(&e->objects, obj);
}

void	cyl_b(t_env *e, int row)
{
	t_obj *obj;

	obj = new_obj();
	obj->type = 3;
	obj->ori.x = 0;
	obj->ori.y = 0;
	obj->ori.z = (5 * row) + (15 * row);
	obj->dir.x = -cos(row * 0.25);
	obj->dir.y = -sin(row * 0.25);
	obj->dir.z = 0;
	obj->radius = 2 * 2;
	obj->height = 20;
	obj->color = (t_vector){1, 1, 1};
	obj->color_backup = obj->color;
	obj->light = 10;
	obj->emit = 1;
	obj_push_back(&e->objects, obj);
}

void	dna(t_env *e)
{
	int		row;
	int		atcg;

	row = 0;
	while (row < 30)
	{
		atcg = randb() > 0.5;
		sphere_mid(e, row);
		sphere_a(e, row, randb());
		sphere_b(e, row, randb());
		cyl_a(e, row);
		cyl_b(e, row);
		cyl_side_a(e, row);
		cyl_side_b(e, row);
		row++;
	}
}
