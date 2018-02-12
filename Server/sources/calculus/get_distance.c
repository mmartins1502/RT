/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 04:25:03 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 15:01:47 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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
