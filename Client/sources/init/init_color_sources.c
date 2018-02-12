/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color_sources.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartins <mmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 06:03:04 by nsampre           #+#    #+#             */
/*   Updated: 2017/12/09 08:45:22 by nsampre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	init_color_tx_sources(void)
{
	int i;

	g_mem.obj_tx_total = 0;
	i = 0;
	while (g_color_sources[i].file_address)
	{
		if (!(g_mem.s_obj_tx[i] = IMG_Load(g_color_sources[i].file_address)))
		{
			printf("FATAL : Failed to load color texture %s\n",
											g_color_sources[i].file_address);
			exit(EXIT_FAILURE);
		}
		i++;
		g_mem.obj_tx_total++;
	}
}
