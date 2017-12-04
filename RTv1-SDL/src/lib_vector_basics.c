/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vector_basics.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 09:45:00 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 10:07:30 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vector	vector_new(double x, double y, double z)
{
	t_vector v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vector	vector_negative(t_vector a)
{
	t_vector v;

	v.x = -a.x;
	v.y = -a.y;
	v.z = -a.z;
	return (v);
}

t_vector	vector_add(t_vector a, t_vector b)
{
	t_vector v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vector	vector_sub(t_vector a, t_vector b)
{
	t_vector v;

	v.x = a.x - b.x;
	v.y = a.y - b.y;
	v.z = a.z - b.z;
	return (v);
}