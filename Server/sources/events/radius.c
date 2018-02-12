/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:25:11 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 17:08:06 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_radius(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
		e->selected->radius++;
	else if (mode == DECREASE && e->selected->radius > 0.0)
		e->selected->radius--;
	else if (mode == INCREASE_MAX)
		e->selected->radius += 10;
	else if (mode == DECREASE_MAX && e->selected->radius > 10)
		e->selected->radius -= 10;
}

void	change_angle(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (mode == INCREASE)
		e->selected->radius += 0.1;
	else if (mode == DECREASE && e->selected->radius > 0.09)
		e->selected->radius -= 0.1;
	else if (mode == INCREASE_MAX)
		e->selected->radius += 0.2;
	else if (mode == DECREASE_MAX && e->selected->radius > 0.19)
		e->selected->radius -= 0.2;
}

void	change_radius_angle(t_env *e, int mode)
{
	if (!e->selected)
		return ;
	if (e->selected->type == OBJ_CONE)
		change_angle(e, mode);
	else
		change_radius(e, mode);
}
