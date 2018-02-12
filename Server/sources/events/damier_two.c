/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:30:19 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 18:40:15 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	dam_two_color_r(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->damier2.x < 0.99)
		e->selected->damier2.x += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->damier2.x > 0.01)
		e->selected->damier2.x -= 0.005 * coef2;
	e->selected->damier2.x = e->selected->damier2.x < 0 ? 0 :
		e->selected->damier2.x;
	e->selected->damier2.x = e->selected->damier2.x > 1 ? 1 :
		e->selected->damier2.x;
}

void	dam_two_color_g(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->damier2.y < 0.99)
		e->selected->damier2.y += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->damier2.y > 0.01)
		e->selected->damier2.y -= 0.005 * coef2;
	e->selected->damier2.y = e->selected->damier2.y < 0 ? 0 :
		e->selected->damier2.y;
	e->selected->damier2.y = e->selected->damier2.y > 1 ? 1 :
		e->selected->damier2.y;
}

void	dam_two_color_b(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->damier2.z < 0.99)
		e->selected->damier2.z += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->damier2.z > 0.01)
		e->selected->damier2.z -= 0.005 * coef2;
	e->selected->damier2.z = e->selected->damier2.z < 0 ? 0 :
		e->selected->damier2.z;
	e->selected->damier2.z = e->selected->damier2.z > 1 ? 1 :
		e->selected->damier2.z;
}
