/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:45:40 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 18:47:21 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_color_r(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->color.x < 0.99)
		e->selected->color.x += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->color.x > 0.01)
		e->selected->color.x -= 0.005 * coef2;
	e->selected->color.x = e->selected->color.x < 0 ? 0 : e->selected->color.x;
	e->selected->color.x = e->selected->color.x > 1 ? 1 : e->selected->color.x;
}

void	change_color_g(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->color.y < 0.99)
		e->selected->color.y += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->color.y > 0)
		e->selected->color.y -= 0.005 * coef2;
	e->selected->color.y = e->selected->color.y < 0 ? 0 : e->selected->color.y;
	e->selected->color.y = e->selected->color.y > 1 ? 1 : e->selected->color.y;
}

void	change_color_b(t_env *e, int mode)
{
	int coef;
	int coef2;

	if (!e->selected)
		return ;
	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if ((mode == INCREASE || mode == INCREASE_MAX) && e->selected->color.z < 1)
		e->selected->color.z += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->color.z > 0.01)
		e->selected->color.z -= 0.005 * coef2;
	e->selected->color.z = e->selected->color.z < 0 ? 0 : e->selected->color.z;
	e->selected->color.z = e->selected->color.z > 1 ? 1 : e->selected->color.z;
}
