/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:12:26 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	move_forward(t_env *e)
{
	e->camera.ori.x -= MOVE_SPEED * cos(PITCH) * sin(YAW);
	e->camera.ori.y += MOVE_SPEED * sin(PITCH);
	e->camera.ori.z += MOVE_SPEED * cos(PITCH) * cos(YAW);
}

void	move_backward(t_env *e)
{
	e->camera.ori.x += MOVE_SPEED * cos(PITCH) * sin(YAW);
	e->camera.ori.y -= MOVE_SPEED * sin(PITCH);
	e->camera.ori.z -= MOVE_SPEED * cos(PITCH) * cos(YAW);
}

void	move_left(t_env *e)
{
	e->camera.ori.x -= MOVE_SPEED * cos(YAW);
	e->camera.ori.z -= MOVE_SPEED * sin(YAW);
}

void	move_right(t_env *e)
{
	e->camera.ori.x += MOVE_SPEED * cos(YAW);
	e->camera.ori.z += MOVE_SPEED * sin(YAW);
}

void	move_up(t_env *e)
{
	e->camera.ori.y += MOVE_SPEED / (double)2.0;
}
