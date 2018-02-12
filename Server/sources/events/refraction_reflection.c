/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction_reflection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 06:02:43 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/11 14:34:22 by tdelmas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	change_refraction(t_env *e, int sense)
{
	if (!e->selected)
		return ;
	if (sense == INCREASE && e->selected->refraction >= 1.00)
		e->selected->refraction += 0.1;
	else if (sense == INCREASE && e->selected->refraction == 0)
		e->selected->refraction += 1;
	else if (sense == DECREASE && e->selected->refraction > 1.09)
		e->selected->refraction -= 0.1;
	else if (sense == DECREASE && e->selected->refraction <= 1.09)
		e->selected->refraction = 0;
	else if (sense == DECREASE_MAX)
		e->selected->refraction = 0;
	else if (sense == INCREASE_MAX && e->selected->refraction >= 1.00)
		e->selected->refraction += 1;
}

void	change_reflection(t_env *e, int sense)
{
	(void)sense;
	if (!e->selected)
		return ;
	e->selected->reflection = (e->selected->reflection == 1) ? 0 : 1;
}
