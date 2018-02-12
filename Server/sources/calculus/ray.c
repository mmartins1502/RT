/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 04:24:05 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 11:52:18 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_ray	cam_ray(t_env *e, double i, double j, double ratio)
{
	t_vector	v;
	t_ray		ray;
	double		pitch;
	double		yaw;

	pitch = e->camera.dir.y;
	yaw = e->camera.dir.x;
	v.x = ((2 * ((i + 0.5) / F_WIDTH)) - 1) * ratio
	* (tan((FOV / 2) * M_PI / 180));
	v.y = ((1 - (2 * ((j + 0.5) / F_HEIGHT)))
		* tan((FOV / 2) * M_PI / 180));
	ray.ori = e->camera.ori;
	ray.dir.x = -cos(pitch) * sin(yaw) + v.x * cos(yaw)
		+ v.y * sin(pitch) * sin(yaw);
	ray.dir.y = sin(pitch) + v.y * cos(pitch);
	ray.dir.z = cos(pitch) * cos(yaw) + v.x * sin(yaw)
		- v.y * sin(pitch) * cos(yaw);
	return (ray);
}
