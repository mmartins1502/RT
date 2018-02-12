/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itonoli- <itonoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:30:16 by itonoli-          #+#    #+#             */
/*   Updated: 2017/12/10 12:04:17 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_clu.h"

t_obj	*new_tmp_obj(void)
{
	t_obj *new;

	new = (t_obj *)ft_memalloc(sizeof(t_obj));
	new->tsp_index = -1;
	new->texture_index = -1;
	new->next = NULL;
	return (new);
}

double	hit_square(t_env *e, t_obj *obj, t_ray ray)
{
	t_vector	v1;
	t_vector	v2;
	double		t;
	t_obj		*tmp;

	size_interpretor(obj, &v1, &v2);
	if ((t = hit_tri(e, obj, ray)) > -1)
		return (t);
	tmp = new_tmp_obj();
	tmp->len1 = obj->len1;
	tmp->len2 = obj->len2;
	tmp->ori = vector_add(vector_add(obj->ori, vector_scale(obj->dir,
					obj->len1)), vector_scale(obj->dir2, obj->len2));
	tmp->dir = vector_negative(obj->dir);
	tmp->dir2 = vector_negative(obj->dir2);
	if ((t = hit_tri(e, tmp, ray)) != -1)
	{
		obj->t = tmp->t;
		obj->cross = tmp->cross;
		obj->normal = tmp->normal;
	}
	free(tmp);
	tmp = NULL;
	return (t);
}
