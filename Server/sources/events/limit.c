/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 04:21:39 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	increase_limit(t_env *e)
{
	if (!e->selected)
		return ;
	if (e->selected->type == OBJ_SQUARE || e->selected->type == OBJ_TRI)
	{
		e->selected->len1++;
		e->selected->len2++;
	}
	else if (e->selected->type == OBJ_TORUS)
	{
		if (e->selected->small_r < e->selected->radius)
			e->selected->small_r++;
	}
	else
		e->selected->height++;
}

void	decrease_limit(t_env *e)
{
	if (!e->selected ||
		(e->selected->height <= 0 && e->selected->type != OBJ_TORUS))
		return ;
	if (e->selected->type == OBJ_SQUARE || e->selected->type == OBJ_TRI)
	{
		e->selected->len1--;
		e->selected->len2--;
	}
	else if (e->selected->type == OBJ_TORUS)
	{
		if (e->selected->small_r > 0)
			e->selected->small_r--;
	}
	else
		e->selected->height--;
}
