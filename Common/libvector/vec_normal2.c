/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normal2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas <tdelmas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 12:15:32 by tdelmas           #+#    #+#             */
/*   Updated: 2017/12/10 15:35:47 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

t_vector	vector_normalize(t_vector a)
{
	t_vector v;

	v = vector_scale(a, 1.0 / vector_magnitude(a));
	return (v);
}

t_vector	normal_triangle(t_obj *obj, t_vector v1, t_vector v2)
{
	t_vector v0v1;
	t_vector v0v2;

	v0v1 = vector_sub(v1, obj->ori);
	v0v2 = vector_sub(v2, obj->ori);
	return (vector_cross(v0v1, v0v2));
}
