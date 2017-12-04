/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:22:43 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/04 18:55:40 by mmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	marble_object(t_env *e)
{	static int	i = 0;
	if (!e->selected)
		return ;
	if (i == 0)
	{
		e->selected->marblesize = randb() / (double)1000.0;
		e->selected->marblecolor = (t_vector){1.0 * randb(), 1.0 * randb(), 1.0 * randb()};
		i = 1;
	}
	else
	{
		e->selected->marblesize = 0;
		e->selected->marblecolor = (t_vector){0, 0, 0};
		i = 0;
	}
	draw_screen(e);	
}

void	light_object(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->emit = e->selected->emit == 0 ? 1 : 0;
	e->selected->light = (e->selected->emit == 1) ? (t_vector){255, 255, 255} : (t_vector){0, 0, 0};
	draw_screen(e);
}

void	move_ojbect_up(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.y += MOVE_SPEED / (double)2.0;
	draw_screen(e);
}

void	move_ojbect_down(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.y -= MOVE_SPEED / (double)2.0;
	draw_screen(e);
}

void	move_ojbect_forward(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.x -= MOVE_SPEED * cos(PITCH) * sin(YAW);
	e->selected->ori.y += MOVE_SPEED * sin(PITCH);
	e->selected->ori.z += MOVE_SPEED * cos(PITCH) * cos(YAW);
	draw_screen(e);
}

void	move_ojbect_backward(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.x += MOVE_SPEED * cos(PITCH) * sin(YAW);
	e->selected->ori.y -= MOVE_SPEED * sin(PITCH);
	e->selected->ori.z -= MOVE_SPEED * cos(PITCH) * cos(YAW);
	draw_screen(e);
}

void	move_ojbect_left(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.x -= MOVE_SPEED * cos(YAW);
	e->selected->ori.z -= MOVE_SPEED * sin(YAW);
	draw_screen(e);
}

void	move_ojbect_right(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->ori.x += MOVE_SPEED * cos(YAW);
	e->selected->ori.z += MOVE_SPEED * sin(YAW);
	draw_screen(e);
}
