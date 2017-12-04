/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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
	return (t);
}

t_vector    skybox(t_env *e, t_vector dir)
{
	t_vector sky;
	dir = vector_normalize(dir);
	double u;
	double v;
	double phi = atan2(dir.z, dir.x);
	double theta = asin(dir.y);
	u = 1-(phi + M_PI) / (2*M_PI);
	v = (theta + M_PI/2) / M_PI;
	int i = u * e->current_skybox->w;
	int j = (double)(1.0 - v) * e->current_skybox->h;
	if (i < 0) i = 0;
	if (j < 0) j = 0;
	if (i > e->current_skybox->w - 1) i = e->current_skybox->w - 1;
	if (j > e->current_skybox->h - 1) j = e->current_skybox->h - 1;

	uint32_t *pixel_array = (uint32_t *)e->current_skybox->pixels;

	double r = ((pixel_array[j * e->current_skybox->w + i] >> 16) & 255) / (double)255.0;
	double g = ((pixel_array[j * e->current_skybox->w + i] >> 8) & 255) / (double)255.0;
	double b = ((pixel_array[j * e->current_skybox->w + i] >> 0) & 255) / (double)255.0;

	sky.x = r;
	sky.y = g;
	sky.z = b;
	return (sky);
}

t_vector	sky(t_env *e, t_vector dir, double t)
{
	if (e->current_skybox)
		return (skybox(e, dir));
	return (diffuse_sky(e, t));
	return ((t_vector){1, 1, 1});
	return ((t_vector){1, 0, 0});
	return ((t_vector){0, 0, 0});
}

t_vector	bounce_ray(t_env *e, t_obj *closest_obj, t_ray ray)
{
	if (closest_obj->damier)
		damier(closest_obj);
	if (closest_obj->reflection > 0)
		return (reflection(e, ray, closest_obj));
	else if (closest_obj->refraction > 0)
		return (refraction(e, ray, closest_obj));
	else
		return (diffuse(e, ray, closest_obj));
}

t_vector	compute_objects(t_env *e, t_ray ray)
{
	t_obj		*obj;
	t_obj		*closest_obj;
	double		t;

	e->depth++;
	obj = e->objects;
	closest_obj = NULL;
	t = -1;
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
	return (sky(e, ray.dir, t));
}
