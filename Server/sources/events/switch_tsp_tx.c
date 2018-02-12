/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_tsp_tx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsampre <nsampre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:41:52 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:23 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	switch_tsp_tx(t_env *e)
{
	if (!e->selected)
		return ;
	e->selected->tsp_index++;
	if (e->selected->tsp_index == e->tsp_tx_total)
	{
		e->selected->tsp_index = -1;
		e->selected->current_tsp = NULL;
	}
	else
		e->selected->current_tsp = e->s_tsp_tx[e->selected->tsp_index];
}
