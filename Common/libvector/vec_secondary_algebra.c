/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_secondary_algebra.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 07:05:15 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

t_vector	vector_cross(t_vector a, t_vector b)
{
	t_vector v;

	v.x = (a.y * b.z) - (b.y * a.z);
	v.y = (a.z * b.x) - (b.z * a.x);
	v.z = (a.x * b.y) - (b.x * a.y);
	return (v);
}

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
