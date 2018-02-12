/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:38:59 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_copy(t_env *e, t_env *copy, int i)
{
	t_obj	*obj;
	t_obj	*copy_obj;

	ft_memcpy((void *)copy, (void *)e, sizeof(t_env));
	obj = e->objects;
	copy->objects = NULL;
	copy->i = i * (int)((int)F_WIDTH / (int)e->threads);
	while (obj)
	{
		copy_obj = new_obj();
		ft_memcpy((void *)copy_obj, (void *)obj, sizeof(t_obj));
		copy_obj->next = NULL;
		obj_push_back(&copy->objects, copy_obj);
		obj = obj->next;
	}
}

void	release_copy(t_env **copy)
{
	t_obj	*obj;
	t_obj	*tmp;

	obj = (*copy)->objects;
	while (obj)
	{
		tmp = obj->next;
		free(obj);
		obj = tmp;
	}
	free(*copy);
	copy = NULL;
}
