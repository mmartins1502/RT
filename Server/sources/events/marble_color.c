/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:13:41 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/10 18:37:21 by itonoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	marble_color_r(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	e->selected->color_backup = e->selected->color;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
		e->selected->marblecolor.x < 0.99)
		e->selected->marblecolor.x += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
		e->selected->marblecolor.x > 0.01)
		e->selected->marblecolor.x -= 0.005 * coef2;
	e->selected->marblecolor.x = e->selected->marblecolor.x < 0 ? 0 :
		e->selected->marblecolor.x;
	e->selected->marblecolor.x = e->selected->marblecolor.x > 1 ? 1 :
		e->selected->marblecolor.x;
}

void	marble_color_g(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	e->selected->color_backup = e->selected->color;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->marblecolor.y < 0.99)
		e->selected->marblecolor.y += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->marblecolor.y > 0.01)
		e->selected->marblecolor.y -= 0.005 * coef2;
	e->selected->marblecolor.y = e->selected->marblecolor.y < 0 ? 0 :
		e->selected->marblecolor.y;
	e->selected->marblecolor.y = e->selected->marblecolor.y > 1 ? 1 :
		e->selected->marblecolor.y;
}

void	marble_color_b(t_env *e, int mode)
{
	int coef;
	int coef2;

	coef = (mode == INCREASE_MAX) ? 10 : 1;
	coef2 = (mode == DECREASE_MAX) ? 10 : 1;
	if (!e->selected)
		return ;
	e->selected->color_backup = e->selected->color;
	if ((mode == INCREASE || mode == INCREASE_MAX) &&
			e->selected->marblecolor.z < 0.99)
		e->selected->marblecolor.z += 0.005 * coef;
	else if ((mode == DECREASE || mode == DECREASE_MAX) &&
			e->selected->marblecolor.z > 0.01)
		e->selected->marblecolor.z -= 0.005 * coef2;
	e->selected->marblecolor.z = e->selected->marblecolor.z < 0 ? 0 :
		e->selected->marblecolor.z;
	e->selected->marblecolor.z = e->selected->marblecolor.z > 1 ? 1 :
		e->selected->marblecolor.z;
}
