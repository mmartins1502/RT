/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_geometry.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 07:04:35 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

double		vector_dot(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double		vector_cos_angle(t_vector a, t_vector b)
{
	double	scalar_product;

	scalar_product = vector_dot(a, b);
	scalar_product /= (double)(sqrt(vector_dot(a, a)));
	scalar_product /= (double)(sqrt(vector_dot(b, b)));
	return (scalar_product);
}

double		vector_angle(t_vector a, t_vector b)
{
	return (acos(vector_cos_angle(a, b)));
}

double		vector_magnitude(t_vector v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}
