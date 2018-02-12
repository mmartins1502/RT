/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 13:42:36 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

double		get_distance(t_env *e, t_obj *obj, t_ray ray)
{
	double t;

	t = -1;
	if (obj->type == OBJ_SPHERE)
		t = hit_sphere(e, obj, ray);
	else if (obj->type == OBJ_PLANE)
		t = hit_plane(e, obj, ray);
	else if (obj->type == OBJ_CYL)
		t = hit_cyl(e, obj, ray);
	else if (obj->type == OBJ_CONE)
		t = hit_cone(e, obj, ray);
	else if (obj->type == OBJ_TORUS)
		t = hit_torus(e, obj, ray);
	else if (obj->type == OBJ_TRI)
		t = hit_tri(e, obj, ray);
	else if (obj->type == OBJ_SQUARE)
		t = hit_square(e, obj, ray);
	return (t);
}

t_vector	skybox(t_env *e, t_vector dir, double u, double v)
{
	int			i;
	int			j;
	uint32_t	*pixel_array;
	double		color[3];

	u = 1 - (atan2(dir.z, dir.x) + M_PI) / (2 * M_PI);
	v = (asin(dir.y) + M_PI / 2.0) / M_PI;
	i = u * e->current_skybox->w;
	j = (double)(1.0 - v) * e->current_skybox->h;
	(i < 0) ? i = 0 : 0;
	(j < 0) ? j = 0 : 0;
	(i > e->current_skybox->w - 1) ? i = e->current_skybox->w - 1 : 0;
	(j > e->current_skybox->h - 1) ? j = e->current_skybox->h - 1 : 0;
	pixel_array = (uint32_t *)e->current_skybox->pixels;
	color[0] = ((pixel_array[j * e->current_skybox->w + i] >> 16) & 255) /
																(double)255.0;
	color[1] = ((pixel_array[j * e->current_skybox->w + i] >> 8) & 255) /
																(double)255.0;
	color[2] = ((pixel_array[j * e->current_skybox->w + i] >> 0) & 255) /
																(double)255.0;
	return ((t_vector){color[0], color[1], color[2]});
}

t_vector	sky(t_env *e, t_vector dir, double t)
{
	if (e->current_skybox)
		return (skybox(e, vector_normalize(dir), 42, 42));
	return (diffuse_sky(e, t));
}

t_vector	bounce_ray(t_env *e, t_obj *closest_obj, t_ray ray)
{
	ray.dir = vector_normalize(ray.dir);
	if (closest_obj->damier)
		damier(closest_obj);
	if (closest_obj->reflection > 0)
		return (reflection(e, ray, closest_obj));
	else if (closest_obj->refraction > 0)
		return (refraction(e, ray, closest_obj));
	else
		return (diffuse(e, ray, closest_obj));
}

t_vector	compute_objects(t_env *e, t_ray ray, double t)
{
	t_obj		*obj;
	t_obj		*closest_obj;

	e->depth++;
	obj = e->objects;
	closest_obj = NULL;
	e->t_min = 0.0;
	e->t_max = INT_MAX;
	while (obj)
	{
		if (e->avoid != obj)
		{
			t = get_distance(e, obj, ray);
			if (t > 0.0)
				e->t_max = t;
			if (t > 0.0)
				closest_obj = obj;
		}
		obj = obj->next;
	}
	if (closest_obj && e->depth < e->recursion)
		return (bounce_ray(e, closest_obj, ray));
	if (closest_obj)
		return (live_preview(closest_obj));
	return (sky(e, ray.dir, t));
}
