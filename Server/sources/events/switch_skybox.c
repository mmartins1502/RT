/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_skybox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:41:49 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	switch_skybox(t_env *e)
{
	e->skybox_index++;
	if (e->skybox_index == e->skybox_total)
	{
		e->skybox_index = -1;
		e->current_skybox = NULL;
	}
	else
		e->current_skybox = e->s_skybox[e->skybox_index];
}
