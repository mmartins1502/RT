/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:39:28 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:05:25 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	compute_light(t_env *e, t_obj *closest_obj, t_light *light, t_ray ray)
{
	t_vector	n;
	t_vector	l;
	double		sca;

	n = vector_normal(closest_obj, ray);
	l = vector_normalize(ray.dir);
	sca = vector_cos_angle(n, l);
	(sca < 0.0) ? (sca = 0.0) : 0;
	diffuse_color(e, closest_obj->color, light->color, sca * 0.9);
	if (closest_obj->type != OBJ_PLANE)
		specular_color(e, light->color, pow(sca, 41));
}

int		check_collision(t_env *e, t_obj *closest_obj, t_light *lgt, t_ray ray)
{
	double	len;
	int		collision;
	t_obj	*obj;

	len = vector_magnitude(ray.dir);
	obj = e->objects;
	collision = 0;
	while (obj && !collision)
	{
		if (obj != closest_obj)
		{
			get_distance(obj, ray);
			if (obj->cross_distance > 0 && obj->cross_distance < len)
			{
				diffuse_color(e, closest_obj->color, lgt->color, 0.1);
				collision = 1;
			}
		}
		obj = obj->next;
	}
	return (collision);
}

void	compute_closest_obj(t_env *e, t_obj *closest_obj)
{
	t_ray	ray;
	t_obj	closest_backup;
	t_light	*light;

	ft_bzero((void *)&e->color, sizeof(t_color));
	ft_memcpy((void *)&closest_backup, (void *)closest_obj, sizeof(t_obj));
	light = e->lights;
	while (light)
	{
		ray.ori = closest_obj->cross;
		ray.dir = vector_sub(light->ori, ray.ori);
		if (!check_collision(e, closest_obj, light, ray))
			compute_light(e, &closest_backup, light, ray);
		light = light->next;
	}
}
