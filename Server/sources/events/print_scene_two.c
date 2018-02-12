/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:39:48 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 03:47:33 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	print_camera(t_env *e)
{
	t_vector	o;
	t_vector	d;

	o = e->camera.ori;
	d = e->camera.dir;
	printf("<camera>\n");
	printf("\t<origin>%f, %f, %f</origin>\n", o.x, o.y, o.z);
	printf("\t<direction>%f, %f, %f</direction>\n", d.x, d.y, d.z);
	printf("</camera>\n");
}

void	print_scene(t_env *e)
{
	t_obj *obj;

	obj = e->objects;
	print_camera(e);
	while (obj)
	{
		printf("<object>\n");
		print_basics_obj(obj, obj->ori, obj->dir);
		print_radius_angle(obj);
		(obj->marblesize) ? print_marble(obj) : 0;
		(obj->damier) ? print_damier(obj) : 0;
		(obj->emit) ? print_light(obj) : 0;
		printf("</object>\n");
		obj = obj->next;
	}
}
