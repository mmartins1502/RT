/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:25:50 by nsampre           #+#    #+#             */
/*   Updated: 2017/09/28 09:54:40 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_obj	*new_obj(void)
{
	t_obj *new;

	new = (t_obj *)ft_memalloc(sizeof(t_obj));
	bzero(new, sizeof(t_obj));
	new->next = NULL;
	return (new);
}

t_light	*new_light(void)
{
	t_light *new;

	new = (t_light *)ft_memalloc(sizeof(t_light));
	bzero(new, sizeof(t_light));
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

void	light_push_back(t_light **list, t_light *cur)
{
	if (!list)
		return ;
	while (*list)
		list = &(*list)->next;
	*list = cur;
}
