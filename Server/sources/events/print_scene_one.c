/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static const char	*g_type[] =
{
	[OBJ_SPHERE] = "sphere",
	[OBJ_CYL] = "cylinder",
	[OBJ_CONE] = "cone",
	[OBJ_PLANE] = "plane"
};

void	print_basics_obj(t_obj *obj, t_vector o, t_vector d)
{
	printf("\t<type>%s</type>\n", g_type[obj->type]);
	printf("\t<origin>%f, %f, %f</origin>\n", o.x, o.y, o.z);
	if (obj->type != OBJ_SPHERE)
		printf("\t<direction>%f, %f, %f</direction>\n", d.x, d.y, d.z);
	if (obj->reflection)
		printf("\t<reflection>%d</reflection>\n", obj->reflection);
	if (obj->refraction)
		printf("\t<refraction>%f</refraction>\n", obj->refraction);
	if (obj->fuzz)
		printf("\t<fuzz>%f</fuzz>\n", obj->fuzz);
	printf("\t<color>");
	printf("0x%.2X,", (int)(obj->color.x * 255.0));
	printf("0x%.2X,", (int)(obj->color.y * 255.0));
	printf("0x%.2X", (int)(obj->color.z * 255.0));
	printf("</color>\n");
}

void	print_radius_angle(t_obj *obj)
{
	if (obj->type == OBJ_SPHERE || obj->type == OBJ_CYL)
		printf("\t<radius>%f</radius>\n", sqrt(obj->radius));
	if (obj->type == OBJ_CONE)
		printf("\t<angle>%f</angle>\n", (obj->radius * 180.0) / M_PI);
}

void	print_marble(t_obj *obj)
{
	printf("\t<marblesize>%f</marblesize>\n", obj->marblesize);
	printf("\t<marblecolor>");
	printf("0x%.2X,", (int)(obj->marblecolor.x * 255.0));
	printf("0x%.2X,", (int)(obj->marblecolor.y * 255.0));
	printf("0x%.2X\n", (int)(obj->marblecolor.z * 255.0));
	printf("</marblecolor>\n");
}

void	print_damier(t_obj *obj)
{
	printf("\t<damier>%d</damier>\n", obj->damier);
	printf("\t<damier1>");
	printf("0x%.2X,", (int)(obj->damier1.x * 255.0));
	printf("0x%.2X,", (int)(obj->damier1.y * 255.0));
	printf("0x%.2X\n", (int)(obj->damier1.z * 255.0));
	printf("</damier1>\n");
	printf("\t<damier2>");
	printf("0x%.2X,", (int)(obj->damier2.x * 255.0));
	printf("0x%.2X,", (int)(obj->damier2.y * 255.0));
	printf("0x%.2X\n", (int)(obj->damier2.z * 255.0));
	printf("</damier2>\n");
}

void	print_light(t_obj *obj)
{
	printf("\t<light>%f</light>\n", obj->light);
}
