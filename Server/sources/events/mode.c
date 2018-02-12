/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 08:16:46 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	set_live_edition_mode(t_env *e)
{
	e->live = 1;
	e->increment = 4;
	e->recursion = 2;
	e->reset = 1;
}

void	set_render_edition_mode(t_env *e)
{
	e->live = 0;
	e->increment = 1;
	e->recursion = 10;
	e->reset = 1;
}

void	switch_render_mode(t_env *e)
{
	if (!e->live)
	{
		e->increment = 4;
		e->recursion = 2;
	}
	else
	{
		e->increment = 1;
		e->recursion = 10;
	}
	e->live = (e->live & 1) ^ 1;
	e->reset = 1;
}
