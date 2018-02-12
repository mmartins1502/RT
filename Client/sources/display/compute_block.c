/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:29:47 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 10:17:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void		fill_cell(t_env *e, int i, int j, t_vector final_color)
{
	int	a;
	int	b;

	a = i - 1;
	while (++a < i + e->increment && a < (int)F_WIDTH)
	{
		b = j - 1;
		while (++b < j + e->increment && b < (int)F_HEIGHT)
		{
			e->color_array[b][a].x += final_color.x;
			e->color_array[b][a].y += final_color.y;
			e->color_array[b][a].z += final_color.z;
		}
	}
}

t_ray			cam_ray(t_env *e, double i, double j, double ratio)
{
	t_vector	v;
	t_ray		ray;
	double		pitch;
	double		yaw;

	(e->increment == 1) ? i += randb() : 0;
	(e->increment == 1) ? j += randb() : 0;
	pitch = e->camera.dir.y;
	yaw = e->camera.dir.x;
	v.x = ((2.0 * ((i + 0.5) / F_WIDTH)) - 1.0) * ratio
			* (tan((FOV / (double)2.0) * M_PI / (double)180.0));
	v.y = (1.0 - (2.0 * ((j + 0.5) / F_HEIGHT)))
			* tan((FOV / (double)2.0) * M_PI / (double)180.0);
	ray.ori = e->camera.ori;
	ray.dir.x = -cos(pitch) * sin(yaw) + v.x * cos(yaw)
				+ v.y * sin(pitch) * sin(yaw);
	ray.dir.y = sin(pitch) + v.y * cos(pitch);
	ray.dir.z = cos(pitch) * cos(yaw) + v.x * sin(yaw)
				- v.y * sin(pitch) * cos(yaw);
	ray.dir = vector_normalize(ray.dir);
	return (ray);
}

static void		save_final_color(t_env *e, t_vector ret, int i, int j)
{
	t_vector final_color;

	final_color = adjust_color(ret);
	final_color.x = sqrt(final_color.x);
	final_color.y = sqrt(final_color.y);
	final_color.z = sqrt(final_color.z);
	final_color.x *= (double)255.0;
	final_color.y *= (double)255.0;
	final_color.z *= (double)255.0;
	fill_cell(e, i, j, final_color);
}

void			*compute_block(void *data)
{
	t_env		*e;
	int			i;
	int			j;
	t_ray		ray;

	e = (t_env *)data;
	i = e->i;
	while (i < (e->i + (int)((int)F_WIDTH / e->threads)))
	{
		j = 0;
		while (j < F_HEIGHT)
		{
			ray = cam_ray(e, i, j, F_WIDTH / F_HEIGHT);
			e->avoid = NULL;
			e->vpos = ray.dir.y;
			e->depth = 0;
			save_final_color(e, compute_objects(e, ray, -1), i, j);
			j += e->increment;
		}
		i += e->increment;
	}
	release_copy(&e);
	return (NULL);
}
