/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:36:30 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:08:28 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		put_color(t_env *e, int i, int j)
{
	SDL_SetRenderDrawColor(e->renderer, e->color.r, e->color.g, e->color.b, 255);
	SDL_RenderDrawPoint(e->renderer, i, j);
}

t_vector	pitch_yaw(t_vector v, double pch, double yaw)
{
	t_vector	dir;

	dir.x = -cos(pch) * sin(yaw) + v.x * cos(yaw) + v.y * sin(pch) * sin(yaw);
	dir.y = sin(pch) + v.y * cos(pch);
	dir.z = cos(pch) * cos(yaw) + v.x * sin(yaw) - v.y * sin(pch) * cos(yaw);
	dir = vector_normalize(dir);
	return (dir);
}

t_vector	virtual_screen(int i, int j)
{
	t_vector	v;
	double		ratio;

	ratio = F_WIDTH / F_HEIGHT;
	v.x = ((2 * ((i + 0.5) / F_WIDTH)) - 1) * ratio;
	v.x *= (tan((60 / 2) * M_PI / 180));
	v.y = (1 - (2 * ((j + 0.5) / F_HEIGHT))) * tan((60 / 2) * M_PI / 180);
	v.z = 1;
	return (v);
}

void		draw_screen(t_env *e)
{
	int			i;
	int			j;
	t_ray		ray;

	i = 0;
	while (i < F_WIDTH)
	{
		j = 0;
		while (j < F_HEIGHT)
		{
			ray.ori = e->camera.ori;
			ray.dir = virtual_screen(i, j);
			ray.dir = pitch_yaw(ray.dir, e->camera.dir.y, e->camera.dir.x);
			compute_objects(e, ray);
			put_color(e, i, j);
			j++;
		}
		i++;
	}
	SDL_RenderPresent(e->renderer);
}