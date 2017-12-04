/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 13:17:05 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vector_new(double x, double y, double z)
{
	t_vector v;

	v.x = x;
	v.y = y;
	v.z = z;
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

t_vector	vector_cross(t_vector a, t_vector b)
{
	t_vector v;

	v.x = (a.y * b.z) - (b.y * a.z);
	v.y = (a.z * b.x) - (b.z * a.x);
	v.z = (a.x * b.y) - (b.x * a.y);
	return (v);
}

t_vector	vector_mul(t_vector a, t_vector b)
{
	t_vector v;

	v.x = (a.x * b.x);
	v.y = (a.y * b.y);
	v.z = (a.z * b.z);
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

double		vector_magnitude(t_vector v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

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

t_vector	vector_normalize(t_vector a)
{
	t_vector v;

	v = vector_scale(a, 1 / (vector_magnitude(a)));
	return (v);
}

t_vector	normal_sphere(t_obj *closest_obj)
{
	t_vector n;

	n = vector_sub(closest_obj->cross, closest_obj->ori);
	n = vector_normalize(n);
	return (n);
}

t_vector	normal_cone(t_obj *closest_obj)
{
	t_vector	n;
	double		k;
	double		m;

	t_vector a = vector_sub(closest_obj->cross, closest_obj->ori);
	t_vector A;
	m = vector_dot(a, closest_obj->dir);
	A = vector_add(closest_obj->ori, vector_scale(closest_obj->dir, m));
	k = vector_magnitude(vector_sub(closest_obj->cross, A)) / m;
	t_vector b = vector_scale(closest_obj->dir, m * (1 + k * k));
	t_vector r = vector_sub(a, b);
	n = vector_normalize(r);
	return (n);
}

t_vector	normal_plane(t_obj *closest_obj, t_ray ray)
{
	double		dot;
	t_vector	n;

	dot = vector_dot(ray.dir, closest_obj->dir);
	if (dot > 0)
		n = vector_negative(closest_obj->dir);
	else
		n = closest_obj->dir;
	return (vector_normalize(n));
}

t_vector	normal_cyl(t_obj *closest_obj)
{
	t_vector n;

	t_vector a = vector_sub(closest_obj->cross, closest_obj->ori);
	t_vector b = vector_scale(closest_obj->dir, vector_dot(a, closest_obj->dir));
	t_vector r = vector_sub(a, b);
	n = vector_normalize(r);
	return (n);
}

