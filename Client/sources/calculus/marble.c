/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 13:51:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static double	turb(t_env *e, t_vector cross)
{
	double		accum;
	t_vector	tmp;
	double		weight;
	int			i;

	accum = 0;
	tmp = cross;
	weight = 1.0;
	i = 0;
	while (i < 7)
	{
		accum += weight * noise(e, tmp);
		weight *= (double)0.5;
		tmp = vector_scale(tmp, 2);
		i++;
	}
	return (fabs(accum));
}

void			marble(t_env *e, t_obj *closest_obj)
{
	double ratio;

	ratio = turb(e, vector_scale(closest_obj->cross, 1.0)) * 16.0;
	closest_obj->color.x = closest_obj->marblecolor.x * ratio;
	closest_obj->color.y = closest_obj->marblecolor.y * ratio;
	closest_obj->color.z = closest_obj->marblecolor.z * ratio;
	closest_obj->color.x += closest_obj->color_backup.x * (1.0 - ratio);
	closest_obj->color.y += closest_obj->color_backup.y * (1.0 - ratio);
	closest_obj->color.z += closest_obj->color_backup.z * (1.0 - ratio);
	(closest_obj->color.x < 0.0) ? closest_obj->color.x = 0.0 : 0;
	(closest_obj->color.y < 0.0) ? closest_obj->color.y = 0.0 : 0;
	(closest_obj->color.z < 0.0) ? closest_obj->color.z = 0.0 : 0;
	(closest_obj->color.x > 1.0) ? closest_obj->color.x = 1.0 : 0;
	(closest_obj->color.y > 1.0) ? closest_obj->color.y = 1.0 : 0;
	(closest_obj->color.z > 1.0) ? closest_obj->color.z = 1.0 : 0;
}
