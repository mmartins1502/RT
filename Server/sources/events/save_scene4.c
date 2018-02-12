/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:18:17 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/11 16:18:20 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		ft_save_square(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>square</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<direction2>%f,\
%f, %f</direction2>\n\t<lenght1>%f</lenght1>\n\t<lenght2>%f</lenght2>\n\t\
<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x,
	obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, obj->dir.z,
	obj->dir2.x, obj->dir2.y, obj->dir2.z, obj->len1, obj->len2,
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

void		ft_save_triangle(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>triangle</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<direction2>%f,\
%f, %f</direction2>\n\t<lenght1>%f</lenght1>\n\t<lenght2>%f\
</lenght2>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x,
	obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y, obj->dir.z,
	obj->dir2.x, obj->dir2.y, obj->dir2.z, obj->len1, obj->len2,
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

void		ft_save_cone(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>cone</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
</radius>\n\t<height>%f</height>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X\
</color>\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x,
	obj->dir.y, obj->dir.z, sqrt(obj->radius), sqrt(obj->height),
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

void		ft_save_cylinder(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>cylinder</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
</radius>\n\t<height>%f</height>\n\t<color>0x%.2X, 0x%.2X, 0x%.2X</color>\
\n", obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y,
	obj->dir.z, sqrt(obj->radius), sqrt(obj->height),
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

void		ft_save_torus(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>torus</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<radius>%f\
</radius>\n\t<small_radius>%f</small_radius>\n\t<color>0x%.2X,\
0x%.2X, 0x%.2X</color>\n",
	obj->ori.x, obj->ori.y, obj->ori.z, obj->dir.x, obj->dir.y,
	obj->dir.z, sqrt(obj->radius), sqrt(obj->small_r),
	(int)(obj->color.x * 255.0), (int)(obj->color.y * 255.0),
	(int)(obj->color.z * 255.0));
	if (obj->reflection)
		ft_save_reflection(obj, file);
	if (obj->refraction)
		ft_save_refraction(obj, file);
	if (obj->fuzz)
		ft_save_fuzz(obj, file);
	if (obj->marblesize)
		ft_save_marble(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}
