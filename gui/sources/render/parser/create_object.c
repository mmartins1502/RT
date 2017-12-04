/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:37:45 by nsampre           #+#    #+#             */
/*   Updated: 2017/11/27 18:14:06 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	*new_obj(void)
{
	t_obj *new;

	new = (t_obj *)ft_memalloc(sizeof(t_obj));
	new->next = NULL;
	return (new);
}

void	obj_push_back(t_obj **list, t_obj *cur)
{
	if (!list)
		return ;
	while (*list)
		list = &(*list)->next;
	*list = cur;
}
