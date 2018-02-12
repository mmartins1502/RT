/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   damier_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:31:38 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 18:39:34 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	switch_damier(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->damier = (e->selected->damier ^ 1) & 1;
}

void	dam_one_color_r(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->damier1.x < 0.99)
		e->selected->damier1.x += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->damier1.x > 0.01)
		e->selected->damier1.x -= 0.005 * coef2;
	e->selected->damier1.x = e->selected->damier1.x < 0 ? 0 :
		e->selected->damier1.x;
	e->selected->damier1.x = e->selected->damier1.x > 1 ? 1 :
		e->selected->damier1.x;
}

void	dam_one_color_g(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->damier1.y < 0.99)
		e->selected->damier1.y += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->damier1.y > 0.01)
		e->selected->damier1.y -= 0.005 * coef2;
	e->selected->damier1.y = e->selected->damier1.y < 0 ? 0 :
		e->selected->damier1.y;
	e->selected->damier1.y = e->selected->damier1.y > 1 ? 1 :
		e->selected->damier1.y;
}

void	dam_one_color_b(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->damier1.z < 0.99)
		e->selected->damier1.z += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->damier1.z > 0.01)
		e->selected->damier1.z -= 0.005 * coef2;
	e->selected->damier1.z = e->selected->damier1.z < 0 ? 0 :
		e->selected->damier1.z;
	e->selected->damier1.z = e->selected->damier1.z > 1 ? 1 :
		e->selected->damier1.z;
}
