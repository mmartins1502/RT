/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:22:14 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/11 16:22:15 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		ft_save_plane(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>plane</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<direction>%f, %f, %f</direction>\n\t<height>%f</height>\n\t\
<color>0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z,
	obj->dir.x, obj->dir.y, obj->dir.z, sqrt(obj->height),
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
	if (obj->damier != 0)
		ft_save_damier(obj, file);
	if (obj->light)
		ft_save_light(obj, file);
}

void		ft_save_sphere(t_obj *obj, FILE *file)
{
	fprintf(file, "<object>\n\t<type>sphere</type>\n\t<origin>%f, %f, %f\
</origin>\n\t<radius>%f</radius>\n\t<height>%f</height>\n\t<color>\
0x%.2X, 0x%.2X, 0x%.2X</color>\n", obj->ori.x, obj->ori.y, obj->ori.z,
	sqrt(obj->radius), sqrt(obj->height), (int)(obj->color.x * 255.0),
	(int)(obj->color.y * 255.0), (int)(obj->color.z * 255.0));
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
	if (obj->tsp_index > -1)
		ft_save_transparent(obj, file);
	if (obj->texture_index > -1)
		ft_save_texture(obj, file);
}

void		ft_save_camera(t_obj *cam, FILE *file)
{
	fprintf(file, "<camera>\n\t<origin>%f, %f, %f</origin>\n\t<direction>%f, \
%f, %f</direction>\n", cam->ori.x, cam->ori.y,
	cam->ori.z, cam->dir.x, cam->dir.y, cam->dir.z);
	if (g_e->skybox_index > -1)
		ft_save_skybox(file);
	if (g_e->skybox_index > 0 && g_e->skybox_index < 4)
		ft_save_filter(file);
}

char		*new_name(void)
{
	char			*buffer;
	struct tm		*tm_info;
	struct timeval	tv;

	buffer = ft_strnew(42);
	gettimeofday(&tv, NULL);
	tm_info = localtime(&tv.tv_sec);
	strftime(buffer, 42, "%Y%m%d_%H%M%S", tm_info);
	return (buffer);
}

void		(*g_print_obj[255])(t_obj *obj, FILE *file) =
{
	[OBJ_SPHERE] = ft_save_sphere,
	[OBJ_CYL] = ft_save_cylinder,
	[OBJ_CONE] = ft_save_cone,
	[OBJ_PLANE] = ft_save_plane,
	[OBJ_TRI] = ft_save_triangle,
	[OBJ_SQUARE] = ft_save_square,
	[OBJ_TORUS] = ft_save_torus
};
