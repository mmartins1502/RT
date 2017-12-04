/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static const char	*g_type[] =
{
	[OBJ_SPHERE] = "sphere",
	[OBJ_CYL] = "cylinder",
	[OBJ_CONE] = "cone",
	[OBJ_PLANE] = "plane"
};

void	print_origin(t_vector o)
{
	printf("\t<origin>");
	printf("%f, %f, %f", o.x, o.y, o.z);
	printf("</origin>\n");
}

void	print_direction(t_vector o)
{
	printf("\t<direction>");
	printf("%f, %f, %f", o.x, o.y, o.z);
	printf("</direction>\n");
}

void	print_type(t_obj *obj)
{
	printf("\t<type>");
	printf("%s", g_type[obj->type]);
	printf("</type>\n");
}

void	print_radius(t_obj *obj)
{
	printf("\t<radius>");
	printf("%f", sqrt(obj->radius));
	printf("</radius>\n");
}

void	print_angle(t_obj *obj)
{
	printf("\t<angle>");
	printf("%f", (obj->radius * 180.0) / M_PI);
	printf("</angle>\n");
}

void	print_color(t_obj *obj)
{
	printf("\t<color>");
	printf("%#.2X,", (int)(obj->color.x * 255.0));
	printf("%#.2X,", (int)(obj->color.y * 255.0));
	printf("%#.2X\n", (int)(obj->color.z * 255.0));
	printf("</color>\n");
}

void	print_reflection(t_obj *obj)
{
	printf("\t<reflection>");
	printf("%f", obj->reflection);
	printf("</reflection>\n");
}

void	print_refraction(t_obj *obj)
{
	printf("\t<refraction>");
	printf("%f", obj->refraction);
	printf("</refraction>\n");
}

void	print_fuzz(t_obj *obj)
{
	printf("\t<fuzz>");
	printf("%f", obj->fuzz);
	printf("</fuzz>\n");
}

void	print_marble(t_obj *obj)
{
	printf("\t<marblesize>");
	printf("%f", obj->marblesize);
	printf("</marblesize>\n");
	printf("\t<marblecolor>");
	printf("%#.2X,", (int)(obj->marblecolor.x * 255.0));
	printf("%#.2X,", (int)(obj->marblecolor.y * 255.0));
	printf("%#.2X\n", (int)(obj->marblecolor.z * 255.0));
	printf("</marblecolor>\n");
}

void	print_damier(t_obj *obj)
{
	printf("\t<damier>");
	printf("%d", obj->damier);
	printf("</damier>\n");
	printf("\t<damier1>");
	printf("%#.2X,", (int)(obj->damier1.x * 255.0));
	printf("%#.2X,", (int)(obj->damier1.y * 255.0));
	printf("%#.2X\n", (int)(obj->damier1.z * 255.0));
	printf("</damier1>\n");
	printf("\t<damier2>");
	printf("%#.2X,", (int)(obj->damier2.x * 255.0));
	printf("%#.2X,", (int)(obj->damier2.y * 255.0));
	printf("%#.2X\n", (int)(obj->damier2.z * 255.0));
	printf("</damier2>\n");
}

void	print_light(t_obj *obj)
{
	printf("\t<light>");
	printf("%d,", (int)obj->light.x);
	printf("%d,", (int)obj->light.y);
	printf("%d\n", (int)obj->light.z);
	printf("</light>\n");
}

void	print_camera(t_env *e)
{
	printf("<camera>\n");
	print_origin(e->camera.ori);
	print_direction(e->camera.dir);
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
		print_type(obj);
		print_origin(obj->ori);
		(obj->type != OBJ_SPHERE) ? print_direction(obj->dir) : 0;
		(obj->type == OBJ_SPHERE || obj->type == OBJ_CYL) ? print_radius(obj) : 0;
		(obj->type == OBJ_CYL) ? print_angle(obj) : 0;
		print_color(obj);
		(obj->reflection) ? print_reflection(obj) : 0;
		(obj->refraction) ? print_refraction(obj) : 0;
		(obj->fuzz) ? print_fuzz(obj) : 0;
		(obj->marblesize) ? print_marble(obj) : 0;
		(obj->damier) ? print_damier(obj) : 0;
		(obj->emit) ? print_light(obj) : 0;
		printf("</object>\n");
		obj = obj->next;
	}
}
