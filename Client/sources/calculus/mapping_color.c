/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:31:12 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 22:55:32 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	requierements(t_obj *obj)
{
	if (obj->texture_index == -1 ||
		(obj->height <= 0 && obj->type != OBJ_SPHERE))
		return (0);
	if (obj->type != OBJ_CYL &&
		obj->type != OBJ_CONE &&
		obj->type != OBJ_SPHERE)
		return (0);
	if (obj->reflection || obj->marblesize)
		return (0);
	return (1);
}

void		sphere_mapping(t_obj *obj)
{
	int			i;
	int			j;
	uint32_t	*pixel_array;
	double		color[3];

	i = obj->u * obj->current_texture->w;
	j = (double)(1.0 - obj->v) * obj->current_texture->h;
	if (i > obj->current_texture->w / 2)
		i -= obj->current_texture->w / 2;
	else
		i += obj->current_texture->w / 2;
	(i < 0) ? i = 0 : 0;
	(j < 0) ? j = 0 : 0;
	(i > obj->current_texture->w - 1) ? i = obj->current_texture->w - 1 : 0;
	(j > obj->current_texture->h - 1) ? j = obj->current_texture->h - 1 : 0;
	pixel_array = (uint32_t *)obj->current_texture->pixels;
	color[0] = ((pixel_array[j * obj->current_texture->w + i] >> 16) & 255) /
	(double)255.0;
	color[1] = ((pixel_array[j * obj->current_texture->w + i] >> 8) & 255) /
	(double)255.0;
	color[2] = ((pixel_array[j * obj->current_texture->w + i] >> 0) & 255) /
	(double)255.0;
	obj->color = (t_vector){color[0], color[1], color[2]};
}

void		cyl_mapping(t_obj *obj)
{
	int			i;
	int			j;
	uint32_t	*pixel_array;
	double		color[3];

	i = ((atan(obj->normal.z / obj->normal.x) + M_PI / 2) / M_PI)
		* obj->current_texture->w;
	j = (1 - (obj->alpha_cross / obj->height)) * obj->current_texture->h;
	(i < 0) ? i = 0 : 0;
	(j < 0) ? j = 0 : 0;
	(i > obj->current_texture->w - 1) ? i = obj->current_texture->w - 1 : 0;
	(j > obj->current_texture->h - 1) ? j = obj->current_texture->h - 1 : 0;
	pixel_array = (uint32_t *)obj->current_texture->pixels;
	color[0] = ((pixel_array[j * obj->current_texture->w + i] >> 16) & 255) /
	(double)255.0;
	color[1] = ((pixel_array[j * obj->current_texture->w + i] >> 8) & 255) /
	(double)255.0;
	color[2] = ((pixel_array[j * obj->current_texture->w + i] >> 0) & 255) /
	(double)255.0;
	obj->color = (t_vector){color[0], color[1], color[2]};
}

void		cone_mapping(t_obj *obj)
{
	int			i;
	int			j;
	uint32_t	*pixel_array;
	double		color[3];

	i = ((atan(obj->normal.z / obj->normal.x) + M_PI / 2) / M_PI)
		* obj->current_texture->w;
	j = (1 - (fabs(obj->alpha_cross) / obj->height)) * obj->current_texture->h;
	(i < 0) ? i = 0 : 0;
	(j < 0) ? j = 0 : 0;
	(i > obj->current_texture->w - 1) ? i = obj->current_texture->w - 1 : 0;
	(j > obj->current_texture->h - 1) ? j = obj->current_texture->h - 1 : 0;
	pixel_array = (uint32_t *)obj->current_texture->pixels;
	color[0] = ((pixel_array[j * obj->current_texture->w + i] >> 16) & 255) /
	(double)255.0;
	color[1] = ((pixel_array[j * obj->current_texture->w + i] >> 8) & 255) /
	(double)255.0;
	color[2] = ((pixel_array[j * obj->current_texture->w + i] >> 0) & 255) /
	(double)255.0;
	obj->color = (t_vector){color[0], color[1], color[2]};
}

void		color_mapping(t_obj *obj)
{
	if (!requierements(obj))
		return ;
	if (obj->type == OBJ_SPHERE)
		sphere_mapping(obj);
	else if (obj->type == OBJ_CYL)
		cyl_mapping(obj);
	else if (obj->type == OBJ_CONE)
		cone_mapping(obj);
}
