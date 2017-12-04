/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vector_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:45:40 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:08:58 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double		vector_cos_angle(t_vector a, t_vector b)
{
	double	scalar_product;

	scalar_product = vector_dot(a, b);
	scalar_product /= (double)(sqrt(vector_dot(a, a)));
	scalar_product /= (double)(sqrt(vector_dot(b, b)));
	return (scalar_product);
}

t_vector	vector_normal(t_obj *closest_obj, t_ray ray)
{
	t_vector	n;

	if (closest_obj->type == OBJ_SPHERE)
		return (sphere_normal(closest_obj));
	else if (closest_obj->type == OBJ_PLANE)
		return (plane_normal(closest_obj, ray));
	else if (closest_obj->type == OBJ_CYL)
		return (cyl_normal(closest_obj));
	else if (closest_obj->type == OBJ_CONE)
		return (cone_normal(closest_obj));
	else
		quit("Unexpected object type. Aborting.");
	ft_bzero((void *)&n, sizeof(t_vector));
	return (n);
}
