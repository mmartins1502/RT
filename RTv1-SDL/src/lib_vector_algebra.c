/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vector_algebra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:45:43 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	vector_scale(t_vector a, double scale)
{
	t_vector v;

	v.x = a.x * scale;
	v.y = a.y * scale;
	v.z = a.z * scale;
	return (v);
}

t_vector	vector_factor(t_vector a, double factor, t_vector b)
{
	t_vector v;

	v.x = a.x + (factor * b.x);
	v.y = a.y + (factor * b.y);
	v.z = a.z + (factor * b.z);
	return (v);
}

t_vector	vector_normalize(t_vector a)
{
	t_vector v;

	v = vector_scale(a, 1 / (vector_magnitude(a)));
	return (v);
}

double		vector_magnitude(t_vector v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

double		vector_dot(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}
